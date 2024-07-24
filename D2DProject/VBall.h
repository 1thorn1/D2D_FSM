#pragma once
#include "DemoApp.h"
#include "SPlayer.h"

class VBall : public GameObject
{
public:

	static AnimationScene* m_Ball;
	float gravityScale;
	float boundForce;
	float position;
	//float velocity;
	bool isBound;
	Vector2F velocity;


	VBall();
	virtual ~VBall();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};
