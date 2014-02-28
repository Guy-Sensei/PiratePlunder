#include "GameManager.h"


//Sets Default Value
GameManager::GameStates GameManager::CurrentState = PREGAME;

GameManager::GameManager()
{
	
}


GameManager::~GameManager()
{
}

void GameManager::AddObject(GameObject* gameObject)
{
	m_GameObjects.insert(GameObjectPair(gameObject->GetId(),gameObject));
}

void GameManager::GameInit()
{
	return;
}