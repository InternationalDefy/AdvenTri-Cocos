#include "Ref2ItemEntity.h"
#include "Ref2Entity.h"
#include "Ref2Player.h"
#include "Ref2Enemy.h"

void M_ItemEntity::initEntity()
{
	_flyingEndCallfunc = NULL;
	_timeExist = 0.0f;
	_flyController = NULL;
	_dropController = NULL;
	_throwAnimate = NULL;
	return;
}
void M_ItemEntity::flyEndOnEnd()
{
	this->removeFromParent();
}
void M_ItemEntity::setFlyingEndFunc(FiniteTimeAction* func)
{
	if (_flyingEndCallfunc)
	{
		log("Have Got A Func!");
		return;
	}
	_flyingEndCallfunc = Sequence::create(func,
		CallFunc::create(std::bind(&M_ItemEntity::flyEndOnEnd, this)), NULL);
	return;
}
void M_ItemEntity::flyEnd()
{
	if (_flyingEndCallfunc)
	{
		runAction(_flyingEndCallfunc);
		return;
	}
	log(	"HavneT A FlyEndFunc!");
	return;
}
void M_ItemEntity::dropByEnemy(Vec2 pos)
{
	//setPosition
	//set&&activeController
}
void M_ItemEntity::dropByPlayer(M_Player* player)
{
	//runAnimation
	//setPosition
	//set&&activeController
}
void M_ItemEntity::update(float dt)
{
	_timeExist -= dt;
	if (_timeExist < 0.0f)
	{
		flyEnd();
		return;
	}
}
