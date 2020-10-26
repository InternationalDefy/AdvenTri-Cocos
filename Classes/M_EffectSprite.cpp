#include "Ref2Effect.h"

using namespace cocos2d;

static int tuple_sort(const std::tuple<ssize_t, M_Effect*, QuadCommand> &tuple1, const std::tuple<ssize_t, M_Effect*, QuadCommand> &tuple2)
{
	return std::get<0>(tuple1) < std::get<0>(tuple2);
}
M_EffectSprite* M_EffectSprite::create(const std::string& name)
{
	auto ret = new (std::nothrow) M_EffectSprite;
	if (ret && ret->initWithFile(name)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_RELEASE(ret);
	return nullptr;

}
void M_EffectSprite::setEffect(M_Effect* effect)
{
	if (_defaultEffect != effect) {
		effect->setTarget(this);

		CC_SAFE_RELEASE(_defaultEffect);
		_defaultEffect = effect;
		CC_SAFE_RETAIN(_defaultEffect);

		setGLProgramState(_defaultEffect->getGLProgramState());
	}
}
void M_EffectSprite::addEffect(M_Effect *effect, ssize_t order) {
	effect->retain();
	effect->setTarget(this);

	_effects.push_back(std::make_tuple(order, effect, QuadCommand()));

	std::sort(std::begin(_effects), std::end(_effects), tuple_sort);
}
void M_EffectSprite::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
#if CC_USE_CULLING
	// Don't do calculate the culling if the transform was not updated
	_insideBounds = (flags & FLAGS_TRANSFORM_DIRTY) ? renderer->checkVisibility(transform, _contentSize) : _insideBounds;

	if (_insideBounds)
#endif
	{
		// negative effects: order < 0
		int idx = 0;
		for (auto &effect : _effects) {

			if (std::get<0>(effect) >= 0)
				break;
			QuadCommand &q = std::get<2>(effect);
			q.init(_globalZOrder, _texture->getName(), std::get<1>(effect)->getGLProgramState(), _blendFunc, &_quad, 1, transform, flags);
			renderer->addCommand(&q);
			idx++;

		}

		// normal effect: order == 0
		_trianglesCommand.init(_globalZOrder, _texture->getName(), getGLProgramState(), _blendFunc, _polyInfo.triangles, transform, flags);
		renderer->addCommand(&_trianglesCommand);

		// postive effects: oder >= 0
		for (auto it = std::begin(_effects) + idx; it != std::end(_effects); ++it) {
			QuadCommand &q = std::get<2>(*it);
			q.init(_globalZOrder, _texture->getName(), std::get<1>(*it)->getGLProgramState(), _blendFunc, &_quad, 1, transform, flags);
			renderer->addCommand(&q);
			idx++;
		}
	}
}
M_EffectSprite::M_EffectSprite() : _defaultEffect(nullptr)
{
	_effects.reserve(2);
}
M_EffectSprite::~M_EffectSprite()
{
	for (auto &tuple : _effects)
	{
		std::get<1>(tuple)->release();
	}
	CC_SAFE_RELEASE(_defaultEffect);
}
