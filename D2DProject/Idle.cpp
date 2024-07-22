#include "Idle.h"

void Idle::Enter()
{
	AnimationScene* IdleAni;
	IdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	IdleAni->LoadAnimationAsset(L"CSV/Idle.txt");
	IdleAni->SetAnimation(10, 1);
}

void Idle::Update()
{
}

void Idle::Exit()
{
}

void Idle::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
