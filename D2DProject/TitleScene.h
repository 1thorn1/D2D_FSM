#pragma once
#include "DemoApp.h"

class TitleScene : public World
{

public:
	TitleScene();
	virtual ~TitleScene();

	void Update();
	void Render();
	void Clear();
};

