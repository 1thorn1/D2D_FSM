#pragma once
#include "DemoApp.h"

class TitleBackground : public GameObject
{
public:
	BitmapScene* m_titlebackground;
	
	TitleBackground();
	virtual ~TitleBackground();

	virtual void Intialize();
	virtual void Update();
	virtual void Render();
};

