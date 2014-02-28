#ifndef STATICOBJECT_H
#define STATICOBJECT_H

enum ObjectType
{
	TREASURE,
	HOLE,
	ESCAPE,
	FLOOR
};

#include "StaticSprite.h"
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject();
	StaticObject(ObjectType type, Position pos, std::string filename);
	~StaticObject();
	ObjectType GetType() const { return m_type; }

private:
	ObjectType m_type;
};

#endif