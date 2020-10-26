#ifndef __PIECE_OF_SHAPE_H__
#define __PIECE_OF_SHAPE_H__

#include "cocos2d.h"

USING_NS_CC;

class PieceOfShape : public Ref
{
private:
	int _pTag;
	float _density;
	float _friction;
	float _restitution;
	float _R;
	int _categoryMask;
	int _collisionMask;
	int _contactTestMask;
	std::string _type;
	std::vector < Vec2 > _vetrexs;
	int _numberOfPolygon;

	Vec2 _Offset;

	PhysicsShapePolygon* createPolygon();
	PhysicsShapeBox* createRect();
	PhysicsShapeCircle* createCircle();


public:
	static PieceOfShape* create();
	/*
	利用该实例持有的数据创造一个PhysiscShape并返回
	*/
	PhysicsShape* createShape();

	//getters&setters
	void setType(const std::string& x){ _type = x; }
	std::string getType(){ return _type; }
	void setPtag(int x){ _pTag = x; }
	int getPtag(){ return _pTag; }
	float getDensity(){ return _density; }
	void setDensity(float x){ _density = x; }
	float getFriction(){ return _friction; }
	void setFriction(float x){ _friction = x; }
	float getRestitution(){ return _restitution; }
	void setRestitution(float x){ _restitution = x; }
	int getNumberOfEdges(){ return _numberOfPolygon; }
	void setNumberOfEdges(int x){ _numberOfPolygon = x; }
	int getCategoryMask(){ return _categoryMask; }
	void setCategoryMask(int x){ _categoryMask = x; }
	int getCollisionMask(){ return _collisionMask; }
	void setCollisionMask(int x){ _collisionMask = x; }
	int getContactTestMask(){ return _contactTestMask; }
	void setContactTestMask(int x){ _contactTestMask = x; }
	std::vector<Vec2>* getVetrexs(){ return &_vetrexs; }
	float getR(){ return _R; }
	void setR(float x){ _R = x; }

	void setOffSet(Vec2 x){ _Offset = x; }
};

#endif