#pragma once
#include "DemoApp.h"

class Player
	: public GameObject
{
	InputManager KeyManager;
	AnimationScene* m_pPlayer;

public:
	Player();
	void PlayerMove();
	virtual void Update();
};