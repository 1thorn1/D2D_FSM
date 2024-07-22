#pragma once
#include "IEnemyState.h"
#include "FPlayer.h"
#include "SPlayer.h"

// 기본 상태 (다른 게임에서는 Idle일 수도 있는) 를 나타냄
class Idle : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	Idle(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~Idle() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};