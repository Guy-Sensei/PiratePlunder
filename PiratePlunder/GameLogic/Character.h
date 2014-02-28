#ifndef CHARACTER_H
#define CHARACTER_H

#include "DynamicObject.h"

class Character : public DynamicObject
{
public:
	Character();
	Character(ObjectType type, Position pos, std::string filename, int sizeW, int sizeH, int columns, int totalFrames);
	~Character();
	void Move(int x, int y) { m_Position.x = x; m_Position.y = y; }

private:
	

};

#endif