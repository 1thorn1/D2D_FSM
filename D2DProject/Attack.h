#pragma once
#include "IEnemyState.h"
#include "FPlayer.h"
#include "SPlayer.h"

// ���� ���� ĥ �� ��Ÿ���� ����

class Attack : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	Attack(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~Attack() {}

	void Enter();
	void Update();
	void Exit();

	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};

