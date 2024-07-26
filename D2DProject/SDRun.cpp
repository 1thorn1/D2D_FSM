#include "SDRun.h"
#include "GameManager.h"

void SDRun::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
	DRunAni->SetAnimation(1, 0);
	// FPlayer�̸� �ݴ� ������ ���� �ٲ���
}

void SDRun::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// �÷��̾��� �ݶ��̴��� ���� �ݶ��̴��� ������
	// �߷°� ź���� �޾� ���� Ƣ���
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		// ���� ����
		fsm->SetCurState("DJump");
	}

	if (KeyManager.IsKeyDown(owner->input.left))
	{
		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;

		// ���̺� ��� ���ϱ�
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
		}
	}

	if (KeyManager.IsKeyDown(owner->input.right))
	{
		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			// ���̺� ��� ���ϱ�
		}
	}

	if (!KeyManager.IsKeyDown(owner->input.left) && !KeyManager.IsKeyDown(owner->input.right))
	{
		fsm->SetCurState("PIdle");
	}
}

void SDRun::Exit()
{
}

void SDRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
