#pragma once
#include "DemoApp.h"

class PlayScene : World

{
public:
	PlayScene();
	virtual ~PlayScene();

	void Update();
	void Render();
	void Clear();
};

