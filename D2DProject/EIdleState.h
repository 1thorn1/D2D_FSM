#pragma once
#include "DemoApp.h"
#include "Enemy.h"

class EIdleState : public FSMState
{
	InputManager KeyManager;
public:
	EIdleState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~EIdleState() {}

	void Enter();
	void Update();
	void Exit();
};

