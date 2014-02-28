#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#pragma once
#include "..\..\Engine\Advanced2D.h"

#include "GameObject.h"
#include "UserInterface.h"
#include <map>

class GameManager
{
	typedef std::pair<unsigned int,GameObject*> GameObjectPair;
public:
	UserInterface GameInterface;
	

	GameManager();
	~GameManager();

	void AddObject(GameObject* gameObject);
	void AddPlayer(GameObject* gameObject) { *player = *gameObject;};
	GameObject* GetPlayer(GameObject* GameObject) {return player;};
	void GameInit();

	enum GameStates { 
		PREGAME, 
		INGAME, 
		ENDGAME,
		INVALID};

	static GameStates CurrentState;

	

private:
	std::map<unsigned int,GameObject*> m_GameObjects;
	static GameObject* player;
};

#endif

