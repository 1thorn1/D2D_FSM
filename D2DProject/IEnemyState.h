#pragma once
#include "DemoApp.h"
#include "Enemy.h"

class IEnemyState
	: public FSMState
{
protected:
	Enemy* owner = nullptr;
public:
	IEnemyState(FiniteStateMachine* pOwner, std::string Name) : FSMState(pOwner, Name) {}
	virtual void Initialize()
	{
		owner = dynamic_cast<Enemy*>(this->m_pOwner->GetOwner());
	}
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
};