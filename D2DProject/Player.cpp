#include "Player.h"
#include "IdleState.h"
#include "MoveState.h"

Player::Player()
{
	PlayerAni = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/ken.png", &PlayerAni->m_pBitmap);
	PlayerAni->m_RelativeLocation = { 100 ,200 };
	SetRootScene(PlayerAni);

	fsm = CreateComponent<FiniteStateMachine>();
	fsm->CreateState<IdleState>("Idle");
	fsm->CreateState<MoveState>("Move");
	fsm->SetCurState("Idle");
}

Player::~Player()
{
}

void Player::Initialize()
{
	// �÷��̾��� �ڽ� �ݶ��̴� ����
}

void Player::Update()
{
	__super::Update();
}

void Player::Render()
{
	__super::Render();
	// �÷��̾��� �ڽ� �ݶ��̴� ���
}
