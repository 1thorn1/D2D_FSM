#pragma once
#include "DemoApp.h"
#include "SPlayer.h"
#include "Object.h"

class VBall : public GameObject
{
public:

	static AnimationScene* m_Ball;
	float gravityScale;
	float boundForce;
	float position;
	//float velocity;
	bool isBound;
	Vector2F vb_velocity;


	VBall();
	virtual ~VBall();
	
	bool CheckCollision();
	void ResolveCollision();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};
