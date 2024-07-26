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
	
	bool CheckCollision(Vector2F& location, float radius);
	void ResolveCollision(Vector2F& location, Vector2F& velocity, float radius);

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};