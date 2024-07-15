#pragma once
#include "DemoApp.h"

class EMoveState : public FSMState
{
	InputManager KeyManager;
public:
	EMoveState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~EMoveState() {}

	void Enter();
	void Update();
	void Exit();
};

