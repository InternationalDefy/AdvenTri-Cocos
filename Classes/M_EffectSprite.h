#ifndef __M_EFFECTSPRITE__
#define __M_EFFECTSPRITE__

#include "cocos2d.h"

class M_Effect;

using namespace cocos2d;

class M_EffectSprite :public Sprite
{
public:
	static M_EffectSprite *create(const std::string& filename);
	void setEffect(M_Effect* effect);
	void addEffect(M_Effect *effect, ssize_t order);
	void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
protected:
	M_EffectSprite();
	~M_EffectSprite();

	std::vector<std::tuple<ssize_t, M_Effect*, QuadCommand>> _effects;
	M_Effect* _defaultEffect;
};

#endif