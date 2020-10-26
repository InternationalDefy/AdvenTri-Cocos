#include "Ref2Physics.h"

USING_NS_CC;

void DB_PhyShape::getLine(const std::string& data)
{
	
	tempShapeData = PieceOfShape::create();
	tempName = analyseMiddle(data);
	//tempShapeData->setPtag(std::atoi(analyseMiddle(data).c_str()));
	tempShapeData->setDensity(std::atof(analyseMiddle(data).c_str()));
	tempShapeData->setFriction(std::atof(analyseMiddle(data).c_str()));
	tempShapeData->setRestitution(std::atof(analyseMiddle(data).c_str()));
	tempShapeData->setCategoryMask(std::atoi(analyseMiddle(data).c_str()));
	tempShapeData->setCollisionMask(std::atoi(analyseMiddle(data).c_str()));
	tempShapeData->setContactTestMask(std::atoi(analyseMiddle(data).c_str()));
	tempShapeData->setPtag(std::atoi(analyseMiddle(data).c_str()));
	tempShapeData->setType(analyseMiddle(data).c_str());
	if (tempShapeData->getType() == "Polygon")
	{
		tempShapeData->setNumberOfEdges(std::atoi(analyseMiddle(data).c_str()));
		for (int i = 0; i < tempShapeData->getNumberOfEdges(); ++i)
		{
			float x = std::atof(analyseMiddle(data).c_str());
			float y = std::atof(analyseMiddle(data).c_str());
			tempShapeData->getVetrexs()->push_back(Vec2(x, y));
		}
		analyseEndln(data);
	}
	else if (tempShapeData->getType() == "Rect")
	{
		float x = std::atof(analyseMiddle(data).c_str());
		float y = std::atof(analyseEndln(data).c_str());
		tempShapeData->getVetrexs()->push_back(Vec2(x, y));
	}
	else if (tempShapeData->getType() == "Circle")
	{
		tempShapeData->setR(std::atoi(analyseEndln(data).c_str()));
	}
	_shapeData.insert(tempName,tempShapeData);
}
PhysicsShape* DB_PhyShape::getShape(const std::string& name,Vec2 Offset)
{
	if (_shapeData.at(name))
	{
		_shapeData.at(name)->setOffSet(Offset);
		return _shapeData.at(name)->createShape();
	}
	else
	{
		auto k = "Physics Shape Name " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_PhyShape);