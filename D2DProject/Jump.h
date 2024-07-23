#pragma once
#include "DemoApp.h"
#include "IPlayerState.h"
#include "FPlayer.h"
#include "SPlayer.h"

// �����Q�� ������ �� �� ���
class Jump : public IPlayerState, public IAnimationProcesser
{
	InputManager KeyManager;
	TimeManager timeManager;

	float gravityScale;
	float jumpForce;
	float position;
	float velocity;
	bool isJumping;

public:
	Jump(FiniteStateMachine* pOwner, std::string Name)
		:IPlayerState(pOwner, Name)
	{}
	virtual ~Jump() {}
	virtual void Initialize();

	void Enter();
	void Update();
	void Exit();

	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};
