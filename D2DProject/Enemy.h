#pragma once
#include "DemoApp.h"
#include "../Engine/AABB.h"
class Enemy
	: public GameObject
{
public:
	AnimationScene* EnemyAni;
	FiniteStateMachine* fsm;

	Enemy();
	~Enemy();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();

};