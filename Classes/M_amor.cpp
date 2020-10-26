#include "Ref2Ebreed.h"
using namespace cocos2d;

void M_Amor::initWithData(SD_Amor* a_breed)
{
	_type = a_breed->_type;
	_defence = a_breed->_defence; 
	_hp = a_breed->_hp;
	_animateRunning = FALSE;
	_animate = NULL;
}

M_Amor* M_Amor::create(SD_Amor* a_breed)
{
	M_Amor* amor = new (std::nothrow)M_Amor();
	if (amor)
	{
		amor->initWithData(a_breed);
		amor->autorelease();
		return amor;
	}
	CC_SAFE_DELETE(amor);
	return nullptr;
}
void M_Amor::addToEnemy(M_Enemy* enemy)
{
	_owner = enemy;
	//以下一句测试使用，要改！
	setPosition(enemy->getPosition());
	
	enemy->addAmor(this);
	return;
}

int M_Amor::handleDamageNum(M_Amor* amor, AdvenTriEnum::DamageType T, int D)
{
	if (amor->_type == AdvenTriEnum::A_TYPE_NONE)
	{
		return D;
	}
	int iRet = D - amor->_defence;
	int	pRet = 0;
	if (iRet < 0) iRet = 0;
	switch (amor->_type)
	{
	case AdvenTriEnum::A_TYPE_BASE:
		break;
	case AdvenTriEnum::A_TYPE_MAGIC:
		pRet = handleDamageMagic(T);
		break;
	case AdvenTriEnum::A_TYPE_METAL:
		pRet = handleDamageMetal(T);
		break;
	case AdvenTriEnum::A_TYPE_WOOD:
		pRet = handleDamageWood(T);
		break;
	default:
		break;
	}
	iRet += pRet;
	if (iRet < 0) return 0;
	return iRet;
}
int M_Amor::handleDamageMagic(AdvenTriEnum::DamageType T)
{
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BLADE);
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BLED);
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BLUNT);
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_STAB);

	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_DARK);
	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_CURSE);
	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_LIGHT);
	AMOR_MIUS2DAMAGE(AdvenTriEnum::DamageType::D_TYPE_MAGIC);
	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_SHOCK);
}
int M_Amor::handleDamageMetal(AdvenTriEnum::DamageType T)
{
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_FROST);
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_ICY);
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_LIGHT);
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_MAGIC);
	AMOR_PLUS2DAMAGE(AdvenTriEnum::DamageType::D_TYPE_SHOCK);

	AMOR_MIUS2DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BLADE);
	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BLED);
	AMOR_MIUS2DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BLUNT);
	AMOR_MIUS2DAMAGE(AdvenTriEnum::DamageType::D_TYPE_STAB);
}
int M_Amor::handleDamageWood(AdvenTriEnum::DamageType T)
{
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_FIRE);
	AMOR_PLUS2DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BURN);
	AMOR_PLUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_BLUNT);
	
	AMOR_MIUS2DAMAGE(AdvenTriEnum::DamageType::D_TYPE_SHOCK);
	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_LIGHT);
	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_FROST);
	AMOR_MIUS_DAMAGE(AdvenTriEnum::DamageType::D_TYPE_ICY);
}

float M_Amor::handleDebuffDuration(M_Amor* amor, AdvenTriEnum::DamageType T, float F)
{
	if (amor->_type == AdvenTriEnum::A_TYPE_NONE)
	{
		return F;
	}
	float iRet = F - amor->_defence;
	float pRet = 0.0f;
	if (iRet < 0.0f) iRet = 0.0f;
	switch (amor->_type)
	{
	case AdvenTriEnum::A_TYPE_BASE:
		break;
	case AdvenTriEnum::A_TYPE_MAGIC:
		pRet = handleDurationMagic(T);
		break;
	case AdvenTriEnum::A_TYPE_METAL:
		pRet = handleDurationMetal(T);
		break;
	case AdvenTriEnum::A_TYPE_WOOD:
		pRet = handleDurationWood(T);
		break;
	default:
		break;
	}
	iRet += pRet;
	if (iRet < 0.0f) return 0.0f;
	return iRet;
}
float M_Amor::handleDurationMagic(AdvenTriEnum::DamageType T)
{
	AMOR_PLUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_BLED);
	AMOR_PLUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_POISONED);

	AMOR_MIUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_CURSE);
	AMOR_MIUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_SHOCK);
	AMOR_MIUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_ICY);
	AMOR_MIUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_BURN);
}
float M_Amor::handleDurationMetal(AdvenTriEnum::DamageType T)
{
	AMOR_PLUS2DURATION(AdvenTriEnum::DamageType::D_TYPE_SHOCK);
	AMOR_PLUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_ICY);

	AMOR_MIUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_BLED);
}
float M_Amor::handleDurationWood(AdvenTriEnum::DamageType T)
{
	AMOR_PLUS2DURATION(AdvenTriEnum::DamageType::D_TYPE_BURN);
	AMOR_PLUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_BLED);

	AMOR_MIUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_ICY);
	AMOR_MIUS_DURATION(AdvenTriEnum::DamageType::D_TYPE_SHOCK);
}
