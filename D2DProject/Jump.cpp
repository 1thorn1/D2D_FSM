#include "Jump.h"

void Jump::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/Jump.txt");
	DRunAni->SetAnimation(9, 0);
}

void Jump::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	
	// ���� �ݶ��̴��� �÷��̾��� �ݶ��̴��� ������ Attack ������� ����

}

void Jump::Exit()
{
}

void Jump::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
