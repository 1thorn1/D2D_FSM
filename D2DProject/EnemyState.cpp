//#include "EnemyState.h"
//
//void EnemyState::Initialize()
//{
//	// �ִϸ��̼� ũ���� �ڽ� �ݶ��̴� �����
//	D2D_SIZE_F size = m_pBitmap->GetSize();
//
//	m_pOwner->GetOwner()->m_BoundBox.m_Extend.x = size.width * 0.5f;
//	m_pOwner->GetOwner()->m_BoundBox.m_Extend.y = size.height * 0.5f;
//
//	// �簢�� �׸���
//	D2D1_RECT_F rectangle = D2D1::RectF(
//		0.0f, 0.0f,
//		m_pOwner->GetOwner()->m_BoundBox.m_Extend.x, m_pOwner->GetOwner()->m_BoundBox.m_Extend.y
//	);
//
//	D2DRender::GetRenderTarget()->BeginDraw();
//	D2DRender::GetRenderTarget()->DrawRectangle(&rectangle, D2DRender::GetID2D1SolidColorBrush());
//	D2DRender::GetRenderTarget()->EndDraw();
//}
//
//void EnemyState::Update()
//{
//}
//
//void EnemyState::IdleState()
//{
//	// �⺻����. �÷��̾ �ִ� �ݶ��̴��� ������ ������ �� ���¸� ����
//}
//
//
//void EnemyState::AttackState()
//{
//	// �߰� �ڽ� �ݶ��̴� ������ ������ �� ���¸� ����
//}
//
//
//void EnemyState::FollowState()
//{
//	// �ִ� �ڽ� �ݶ��̴� ������ ������ �� ���¸� ����
//}
