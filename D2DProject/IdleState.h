#pragma once
#include "DemoApp.h"
#include "Player.h"

class Player;
class IdleState : public FSMState
{
	Player player;
	InputManager KeyManager;
public:
	IdleState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~IdleState() {}

	void Enter();
	void Update();
	void Exit();
};

