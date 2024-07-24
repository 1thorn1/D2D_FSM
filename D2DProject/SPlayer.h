#pragma once
#include "DemoApp.h"

class SPlayer
	: public GameObject
{
public:

	static AnimationScene* SPlayerAni;
	FiniteStateMachine* fsm;

	SPlayer();
	virtual ~SPlayer();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};