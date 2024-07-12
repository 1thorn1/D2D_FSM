#pragma once
#include "DemoApp.h"
// 부모 생성자에 인수를 넘겨줘야 대니까 생성자 정의 할것
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