#include "Ref2Physics.h"

PhysicsStringData* PhysicsStringData::create()
{

	PhysicsStringData* PitemStringData = new (std::nothrow) PhysicsStringData();
	if (PitemStringData)
	{
		PitemStringData->autorelease();
		return PitemStringData;
	}
	CC_SAFE_DELETE(PitemStringData);
	return nullptr;
}
PhysicsBody* PhysicsStringData::createBody()
{
	auto b_temp = PhysicsBody::create();
	for (int i = 0; i < _shapesName.size(); ++i)
	{
		auto sh = DB_PhyShape::getInstance()->getShape(_shapesName.at(i), Vec2(_sideX.at(i), _sideY.at(i)));
		b_temp->addShape(sh);
	}
	b_temp->setDynamic(_dynamic);
	b_temp->setAngularDamping(d_angular);
	b_temp->setLinearDamping(d_linear);
	b_temp->setVelocityLimit(l_linearVelocity);
	b_temp->setAngularVelocityLimit(l_angularVelocity);
	return b_temp;
}