#pragma once
#include "IEnemyState.h"
#include "FPlayer.h"
#include "SPlayer.h"

// �⺻ ���� (�ٸ� ���ӿ����� Idle�� ���� �ִ�) �� ��Ÿ��
class DRun : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	DRun(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~DRun() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};
