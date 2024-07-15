#pragma once
#include "DemoApp.h"

class Player
	: public GameObject
{
public:

	AnimationScene* PlayerAni;
	FiniteStateMachine* fsm;

	Player();
	virtual ~Player();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};