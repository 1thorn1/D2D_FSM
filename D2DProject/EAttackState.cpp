#include "EAttackState.h"

void EAttackState::Enter()
{
	AnimationScene* EMoveAni;
	EMoveAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EMoveAni->LoadAnimationAsset(L"CSV/EAttack.txt");
	EMoveAni->SetAnimation(5, 0);
}

void EAttackState::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 0;
	}
	else if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmaxRect) &&
			!DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->SetCurState("EMove");
	}
}

void EAttackState::Exit()
{
}