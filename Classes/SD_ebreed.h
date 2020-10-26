#ifndef __SD_BREED__
#define __SD_BREED__

#include "cocos2d.h"

USING_NS_CC;

class M_Enemy;

class SD_Ebreed : public Ref
{
private:
	std::string _textureName;
	int _id;
	std::string _amor_type_name;
	std::string _unit_type_name;
	//std::vector<int> _skillsId;
	std::string _animation_pack_name;
	std::string _physics_body_name;
	std::string _weapon_type_name;
	std::string _event_listener_name;
	int _ui_collection_id;
	std::string _controller_name;
	void init();
public:
	static SD_Ebreed* create();

	M_Enemy* createFromEbreed();
	
	void setID(int x){ _id = x; }
	void setAmorType(const std::string& x){ _amor_type_name = x; }
	void setUnitType(const std::string& x){ _unit_type_name = x; }
	//void pushSkillsID(int x){ _skillsId.push_back(x); }
	void setAnimationPack(const std::string& x){ _animation_pack_name = x; }
	void setPhysicsBody(const std::string& x){ _physics_body_name = x; }
	void setWeaponType(const std::string& x){ _weapon_type_name = x; }
	void setListenerSetName(const std::string& x){ _event_listener_name = x; }
	void setUiColID(int x){ _ui_collection_id = x; }
	void setController(const std::string& x){ _controller_name = x; }
	void setTextureName(const std::string& x){ _textureName = x; }
};

#endif