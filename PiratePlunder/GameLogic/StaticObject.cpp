#include "StaticObject.h"

StaticObject::StaticObject(ObjectType type, Position pos, std::string filename)
{
	m_type = type;
	m_Position = pos;

	sprite->loadImage(filename);
}