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
}

void EIdleState::Exit()
{
}
