#pragma once
#include "IEnemyState.h"
#include "FPlayer.h"
#include "SPlayer.h"

// �⺻ ���� (�ٸ� ���ӿ����� Idle�� ���� �ִ�) �� ��Ÿ��
class SDRun : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	SDRun(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~SDRun() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};