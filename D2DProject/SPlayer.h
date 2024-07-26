#pragma once
#include "DemoApp.h"

class SPlayer
	: public GameObject
{
public:

	static Vector2F sp_velocity;
	static AnimationScene* SPlayerAni;
	FiniteStateMachine* fsm;

	SPlayer();
	virtual ~SPlayer();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};