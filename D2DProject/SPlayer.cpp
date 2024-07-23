#include "SPlayer.h"
#include "SDRun.h"
#include "Idle.h"
#include "Attack.h"
#include "Jump.h"

SPlayer::SPlayer()
{
	SPlayerAni = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/realpikachuuu.png", &SPlayerAni->m_pBitmap);
	SetRootScene(SPlayerAni);
	//SPlayerAni->m_RelativeLocation = { 0,-180 };
	SPlayerAni->m_RelativeScale = { 2.f,2.f };

	fsm = CreateComponent<FiniteStateMachine>();
	fsm->CreateState<Attack>("Attack");
	fsm->CreateState<Idle>("PIdle");
	fsm->CreateState<SDRun>("SDRun");
	fsm->CreateState<Jump>("DJump");
	fsm->SetCurState("PIdle");
}

SPlayer::~SPlayer()
{
}

void SPlayer::Initialize()
{
}

void SPlayer::Update()
{
	__super::Update();  
}

void SPlayer::Render()
{
	__super::Render();
}
