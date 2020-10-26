#ifndef __P_ITEM_STRING_DATA_H__
#define __P_ITEM_STRING_DATA_H__

#include "cocos2d.h"

USING_NS_CC;

class PhysicsStringData : public Ref
{
private:
	std::vector<float> _sideX;
	std::vector<float> _sideY;
	std::vector<std::string> _shapesName;
	bool _dynamic;
	int _size;
	float l_linearVelocity;
	float l_angularVelocity;
	float d_linear;
	float d_angular;

public:
	static PhysicsStringData* create();
	PhysicsBody* createBody();
	std::vector<float>* getSideX(){ return &_sideX; }
	std::vector<float>* getSideY(){ return &_sideY; }
	std::vector<std::string>* getShapes(){ return &_shapesName; }
	void pushShape(const std::string& x){ _shapesName.push_back(x); }
	void pushSideX(float x){ _sideX.push_back(x); }
	void pushSideY(float x){ _sideY.push_back(x); }
	int getSize(){ return _size; }
	void setSize(int x){ _size = x; }
	bool isBodyDynamic(){ return _dynamic; }
	void setBodyDynamic(bool x){ _dynamic = x; }
	void setLimitedVelocity(float x){ l_linearVelocity = x; }
	void setLimitedAngularV(float x){ l_angularVelocity = x; }
	void setDampingLinear(float x){ d_linear = x; }
	void setDampingAngular(float x){ d_angular = x; }
};

#endif