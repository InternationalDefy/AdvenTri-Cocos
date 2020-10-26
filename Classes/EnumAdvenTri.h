#ifndef __ENUMOFADVENTRI__
#define __ENUMOFADVENTRI__

class AdvenTriEnum
{
public:
	enum AmorType
	{
		A_TYPE_BASE,
		A_TYPE_WOOD,
		A_TYPE_MAGIC,
		A_TYPE_METAL,
		A_TYPE_NONE,
	};
	static AmorType changeStringToAmorType(const std::string& name)
	{
		if (name == "Base," || name == "BASE," || name == "base,"
			|| name == "Base" || name == "BASE" || name == "base")
		{
			return A_TYPE_BASE;
		}
		if (name == "Wood," || name == "WOOD," || name == "wood,"
			|| name == "Wood" || name == "WOOD" || name == "wood")
		{
			return A_TYPE_WOOD;
		}
		if (name == "Magic," || name == "MAGIC," || name == "magic,"
			|| name == "Magic" || name == "MAGIC" || name == "magic")
		{
			return A_TYPE_MAGIC;
		}
		if (name == "Metal," || name == "METAL," || name == "metal,"
			|| name == "Metal" || name == "METAL" || name == "metal")
		{
			return A_TYPE_METAL;
		}
		CCLOG("UnDefined Type!");
	}
	enum EnemyAction
	{
		E_ACTION_ATTACK,
		E_ACTION_SKILL1,
		E_ACTION_SKILL2,
		E_ACTION_SKILL3,
		E_ACTION_SKILL4,
		E_ACTION_PARRY,
		E_ACTION_DASH,
		E_ACTION_HURT,
	};
	enum EnemyState
	{
		E_STATE_STANDRED,
		E_STATE_DASH,
		E_STATE_USE,
		E_STATE_ACTION,
		E_STATE_GATHER,
	};
	enum PlayerAction
	{
		P_ACTION_DASH,
		P_ACTION_SKILL1,
		P_ACTION_SKILL2,
		P_ACTION_OPERATE,
		P_ACITON_USEITEM,
		P_ACTION_CHANGEITEM,
		P_ACTION_DROPITEM,
		P_ACTION_ATTACK,
		P_ACTION_PARRY,
		P_ACTION_BLINK,
		P_ACTION_HURT,
	};
	enum PlayerStateType
	{
		P_STATE_STANDRED,
		P_STATE_DASH,
		P_STATE_USE,
		P_STATE_ACTION,
		P_STATE_GATHER,
		P_STATE_ATTACK,
	};
	/*
	common:no type
	blade->poison: only influences on effect
	burn->curse: set on debuff
	*/
	enum DamageType
	{
		D_TYPE_COMMON,
		D_TYPE_BLADE,
		D_TYPE_STAB,
		D_TYPE_BLUNT,
		D_TYPE_FIRE,
		D_TYPE_FROST,
		D_TYPE_LIGHT,
		D_TYPE_DARK,
		D_TYPE_MAGIC,
		D_TYPE_POISON,
		D_TYPE_BURN,
		D_TYPE_ICY,
		D_TYPE_POISONED,
		D_TYPE_BLED,
		D_TYPE_SHOCK,
		D_TYPE_CURSE,
	};
	static DamageType changeStringToDamageType(const std::string& name)
	{
		if (name == "Poison," || name == "POISON," || name == "poison,"
			|| name == "Poison" || name == "POISON" || name == "poison")
		{
			return D_TYPE_POISON;
		}
		if (name == "Common," || name == "COMMON," || name == "common,"
			|| name == "Common" || name == "COMMON" || name == "common")
		{
			return D_TYPE_COMMON;
		}
		if (name == "Blade," || name == "blade," || name == "BLADE,"
			|| name == "Blade" || name == "blade" || name == "BLADE")
		{
			return D_TYPE_BLADE;
		}
		if (name == "Stab," || name == "STAB," || name == "stab,"
			|| name == "Common" || name == "COMMON" || name == "common")
		{
			return D_TYPE_STAB;
		}
		if (name == "Blunt," || name == "BLUNT," || name == "blunt,"
			|| name == "Blunt" || name == "BLUNT" || name == "blunt")
		{
			return D_TYPE_BLUNT;
		}
		if (name == "Fire," || name == "FIRE," || name == "fire,"
			|| name == "Fire" || name == "FIRE" || name == "fire")
		{
			return D_TYPE_FIRE;
		}
		if (name == "Frost," || name == "FROST," || name == "frost,"
			|| name == "Frost" || name == "FROST" || name == "frost")
		{
			return D_TYPE_FROST;
		}
		if (name == "Light," || name == "LIGHT," || name == "light,"
			|| name == "Light" || name == "LIGHT" || name == "light")
		{
			return D_TYPE_LIGHT;
		}
		if (name == "Dark," || name == "DARK," || name == "dark,"
			|| name == "Dark" || name == "DARK" || name == "dark")
		{
			return D_TYPE_DARK;
		}
		if (name == "Magic," || name == "MAGIC," || name == "magic,"
			|| name == "Magic" || name == "MAGIC" || name == "magic")
		{
			return D_TYPE_MAGIC;
		}
		if (name == "Burn," || name == "BURN," || name == "burn,"
			|| name == "Burn" || name == "BURN" || name == "burn")
		{
			return D_TYPE_BURN;
		}
		if (name == "Icy," || name == "ICY," || name == "icy,"
			|| name == "Icy" || name == "ICY" || name == "icy")
		{
			return D_TYPE_ICY;
		}
		if (name == "Poisoned," || name == "POISONED," || name == "poisoned,"
			|| name == "Poisoned" || name == "POISONED" || name == "poisoned")
		{
			return D_TYPE_POISONED;
		}
		if (name == "Bled," || name == "BLED," || name == "bled,"
			|| name == "Bled" || name == "BLED" || name == "bled")
		{
			return D_TYPE_BLED;
		}
		if (name == "Shock," || name == "SHOCK," || name == "shock,"
			|| name == "Shock" || name == "SHOCK" || name == "shock")
		{
			return D_TYPE_SHOCK;
		}
		if (name == "Curse," || name == "CURSE," || name == "curse,"
			|| name == "Curse" || name == "CURSE" || name == "curse")
		{
			return D_TYPE_CURSE;
		}
		CCLOG("UnDefined Type!");
	}
	static std::string changeDamageTypeToKillString(DamageType damage)
	{
		switch (damage)
		{
		case AdvenTriEnum::D_TYPE_COMMON:
			return "Common";
			break;
		case AdvenTriEnum::D_TYPE_BLADE:
			return "Bled";
			break;
		case AdvenTriEnum::D_TYPE_STAB:
			return "Bled";
			break;
		case AdvenTriEnum::D_TYPE_BLUNT:
			return "Common";
			break;
		case AdvenTriEnum::D_TYPE_FIRE:
			return "Burn";
			break;
		case AdvenTriEnum::D_TYPE_FROST:
			return "Frozen";
			break;
		case AdvenTriEnum::D_TYPE_LIGHT:
			return "Shocked";
			break;
		case AdvenTriEnum::D_TYPE_DARK:
			return "Cursed";
			break;
		case AdvenTriEnum::D_TYPE_MAGIC:
			return "Magic";
			break;
		case AdvenTriEnum::D_TYPE_POISON:
			return "Poisoned";
			break;
		case AdvenTriEnum::D_TYPE_BURN:
			return "Burn";
			break;
		case AdvenTriEnum::D_TYPE_ICY:
			return "Frozen";
			break;
		case AdvenTriEnum::D_TYPE_POISONED:
			return "Poisoned";
			break;
		case AdvenTriEnum::D_TYPE_BLED:
			return "Bled";
			break;
		case AdvenTriEnum::D_TYPE_SHOCK:
			return "Shocked";
			break;
		case AdvenTriEnum::D_TYPE_CURSE:
			return "Cursed";
			break;
		default:
			break;
		}
	}
	static std::string changeDamageTypeToString(DamageType damage)
	{
		switch (damage)
		{
		case AdvenTriEnum::D_TYPE_COMMON:
			return "Common";
			break;
		case AdvenTriEnum::D_TYPE_BLADE:
			return "Blade";
			break;
		case AdvenTriEnum::D_TYPE_STAB:
			return "Stab";
			break;
		case AdvenTriEnum::D_TYPE_BLUNT:
			return "Blunt";
			break;
		case AdvenTriEnum::D_TYPE_FIRE:
			return "Fire";
			break;
		case AdvenTriEnum::D_TYPE_FROST:
			return "Frost";
			break;
		case AdvenTriEnum::D_TYPE_LIGHT:
			return "Light";
			break;
		case AdvenTriEnum::D_TYPE_DARK:
			return "Dark";
			break;
		case AdvenTriEnum::D_TYPE_MAGIC:
			return "Magic";
			break;
		case AdvenTriEnum::D_TYPE_POISON:
			return "Poison";
			break;
		case AdvenTriEnum::D_TYPE_BURN:
			return "Burn";
			break;
		case AdvenTriEnum::D_TYPE_ICY:
			return "Frozen";
			break;
		case AdvenTriEnum::D_TYPE_POISONED:
			return "Poisoned";
			break;
		case AdvenTriEnum::D_TYPE_BLED:
			return "Bleed";
			break;
		case AdvenTriEnum::D_TYPE_SHOCK:
			return "Shock";
			break;
		case AdvenTriEnum::D_TYPE_CURSE:
			return "Curse";
			break;
		default:
			break;
		}
	}
	enum Debuff
	{
		DBUFF_FIRE,
		DBUFF_FROST,
		DBUFF_PARRYED,
		DBUFF_POISON,
		DBUFF_CURSE,
		DBUFF_SHOCK,
		DBUFF_BLEED,
	};
	static std::string changeDebuffTypeToString(Debuff debuff)
	{
		switch (debuff)
		{
		case DBUFF_FIRE:
			return "Burn";
		case DBUFF_FROST:
			return "Frozen";
		case DBUFF_PARRYED:
			return "Parryed";
		case DBUFF_POISON:
			return "Poisoned";
		case DBUFF_CURSE:
			return "Cursed";
		case DBUFF_SHOCK:
			return "Shocked";
		case DBUFF_BLEED:
			return "Bled";
		default:
			break;
		}
	};
	enum ItemUseCallfunc
	{
		US_C_RESTORE_HP,
		US_C_RESTORE_MP,
		US_C_DAMAGETO_SELF,
	};
	static ItemUseCallfunc changeStringToItemUseCallfunc(const std::string& name)
	{

		if (name == "RestoreHp," || name == "RestoreHP," || name == "restorehp," || name == "restoreHP,"
			|| name == "RestoreHp" || name == "RestoreHP" || name == "restorehp" || name == "restoreHP")
		{
			return US_C_RESTORE_HP;
		}
		if (name == "RestoreMp," || name == "RestoreMP," || name == "restoremp," || name == "restoreMP,"
			|| name == "RestoreMp" || name == "RestoreMP" || name == "restoremp" || name == "restoreMP")
		{
			return US_C_RESTORE_MP;
		}
		if (name == "DamageToSelf," || name == "damagetoself," || name == "DamagetoSelf," || name == "damagetoSelf,"
			|| name == "DamageToSelf" || name == "damagetoself" || name == "DamagetoSelf" || name == "damagetoSelf")
		{
			return US_C_DAMAGETO_SELF;
		}
		CCLOG("UnDefined Type!");
	}
	enum ItemDropCallfunc
	{
		DP_C_DEFAULT,
		DP_C_FLYING,
	};
	static ItemDropCallfunc changeStringToItemDropCallfunc(const std::string& name)
	{
		if (name == "FLYING," || name == "Flying," || name == "flying,"
			|| name == "FLYING" || name == "Flying" || name == "flying")
		{
			return DP_C_FLYING;
		}
		if (name == "Default," || name == "DEFAULT," || name == "default,"
			|| name == "Default" || name == "DEFAULT" || name == "default")
		{
			return DP_C_DEFAULT;
		}
		CCLOG("UnDefined Type!");
	}
	enum FlyEndCallfunc
	{
		FE_C_DEFAULT,
		FE_C_BLAST,
	};
	static FlyEndCallfunc changeStringToFlyEndCallfunc(const std::string& name)
	{
		if (name == "BLAST," || name == "Blast," || name == "blast,"
			|| name == "BLAST" || name == "Blast" || name == "blast")
		{
			return FE_C_BLAST;
		}
		if (name == "Default," || name == "DEFAULT," || name == "default,"
			|| name == "Default" || name == "DEFAULT" || name == "default")
		{
			return FE_C_DEFAULT;
		}
		CCLOG("UnDefined Type!");
	}
	enum EmojiEnterAction
	{
		EE_A_DEFAULT,
		EE_A_FADEIN,
	};
	static EmojiEnterAction changeStringToEmojiEnterAction(const std::string& name)
	{
		if (name == "" || name == "Default," || name == "DEFAULT," || name == "default,"
			|| name == "Default" || name == "DEFAULT" || name == "default")
		{
			return EE_A_DEFAULT;
		}
		if (name == "FadeIn," || name == "FADEIN," || name == "fadein," || name == "Fadein,"
			|| name == "FadeIn" || name == "FADEIN" || name == "fadein" || name == "Fadein")
		{
			return EE_A_FADEIN;
		}
		CCLOG("UnDefined Type!");
	}
	enum MenuAnimation
	{
		MEA_FORCE,
		MEA_FADEIN,
		MEA_FLYFROM,
		MEA_JUMPFROM,
		MQA_FORCE,
		MQA_FADEOUT,
		MQA_FLYTO,
		MQA_JUMPTO,
	};
	static MenuAnimation changeStringToMenuAnimation(const std::string& name)
	{
		if (name == "" || name == "Force," || name == "FORCE," || name == "force,"
			|| name == "Force" || name == "FORCE" || name == "force")
		{
			return MEA_FORCE;
		}
		if (name == "FadeIn," || name == "FADEIN," || name == "Fadein,"
			|| name == "FadeIn" || name == "FADEIN" || name == "Fadein")
		{
			return MEA_FADEIN;
		}
		if (name == "FlyFrom," || name == "FLYFROM," || name == "Flyfrom,"
			|| name == "FlyFrom" || name == "FLYFROM" || name == "Flyfrom")
		{
			return MEA_FLYFROM;
		}
		if (name == "JumpFrom," || name == "JUMPFROM," || name == "Jumpfrom,"
			|| name == "JumpFrom" || name == "JUMPFROM" || name == "Jumpfrom")
		{
			return MEA_JUMPFROM;
		}
		if (name == "" || name == "ForceOut," || name == "FORCEOUT," || name == "fouceOut,"
			|| name == "ForceOut" || name == "FORCEOUT" || name == "fouceOut")
		{
			return MQA_FORCE;
		}
		if (name == "FadeOut," || name == "FADEOUT," || name == "Fadeout,"
			|| name == "FadeOut" || name == "FADEOUT" || name == "Fadeout")
		{
			return MQA_FADEOUT;
		}
		if (name == "FlyTo," || name == "FLYTO," || name == "Flyto,"
			|| name == "FlyTo" || name == "FLYTO" || name == "Flyto")
		{
			return MQA_FLYTO;
		}
		if (name == "JumpTo," || name == "JUMPTO," || name == "Jumpto,"
			|| name == "JumpTo" || name == "JUMPTO" || name == "Jumpto")
		{
			return MQA_JUMPTO;
		}
		CCLOG("Undefined Type!");
	}
};

#endif