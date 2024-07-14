#pragma once
#include "DemoApp.h"

class Player
	: public GameObject
{
	InputManager KeyManager;
	AnimationScene* m_pPlayer;

public:
	Player() {};
	Player(const std::wstring& animationFilePath);
	virtual ~Player();

	void SetAnimationFilePath(const std::wstring& animationFilePath);
	void PlayerMove();
	virtual void Update();
};