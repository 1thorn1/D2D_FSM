#include "pch.h"
#include "Collider.h"

void Collider_BTOB::Initialize()
{
}

void Collider_BTOB::Update()
{
	// �ٿ�� �ڽ��� �浹�ϸ� -> �������� ���ϰ� ���߰�
	// �̰� ���� �����غ���... ���ӿ�����Ʈ�� �ٿ�� �ڽ��� ���ӿ�����Ʈ�� �ٿ�� �ڽ�..
	// ���� �ƴ� ���ӿ�����Ʈ�� �ٿ�� �ڽ���� �����ұ�?
	//if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	//{
	//	fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 0;
	//}

	// �굵 �� �� ���� Ȯ���غ���
	//for (GameObject*& obj : m_GameObjects)
	//{
	//	if (obj == mainCamera) continue; // ī�޶�� ī��Ʈ ���� �ʴ´�
	//	if (mainCamera->m_BoundBox.CheckIntersect(obj->m_BoundBox)) // ī�޶� �ٿ�� �ڽ��� �ٸ� ������Ʈ�� �ٿ�� �ڽ��� ��ġ���� üũ
	//	{
	//		obj->Render();
	//		count++;
	//	}
	//}
	
	// �ٿ�� �ڽ��� ������ �÷��̾�, ��... 
	// �� �����غ��ϱ� �ݶ��̴� �� ������ �� ���� ��������
	// �÷��̾� 2, ��, �� �� 2, �ϴ� 1, �߰� �� 1
	
	//Debug.Log("��...");

}

void Collider_BTOC::Initialize()
{
}

void Collider_BTOC::Update()
{
}
