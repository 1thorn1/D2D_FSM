#pragma once
#include "AABB.h"
#include "Debug.h"

class Collider_BTOB :public AABB
{
	// 바운드 박스 간의 충돌
	AABB BTOB;
public:
	void Initialize();
	static void Update();
};

class Collider_BTOC
{
	// 바운드 박스와 원의 충돌
public:
	void Initialize();
	static void Update();
};



