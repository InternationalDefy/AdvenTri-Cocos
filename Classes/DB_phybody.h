#ifndef __DB_PHYSICS__
#define __DB_PHYSICS__

#include "cocos2d.h"

#include "Ref_DataBase.h"

class PhysicsStringData;

USING_NS_CC;

class DB_Physics : public DB
{
private:
	
	std::string tempName;
	PhysicsStringData* tempPStringData;

	Map<std::string,PhysicsStringData*> _table;
		
public:

	std::string useString(){ return "Table_Physics.csv"; }
	void getLine(const std::string& data);

	static DB_Physics* getInstance();
	static DB_Physics* create();

	PhysicsBody* getBody(const std::string& name);
};

#endif