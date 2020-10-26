#include "Ref2Entity.h"

using namespace cocos2d;

void M_Shadow::update(float)
{
	if (!_entity)
		return;
	//setRotation(_entity->getRotation());
	//setPositionZ(-_depth);

	return;
}

M_Shadow* M_Shadow::createWithTexture(Texture2D* texture)
{
	M_Shadow* sha = new (std::nothrow) M_Shadow();
	if (sha && sha->initWithTexture(texture))
	{
		sha->autorelease();
		sha->init();
		return sha;
	}
}
bool M_Shadow::init()
{
	_height = 0.0f;
	_depth = 0.0f;
	_entity = NULL;
	Size cont = getContentSize();
	setEffect(ME_Blur::create());
	return true;
}
void M_Shadow::setEntity(Entity* entity)
{
	_entity = entity;
	return;
}