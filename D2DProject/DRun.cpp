//#include "DRun.h"
//
//void DRun::Enter()
//{
//	AnimationScene* DRunAni;
//	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
//	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
//	DRunAni->SetAnimation(8, 0);
//	// FPlayer�̸� �ݴ� ������ ���� �ٲ���
//}
//
//void DRun::Update()
//{
//	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
//	// �÷��̾��� �ݶ��̴��� ���� �ݶ��̴��� ������
//	// �߷°� ź���� �޾� ���� Ƣ���
//	if (KeyManager.IsKeyDown('W') || KeyManager.IsKeyDown(VK_UP))
//	{
//		// ���� ����
//		fsm->SetCurState("Jump");
//
//		if (KeyManager.IsKeyDown('W') && KeyManager.IsKeyDown(VK_SHIFT))
//		{
//			// ���� ġ��
//		}
//		if (KeyManager.IsKeyDown(VK_UP) && KeyManager.IsKeyDown(VK_RETURN))
//		{
//			// ���� ġ��
//		}
//		
//	}
//	if (KeyManager.IsKeyDown('A') || KeyManager.IsKeyDown(VK_LEFT))
//	{
//		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
//		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
//		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;
//		if (KeyManager.IsKeyDown('A') && KeyManager.IsKeyDown(VK_SHIFT))
//		{
//			// ���̺� ��� ���ϱ�
//		}
//
//	}
//
//	if (KeyManager.IsKeyDown('D') || KeyManager.IsKeyDown(VK_RIGHT))
//	{
//		// �׳� ���� �ִϸ��̼� ���, ������ �̵�
//		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
//		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
//		if (KeyManager.IsKeyDown('D') && KeyManager.IsKeyDown(VK_SHIFT)) 
//		{
//			// ���̺� ��� ���ϱ�
//		}
//	}
//
//	// enter + ����Ű , shift + a,d => save ���
//}
//
//void DRun::Exit()
//{
//}
//
//void DRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
//{
//}
