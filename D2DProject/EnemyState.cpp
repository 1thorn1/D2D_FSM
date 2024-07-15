//#include "EnemyState.h"
//
//void EnemyState::Initialize()
//{
//	// 애니매이션 크기의 박스 콜라이더 만들기
//	D2D_SIZE_F size = m_pBitmap->GetSize();
//
//	m_pOwner->GetOwner()->m_BoundBox.m_Extend.x = size.width * 0.5f;
//	m_pOwner->GetOwner()->m_BoundBox.m_Extend.y = size.height * 0.5f;
//
//	// 사각형 그리기
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
//	// 기본상태. 플레이어가 최대 콜라이더로 들어오지 않으면 이 상태를 유지
//}
//
//
//void EnemyState::AttackState()
//{
//	// 중간 박스 콜라이더 범위로 들어오면 이 상태를 실행
//}
//
//
//void EnemyState::FollowState()
//{
//	// 최대 박스 콜라이더 범위로 들어오면 이 상태를 실행
//}
