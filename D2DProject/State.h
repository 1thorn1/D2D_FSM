#pragma once
#include "DemoApp.h"
// �θ� �����ڿ� �μ��� �Ѱ���� ��ϱ� ������ ���� �Ұ�
class IdleState   //: public FSMState
{
public:
	void Enter();
	void Update();
	void Exit();
};

class AttackState //: public FSMState
{
public:
	void Enter();
	void Update();
	void Exit();
};

class MoveState //: public FSMState
{
public:
	void Enter();
	void Update();
	void Exit();
};

class DeathState //: public FSMState
{
public:
	void Enter();
	void Update();
	void Exit();
};