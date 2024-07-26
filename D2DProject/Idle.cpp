#include "Idle.h"
#include "GameManager.h"

void Idle::Enter()
{
	AnimationScene* IdleAni;
	IdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	IdleAni->LoadAnimationAsset(L"CSV/Idle.txt");
	IdleAni->SetAnimation(3, 0);
}

void Idle::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// �÷��̾��� �ݶ��̴��� ���� �ݶ��̴��� ������
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		// ���� ����
		fsm->SetCurState("DJump");

	}
	if (KeyManager.IsKeyHold(owner->input.left))
	{
		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
		fsm->SetCurState("SDRun");
	}

	if (KeyManager.IsKeyHold(owner->input.right))
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
