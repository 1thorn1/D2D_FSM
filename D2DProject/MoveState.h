#pragma once
#include "DemoApp.h"

class MoveState : public FSMState
{
public:
	MoveState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~MoveState() {}

	virtual void Enter();
	virtual void Update();
	virtual void Exit();
};

