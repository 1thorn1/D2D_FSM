#pragma once
#include "DemoApp.h"

class Player
	: public GameObject
{
	InputManager KeyManager;
	static AnimationScene* m_pPlayer;

public:
	Player();
	void PlayerMove();
	virtual void Update();
	static AnimationScene* GetPlayer() { return m_pPlayer; }
};