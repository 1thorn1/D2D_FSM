#pragma once
#include "DemoApp.h"
#include "Attack.h"
#include "FDRun.h"
#include "Jump.h"

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