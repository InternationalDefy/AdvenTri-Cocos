#include "Ref2EventPhysics.h"
#include "Ref_Animation.h"
#include "Ref_Entity.h"

using namespace cocos2d;

void EPP_PlayerBodyOnEnemy::PhysicsCallback(PhysicsContact& contact)
{
	M_Player* p = NULL;
	if (contact.getShapeA()->getTag() == 2)
	{
		p = dynamic_cast<M_Player*> (contact.getShapeB()->getBody()->getNode());
	}
	else
	{
		p = dynamic_cast<M_Player*> (contact.getShapeA()->getBody()->getNode());
	}
	AdvenTriEnum::DamageType dam = AdvenTriEnum::DamageType(10 + int(std::floorf(6 * CCRANDOM_0_1())));
	/*
	auto i = DB_AnimationPack::getInstance()->getAnimationPack("HitAnimation");
	auto k = i->getAnimation(AdvenTriEnum::changeDamageTypeToString(dam));
	
	auto e = Sprite::create();
	e->setPosition(contact.getContactData()->points[0]);
	e->setScale(2.0f);
	dynamic_cast<Layer*> (p->getParent())->addChild(e, 10);
	e->runAction(Sequence::createWithTwoActions(k,CallFunc::create(std::bind(&Sprite::removeFromParent,e))));
	*/
	p->setHurtType(dam);
	p->setHurtDamage(1);
	p->setDebuffLimit(2.0f);
	p->handleAction(AdvenTriEnum::PlayerAction::P_ACTION_HURT);
	//p->getPhysicsBody()->applyImpulse(-10.0f * p->getPhysicsBody()->getVelocity());
	return;
}
