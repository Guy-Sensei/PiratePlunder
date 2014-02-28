#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "GameObject.h"
class GameEntity : public GameObject
{
public:
	GameEntity();
	~GameEntity();
	char* GetType() const { return "Entity";}
};

#endif

