#include "EAttackState.h"

void EAttackState::Enter()
{
	AnimationScene* EMoveAni;
	EMoveAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EMoveAni->LoadAnimationAsset(L"CSV/EAttack.txt");
	EMoveAni->SetAnimation(4, 0);
}

void EAttackState::Update()
{
	// 플레이어가 mid 바운드 박스로 들어오면 Attack 모션 취하기
}

void EAttackState::Exit()
{
}
