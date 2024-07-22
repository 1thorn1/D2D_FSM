#include "SPlayer.h"

SPlayer::SPlayer()
{
	SPlayerAni = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/realpikachuuu.png", &SPlayerAni->m_pBitmap);
	SetRootScene(SPlayerAni);
	//SPlayerAni->m_RelativeLocation = { -600,0 };
	SPlayerAni->m_RelativeScale = { 2.2f,2.2f };

	fsm = CreateComponent<FiniteStateMachine>();
	//fsm->CreateState<Attack>("SAttack");
	fsm->CreateState<Idle>("PIdle");
	fsm->CreateState<SDRun>("SDRun");
	fsm->CreateState<Jump>("DJump");
	fsm->SetCurState("PIdle");
}

SPlayer::~SPlayer()
{
}

void SPlayer::Initialize(float gravityScale, float jumpForce)
{
	this->gravityScale = gravityScale;
	this->jumpForce = jumpForce;
}

void SPlayer::Update()
{
	__super::Update();  
}

void SPlayer::Render()
{
	__super::Render();
}
