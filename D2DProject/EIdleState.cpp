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

	// player�ּҸ� �̸� �˰��־�ߴ�. <- �÷��̾� �ϳ��� �浹�˻��� �� ����.
}

void EIdleState::Exit()
{
}
