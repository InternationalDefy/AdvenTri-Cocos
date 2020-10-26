#include "Ref2Npc.h"

using namespace cocos2d;

M_Npc* M_Npc::create(const std::string& sdName)
{
	return M_Npc::create(DB_Npc::getInstance()->getNpcBreed(sdName));
}
M_Npc* M_Npc::create(SD_Npc* sd)
{
	M_Npc *pRet = new (std::nothrow) M_Npc();
	if (pRet && pRet->initWithFile(sd->getTextureName()))
	{
		M_Npc::init(pRet,sd);
		pRet->initEntity();
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

void M_Npc::init(M_Npc* npc,SD_Npc* sd)
{
	//if (sd->getAnimationPackName()!="")		npc->_animationPack = DB_AnimationPack::getInstance()->getAnimationPack(sd->getAnimationPackName());
	if (sd->getLanguagePackName()!="")
		npc->_laEmojiPack = 	Sys_LaEmoji::getInstance()->getLaEmojiPack(sd->getLanguagePackName());
	if (sd->getListenerSetName() != "")
		Sys_Event::getInstance()->addListenerSetTo(npc, sd->getListenerSetName());
	if (sd->getControllerName() != "")
		npc->setController(Sys_Ctrl::getInstance()->getControllerWithName(sd->getControllerName()));
	if (sd->getPhysicsBodyName() != "")
		npc->setPhysicsBody(DB_Physics::getInstance()->getBody(sd->getPhysicsBodyName()));

	npc->_nbreed = sd;
	npc->_currentLaEmoji = NULL;
	npc->_currentLaEmojiName = "";
	return;
}

void M_Npc::speakKey(const std::string& key, Vec2 pos)
{
	speak(_laEmojiPack->getLaEmoji(key), pos);
	return;
}
void M_Npc::speakLaEmoji(const std::string& name, Vec2 pos)
{
	if (_currentLaEmojiName == name)
	{
		return;
	}
	_currentLaEmojiName = name;
	speak(Sys_LaEmoji::getInstance()->getLaEmoji(name), pos);
	return;
}
void M_Npc::speak(M_LaEmoji* laEmoji, Vec2 pos)
{
	if (_currentLaEmoji)
	{
		_currentLaEmoji->removeFromParent();
	}
	laEmoji->setPosition(pos);
	_currentLaEmoji = laEmoji;
	addChild(laEmoji);
}

void M_Npc::onHurt(AdvenTriEnum::DamageType type, int dam)
{
	if (!_nbreed->isVulnerable(type))
	{
		return;
	}
	if (!dam)
	{
		return;
	}	
	doHurt(type,dam);
}
void M_Npc::doHurt(AdvenTriEnum::DamageType type,int dam)
{
	//animation
	//kill
	//sound
	return;
}

void M_Npc::update(float dt)
{
	auto k = _children.size();
	for (auto i = 0; i < k; ++i)
	{
		if (_children.at(i))
			_children.at(i)->update(dt);
	}
	return;
}