#pragma once
#include "DemoApp.h"
#include "SDRun.h"
#include "Idle.h"

class SPlayer
	: public GameObject
{
public:
	float gravityScale = 0.0f;
	float jumpForce = 0.0f;
	float position = 0.0f;
	float velocity = 0.0f;
	bool isJumping = false;

	AnimationScene* SPlayerAni;
	FiniteStateMachine* fsm;

	SPlayer();
	virtual ~SPlayer();

	virtual void Initialize(float gravityScale, float jumpForce);
	virtual void Update();
	virtual void Render();
};