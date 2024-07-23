#include "Idle.h"

void Idle::Enter()
{
	AnimationScene* IdleAni;
	IdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	IdleAni->LoadAnimationAsset(L"CSV/Idle.txt");
	IdleAni->SetAnimation(10, 0);
}

void Idle::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// �÷��̾��� �ݶ��̴��� ���� �ݶ��̴��� ������
	if (KeyManager.IsKeyDown(VK_UP))
	{
		// ���� ����
		fsm->SetCurState("DJump");
	}
	if (KeyManager.IsKeyHold(VK_LEFT))
	{
		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
		fsm->SetCurState("SDRun");
	}

	if (KeyManager.IsKeyHold(VK_RIGHT))
	{
		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
		fsm->SetCurState("SDRun");
	}
}

void Idle::Exit()
{
}

void Idle::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
