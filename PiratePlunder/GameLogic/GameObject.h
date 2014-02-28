#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Grid.h"
#include "..\..\Engine\Advanced2D.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	unsigned int GetId() const {return m_ID;}
	Position GetPosition() const { return m_Position; }
	Position SetPoisition(int x, int y) { m_Position.x = x; m_Position.y = y; }

protected:
	unsigned int m_ID;
	static unsigned int ID_INDEX;
	Position m_Position;
	Advanced2D::Sprite* sprite;
};

#endif