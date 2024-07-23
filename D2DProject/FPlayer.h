#pragma once
#include "DemoApp.h"

class FPlayer
	: public GameObject
{
public:

	AnimationScene* FPlayerAni;
	FiniteStateMachine* fsm;

	FPlayer();
	virtual ~FPlayer();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};