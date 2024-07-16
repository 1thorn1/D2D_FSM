#pragma once
#include "../Engine/GameApp.h"

class Player;

class DemoApp : public GameApp
{
public:
	static Player* m_pPlayer;

	World tempWorld;
	
	void Initialize(HINSTANCE hInstance);

	void CheckKeyInput();
	void PrintUsedVRAM();

	void FixedUpdate();
	void Update();
	void Render();
};

