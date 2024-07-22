#pragma once
#include "IEnemyState.h"
#include "FPlayer.h"
#include "SPlayer.h"

// �⺻ ���� (�ٸ� ���ӿ����� Idle�� ���� �ִ�) �� ��Ÿ��
class FDRun : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	FDRun(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~FDRun() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};