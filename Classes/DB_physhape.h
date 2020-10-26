#ifndef __DB_PHYSHAPE__
#define __DB_PHYSHAPE__

#include "cocos2d.h"

#include "Ref_DataBase.h"

class PieceOfShape;

USING_NS_CC;

class DB_PhyShape : public DB
{
private:

	std::string tempName;
	PieceOfShape* tempShapeData;
	
	float tempX; float tempY;

	void HandlePolygonDataType(int type, std::string data);
	void HandleCircleDataType(int type, std::string data);
	void HandleRectDataType(int type, std::string data);

	Map<std::string,PieceOfShape*> _shapeData;

public:
	
	std::string useString(){ return "Table_Shape.csv"; }
	void getLine(const std::string& data);
	
	static DB_PhyShape* getInstance();
	static DB_PhyShape* create();

	PhysicsShape* DB_PhyShape::getShape(const std::string& name,Vec2 Offset);

};

#endif