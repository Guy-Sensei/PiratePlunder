#include "Character.h"


Character::Character(ObjectType type, Position pos, std::string filename, int sizeW, int sizeH, int columns, int totalFrames)
{
	m_type = type;
	m_Position = pos;

	sprite->loadImage(filename);
	sprite->setColumns(columns);
	sprite->setSize(sizeW, sizeH);
	sprite->setTotalFrames(totalFrames);
	sprite->setFrameTimer(30);
}


Character::~Character()
{
}
