#include "MoveState.h"

void MoveState::Enter()
{
	// Walk�ִϸ��̼� ���!
	//m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;

	AnimationScene* ani;
	ani = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	ani->LoadAnimationAsset(L"CSV/KenMove.txt");
	ani->SetAnimation(3, 0);
	m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
}

void MoveState::Update()
{
	/*Ư�� Ű ������ �� Ư�� Walk ��������Ʈ�� �۵��ϰԲ�
	�÷��̾� �ִϸ��̼��� ��Ʈ ���� �� �˾����� ���ڴµ� ��ĳ �˰� ���� ��������*/
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	if (KeyManager.IsKeyDown('W'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.y -= 1;
	}
	if (KeyManager.IsKeyDown('S'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.y += 1;
	}
	if (KeyManager.IsKeyDown('A'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
	}
	if (KeyManager.IsKeyDown('D'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;
	}

	if (!KeyManager.IsKeyDown('W') &&
		!KeyManager.IsKeyDown('S') &&
		!KeyManager.IsKeyDown('A') &&
		!KeyManager.IsKeyDown('D'))
	{
		fsm->SetCurState("Idle");
	}
}
void MoveState::Exit()
{
}
