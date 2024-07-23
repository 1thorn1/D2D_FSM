#include "FDRun.h"

void FDRun::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
	DRunAni->SetAnimation(8, 1);
	// FPlayer�̸� �ݴ� ������ ���� �ٲ���
}

void FDRun::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// �÷��̾��� �ݶ��̴��� ���� �ݶ��̴��� ������
	// �߷°� ź���� �޾� ���� Ƣ���
	//if (KeyManager.IsKeyDown('W'))
	//{
	//	// ���� ����
	//	fsm->SetCurState("DJump");

	//	// ������ ������ �����ϸ� �ٽ� FDRun���� ����
	//	if (KeyManager.IsKeyDown(VK_SHIFT))
	//	{
	//		// ���� ġ��
	//	}

	//}
	//if (KeyManager.IsKeyDown('A'))
	//{
	//	// �׳� ���� �ִϸ��̼� ���, ������ �̵�
	//	fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
	//	m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;
	//	if ( KeyManager.IsKeyDown(VK_SHIFT))
	//	{
	//		// ���̺� ��� ���ϱ�
	//	}
	//}

	//if (KeyManager.IsKeyDown('D'))
	//{
	//	// �׳� ���� �ִϸ��̼� ���, ������ �̵�
	//	fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
	//	m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
	//	if (KeyManager.IsKeyDown(VK_SHIFT))
	//	{
	//		// ���̺� ��� ���ϱ�
	//	}
	//}

	// enter + ����Ű , shift + a,d => save ���
}

void FDRun::Exit()
{
}

void FDRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
