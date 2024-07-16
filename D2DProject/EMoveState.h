#pragma once
#include "IEnemyState.h"
#include "Player.h"
#include "Enemy.h"

class EMoveState : public IEnemyState
{
	InputManager KeyManager;
public:
	EMoveState(FiniteStateMachine* pOwner, std::string Name)
		: IEnemyState(pOwner, Name)
	{}
	virtual ~EMoveState() {}

	void Enter();
	void Update();
	void Exit();
};

