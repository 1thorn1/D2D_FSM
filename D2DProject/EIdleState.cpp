#include "EIdleState.h"

void EIdleState::Enter()
{
	AnimationScene* EIdleAni;
	EIdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EIdleAni->LoadAnimationAsset(L"CSV/EIdle.txt");
	EIdleAni->SetAnimation(4, 0);
}

void EIdleState::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();

	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmaxRect))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
	}

	// player주소를 미리 알고있어야댐. <- 플레이어 하나만 충돌검사할 때 좋음.
}

void EIdleState::Exit()
{
}
