#ifndef __M_SHADOW__
#define __M_SHADOW__

#include "cocos2d.h"

#include "M_EffectSprite.h"

using namespace cocos2d;

class Entity;

class M_Shadow :public M_EffectSprite
{
//��������&&getters&&setters
private:
	float _depth;
	float _height;
public:
	void setHeight(float x)
	{
		_height = x;
	}
	float getHeight()
	{
		return _height;
	}
	void setDepth(float x)
	{
		_depth = x;
	}
	float getDepth()
	{
		return _depth;
	}
//�̳д�������
public:
	static M_Shadow* createWithTexture(Texture2D* texture);
	bool init();
//׷��ʵ���õ�update����
private:
	Entity* _entity;
public:
	void setEntity(Entity* entity);
	void update(float);
};

#endif