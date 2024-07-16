#include "EMoveState.h"

void EMoveState::Enter()
{
	AnimationScene* EMoveAni;
	EMoveAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EMoveAni->LoadAnimationAsset(L"CSV/EMove.txt");
	EMoveAni->SetAnimation(6, 0);
}

void EMoveState::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();

	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmaxRect) &&
	   !DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 0.5;
	}
	else
	{
		fsm->SetCurState("EIdle");
	}
	// 플레이어가 mid 바운드 박스로 들어오면 Attack 모션 취하기
	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->SetCurState("EAttack");
	}
}

void EMoveState::Exit()
{
}
