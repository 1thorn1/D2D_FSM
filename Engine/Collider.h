#pragma once
#include "AABB.h"
#include "Debug.h"

class Collider_BTOB :public AABB
{
	// �ٿ�� �ڽ� ���� �浹
	AABB BTOB;
public:
	void Initialize();
	static void Update();
};

class Collider_BTOC
{
	// �ٿ�� �ڽ��� ���� �浹
public:
	void Initialize();
	static void Update();
};



