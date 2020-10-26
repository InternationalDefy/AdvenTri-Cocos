#ifndef __M_ACITONMANAGER__
#define __M_ACITONMANAGER__

#include "cocos2d.h"

using namespace cocos2d;

class M_ActionParser;
class M_AnimationPack;
class Entity;

class M_ActionHandler :public Ref
{
private:
	static M_ActionHandler* create();
	void init();
	std::map<std::string, M_ActionParser*> _actionParsers;
public:
	static M_ActionHandler* getInstance();
	/*
	@param Entity
	@param AnimationPackName
	*/
	void addAnimationPackToEntity(Entity* entity, const std::string& name);
	/*
	@param Node* parentNode exp BG Entity
	@param Vec2 position swamping Position
	@param localZ position local Z Order
	@param AnimationName name in DB_Animation
	*/
	void runEnvirAction(Node* pNode,Vec3 position,int localZ,const std::string& name);
	/*
	@param const std::string& AnimationName(in DB_Animation)
	*/
	FiniteTimeAction* getAction(Node* node, const std::string&);
	/*
	@param const std::string& type
	@param std::vector<std::string> params
	*/
	FiniteTimeAction* getAction(Node* node, const std::string&, std::vector<std::string>);
	/*
	@param const std::string& type
	@param Vector<String*>* params
	*/
	FiniteTimeAction* getAction(Node* node, const std::string&, Vector<String*>*);
};

#endif