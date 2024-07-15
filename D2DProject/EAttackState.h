#pragma once
#include "DemoApp.h"

class EAttackState : public FSMState
{
	InputManager KeyManager;
public:
	EAttackState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~EAttackState() {}

	void Enter();
	void Update();
	void Exit();
};

