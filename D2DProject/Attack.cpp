#include "Attack.h"

void Attack::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/Attack.txt");
	DRunAni->SetAnimation(7, 0);
}

void Attack::Update()
{
}

void Attack::Exit()
{
}

void Attack::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
