#include "Enemy.h"
#include "EIdleState.h"
#include "EMoveState.h"
#include "EAttackState.h"

Enemy::Enemy()
{
	EnemyAni = GameObject::CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/Enemy.png", &EnemyAni->m_pBitmap);
	EnemyAni->m_RelativeLocation = { 400 ,200 };
	SetRootScene(EnemyAni);

	fsm = CreateComponent<FiniteStateMachine>();
	fsm->CreateState<EIdleState>("EIdle");
	fsm->CreateState<EMoveState>("EMove");
	fsm->CreateState<EAttackState>("EAttack");
	fsm->SetCurState("EIdle");
}

Enemy::~Enemy()
{
}


void Enemy::Initialize()
{
}

void Enemy::Update()
{
	__super::Update();

}

void Enemy::Render()
{
	__super::Render();
	// 에너미의 박스 콜라이더 생성
	D2D_SIZE_F size = EnemyAni->m_pBitmap->GetSize();
	m_BoundBox.m_Extend.x = size.width * 0.5f;
	m_BoundBox.m_Extend.y = size.height * 0.5f;

	// 사각형 그리기
	D2D1_RECT_F rectangle = D2D1::RectF(
		m_BoundBox.m_Center.x - m_BoundBox.m_Extend.x, m_BoundBox.m_Center.y - m_BoundBox.m_Extend.y,
		m_BoundBox.m_Center.x + m_BoundBox.m_Extend.x, m_BoundBox.m_Center.y + m_BoundBox.m_Extend.y
	);

	// 에너미의 박스 콜라이더 출력
	D2DRender::GetRenderTarget()->SetTransform(D2D1::IdentityMatrix());

	D2DRender::GetRenderTarget()->DrawRectangle(&rectangle, D2DRender::GetID2D1SolidColorBrush());
}
