#pragma once
#include "DemoApp.h"
#include "GameManager.h"

class SPlayer
	: public GameObject
{
public:

	static Vector2F sp_velocity;
	AnimationScene* SPlayerAni;
	FiniteStateMachine* fsm;

	CustomInput input;

	SPlayer();
	virtual ~SPlayer();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};