#include "SDRun.h"

void SDRun::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
	DRunAni->SetAnimation(8, 0);
	// FPlayer�̸� �ݴ� ������ ���� �ٲ���
}

void SDRun::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// �÷��̾��� �ݶ��̴��� ���� �ݶ��̴��� ������
	// �߷°� ź���� �޾� ���� Ƣ���
	if (KeyManager.IsKeyDown(VK_UP))
	{
		// ���� ����
		fsm->SetCurState("DJump");

		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			// ���� ġ��
		}

	}
	if (KeyManager.IsKeyDown(VK_LEFT))
	{
		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;
		if (KeyManager.IsKeyDown(VK_LEFT) && KeyManager.IsKeyDown(VK_RETURN))
		{
			// ���̺� ��� ���ϱ�
		}

	}

	if (KeyManager.IsKeyDown(VK_RIGHT))
	{
		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
		if (KeyManager.IsKeyDown(VK_RIGHT) && KeyManager.IsKeyDown(VK_RETURN))
		{
			// ���̺� ��� ���ϱ�
		}
	}

	// enter + ����Ű , shift + a,d => save ���
}

void SDRun::Exit()
{
}

void SDRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
