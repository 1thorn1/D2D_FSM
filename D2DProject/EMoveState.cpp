#include "EMoveState.h"

void EMoveState::Enter()
{
	AnimationScene* EMoveAni;
	EMoveAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EMoveAni->LoadAnimationAsset(L"CSV/EMove.txt");
	EMoveAni->SetAnimation(4, 0);
}

void EMoveState::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	
	Player m_Player;
	Enemy m_Enemy;
	
	if (m_Player.m_BoundBox.CheckIntersect(m_Enemy.BmaxRect))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.y -= 1;
	}
}

void EMoveState::Exit()
{
}
