#pragma once
#include "DemoApp.h"
#include "../Engine/AABB.h"
class Enemy
	: public GameObject
{
public:
	AnimationScene* EnemyAni;
	FiniteStateMachine* fsm;
	AABB BmidRect;
	AABB BmaxRect;
	float m_speed;
	
	
	Enemy();
	~Enemy();

	virtual void Initialize(float x, float y, float speed);
	virtual void Update();
	virtual void Render();

};