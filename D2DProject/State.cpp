#include "State.h"

// Idle
void IdleState::Enter()
{
}

void IdleState::Update()
{
	InputManager KeyManager;
	if (KeyManager.IsKeyDown('K'))
	{

	}
}

void IdleState::Exit()
{
}

// Attack
void AttackState::Enter()
{
}

void AttackState::Update()
{
}

void AttackState::Exit()
{
}

// Move
void MoveState::Enter()
{
}

void MoveState::Update()
{
}

void MoveState::Exit()
{
}

// Death
void DeathState::Enter()
{
}

void DeathState::Update()
{
}

void DeathState::Exit()
{
}
