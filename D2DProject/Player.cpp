#include "Player.h"
#include "IdleState.h"
#include "MoveState.h"

Player::Player()
{
	AnimationScene* m_pPlayer = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/ken.png", &m_pPlayer->m_pBitmap);
	m_pPlayer->m_RelativeLocation = { 200 ,200 };
	SetRootScene(m_pPlayer);

	fsm = CreateComponent<FiniteStateMachine>();
	fsm->CreateState<IdleState>("Idle");
	fsm->CreateState<MoveState>("Move");
	fsm->SetCurState("Idle");
}

Player::~Player()
{
}

void Player::Update()
{
	__super::Update();
}
