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
		// �÷��̾��� ��ǥ�� ���ʹ� ��ǥ �Ÿ� ����ϱ�


	}
	else
	{
		fsm->SetCurState("EIdle");
	}
	// �÷��̾ mid �ٿ�� �ڽ��� ������ Attack ��� ���ϱ�
	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->SetCurState("EAttack");
	}
}

void EMoveState::Exit()
{
}

void EMoveState::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
