#include "Ref2Physics.h"

USING_NS_CC;

PieceOfShape* PieceOfShape::create()
{
	PieceOfShape* SitemStringData = new (std::nothrow) PieceOfShape();
	if (SitemStringData)
	{
		return SitemStringData;
	}
	CC_SAFE_DELETE(SitemStringData);
	return nullptr;
}

PhysicsShape* PieceOfShape::createShape()
{
	if (_type == "Polygon")
	{
		return createPolygon();
	}
	else if (_type == "Rect")
	{
		return createRect();
	}
	else return createCircle();
}

PhysicsShapePolygon* PieceOfShape::createPolygon()
{
	PhysicsMaterial m_temp;
	m_temp.density = _density;
	m_temp.friction = _friction;
	m_temp.restitution = _restitution;

	Vec2 v_temp[20];
	for (int i = 0; i < _vetrexs.size(); ++i)
	{
		v_temp[i] = _vetrexs.at(i);
	}
	auto s_temp = PhysicsShapePolygon::create(v_temp, _numberOfPolygon, m_temp,_Offset);
	s_temp->setCategoryBitmask(_categoryMask);
	s_temp->setCollisionBitmask(_collisionMask);
	s_temp->setContactTestBitmask(_contactTestMask);
	s_temp->setTag(_pTag);
	
	return s_temp;
}

PhysicsShapeCircle* PieceOfShape::createCircle()
{
	PhysicsMaterial m_temp;
	m_temp.density = _density;
	m_temp.friction = _friction;
	m_temp.restitution = _restitution;

	auto s_temp = PhysicsShapeCircle::create(_R, m_temp, _Offset);
	s_temp->setCategoryBitmask(_categoryMask);
	s_temp->setCollisionBitmask(_collisionMask);
	s_temp->setContactTestBitmask(_contactTestMask);
	s_temp->setTag(_pTag);
	return s_temp;
}

PhysicsShapeBox* PieceOfShape::createRect()
{
	PhysicsMaterial m_temp;
	m_temp.density = _density;
	m_temp.friction = _friction;
	m_temp.restitution = _restitution;

	auto s_temp = PhysicsShapeBox::create(Size(_vetrexs.at(0).x, _vetrexs.at(0).y), m_temp, _Offset);
	s_temp->setCategoryBitmask(_categoryMask);
	s_temp->setCollisionBitmask(_collisionMask);
	s_temp->setContactTestBitmask(_contactTestMask);
	s_temp->setTag(_pTag);
	return s_temp;
}