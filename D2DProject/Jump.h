#pragma once

#include "IEnemyState.h"
#include "FPlayer.h"
#include "SPlayer.h"

// 삒깻쯖이 점프를 할 때 모션
class Jump : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	Jump(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~Jump() {}

	void Enter();
	void Update();
	void Exit();

	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};
