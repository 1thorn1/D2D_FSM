#include "IdleState.h"

void IdleState::Enter()
{
	player.SetAnimationFilePath(L"CSV/Run.txt");
}

void IdleState::Update()
{
	// Ư�� Ű ������ �� Ư�� Idle ��������Ʈ�� �۵��ϰԲ�
	// �÷��̾� �ִϸ��̼��� ��Ʈ ���� �� �˾����� ���ڴµ� ��ĳ �˰� ���� ��������
	//if (KeyManager.IsKeyDown('W'))
	//{
	//	m_pRootScene->m_RelativeLocation.y -= 1;
	//}
	//if (KeyManager.IsKeyDown('A'))
	//{
	//	m_pRootScene->m_RelativeLocation.x -= 1;
	//}
	//if (KeyManager.IsKeyDown('S'))
	//{
	//	m_pRootScene->m_RelativeLocation.y += 1;
	//}
	//if (KeyManager.IsKeyDown('D'))
	//{
	//	m_pRootScene->m_RelativeLocation.x += 1;
	//}
}

void IdleState::Exit()
{
	// ������ ������ ���� ������ �̾��� �� �ְ� ����
}
