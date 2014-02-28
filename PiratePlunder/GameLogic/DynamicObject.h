#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

enum ObjectType
{
	PLAYER,
	ENEMY
};

enum AnimationState
{
	IDLE,
	WALKING,
	DEAD
};

#include "AnimatedSprite.h"
#include "GameObject.h"

class DynamicObject : public GameObject
{
public:
	DynamicObject();
	~DynamicObject();
	ObjectType GetType() const { return m_type; }
	AnimationState GetAnimState() const { return m_state; }
	void AllowMovement() { canMove = true; }
	void FreezeMovement() { canMove = false; }
	void SetAnimState(AnimationState state) { m_state = state; }
	virtual void CheckCollision(GameObject* other);

protected:
	ObjectType m_type;
	AnimationState m_state;
	bool canMove;
};

#endif