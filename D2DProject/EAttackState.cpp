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
	// �÷��̾ mid �ٿ�� �ڽ��� ������ Attack ��� ���ϱ�
}

void EAttackState::Exit()
{
}
