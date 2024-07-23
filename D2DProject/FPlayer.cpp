#include "FPlayer.h"
#include "Attack.h"
#include "FDRun.h"
#include "SDRun.h"
#include "Jump.h"

FPlayer::FPlayer()
{
	FPlayerAni = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/realpikachuuu.png", &FPlayerAni->m_pBitmap);
	SetRootScene(FPlayerAni);
	FPlayerAni->m_RelativeLocation = { -600,0 };
	FPlayerAni->m_RelativeScale = { 2.2f,2.2f };

	fsm = CreateComponent<FiniteStateMachine>();
	fsm->CreateState<Attack>("PAttack");
	fsm->CreateState<FDRun>("FDRun");
	fsm->CreateState<SDRun>("SDRun");
	fsm->CreateState<Jump>("DJump");
	fsm->SetCurState("FDRun");
	\

}

FPlayer::~FPlayer()
{
}

void FPlayer::Initialize()
{
}

void FPlayer::Update()
{
	__super::Update();
}

void FPlayer::Render()
{
	__super::Render();
}
