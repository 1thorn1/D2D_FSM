#pragma once
#include "DemoApp.h"

class Player
	: public GameObject
{
	InputManager KeyManager;

public:

	AnimationScene* m_pPlayer;
	FiniteStateMachine* fsm;

	Player();
	virtual ~Player();

	virtual void Update();
};