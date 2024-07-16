#pragma once
#include "IEnemyState.h"
#include "Enemy.h"
#include "Player.h"

class EAttackState : public IEnemyState
{
	InputManager KeyManager;
public:
	EAttackState(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~EAttackState() {}

	void Enter();
	void Update();
	void Exit();
};

