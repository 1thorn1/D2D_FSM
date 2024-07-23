#include "Idle.h"

void Idle::Enter()
{
	AnimationScene* IdleAni;
	IdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	IdleAni->LoadAnimationAsset(L"CSV/Idle.txt");
	IdleAni->SetAnimation(10, 0);
}

void Idle::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// 플레이어의 콜라이더와 공의 콜라이더가 닿으면
	if (KeyManager.IsKeyDown(VK_UP))
	{
		// 점프 실행
		fsm->SetCurState("DJump");
	}
	if (KeyManager.IsKeyHold(VK_LEFT))
	{
		// 그냥 현재 애니메이션 재생, 앞으로 이동
		fsm->SetCurState("SDRun");
	}

	if (KeyManager.IsKeyHold(VK_RIGHT))
	{
		// 그냥 현재 애니메이션 재생, 뒤으로 이동
		fsm->SetCurState("SDRun");
	}
}

void Idle::Exit()
{
}

void Idle::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
