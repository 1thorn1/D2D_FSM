#pragma once
#include "DemoApp.h"
#include "SPlayer.h"

class Object : public GameObject
{
public:

	static BitmapScene* m_Object;
	static Vector2F ob_velocity;

	Object();
	virtual ~Object();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};

