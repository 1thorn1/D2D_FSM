#include "Enemy.h"
#include "EIdleState.h"
#include "EMoveState.h"
#include "EAttackState.h"

Enemy::Enemy()
{
	EnemyAni = GameObject::CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/Enemy.png", &EnemyAni->m_pBitmap);
	//EnemyAni->m_RelativeLocation = { 300 ,200 };
	Initialize(300, 200, 0.2f);
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


void Enemy::Initialize(float x, float y, float speed)
{
	EnemyAni->m_RelativeLocation.x = x;
	EnemyAni->m_RelativeLocation.y = y;
	m_speed = speed;
}

void Enemy::Update()
{
	__super::Update();
	 // 바운드 박스를 초기화 해줄 것 ㅠㅠ
	BmidRect.m_Center = m_pRootScene->GetWorldLocation();
	BmaxRect.m_Center = m_pRootScene->GetWorldLocation();
	BmidRect.m_Extend = { m_BoundBox.m_Extend.x + 10, m_BoundBox.m_Extend.y + 10 };
	BmaxRect.m_Extend = { m_BoundBox.m_Extend.x + 300, m_BoundBox.m_Extend.y + 300 };
}

void Enemy::Render()
{
	__super::Render();

	D2D1_SIZE_F center = D2D1::SizeF((EnemyAni->m_SrcRect.right - EnemyAni->m_SrcRect.left) / 2, (EnemyAni->m_SrcRect.bottom - EnemyAni->m_SrcRect.top) / 2);
	D2DRender::GetRenderTarget()->SetTransform(
		// 중심축을 기준으로 행렬연산을 하기 위해 중심축을 먼저 옮겨줌
		D2D1::Matrix3x2F::Translation(-center.width, -center.height) *
		// 이미지의 행렬(지금은 Scale만 있음)과 Scene의 행렬을 연산
		EnemyAni->m_ImageTransform * EnemyAni->m_WorldTransform
		// 카메라의 역행렬
		* dynamic_cast<CameraScene*>(m_pOwner->mainCamera->m_pRootScene)->m_CameraMatrix); //-> 카메라 중심 기준으로 월드 좌표

	// 에너미의 박스 콜라이더 or 애니메이션 사이즈를 가져와서 크기를 키우자 
	// +  그 크기만큼의 콜라이더를 만들어주기
	D2D1_RECT_F midRect = D2D1::RectF(-10, -10, EnemyAni->m_DstRect.right + 10, EnemyAni->m_DstRect.bottom + 10);
	D2D1_RECT_F maxRect = D2D1::RectF(-300, -300, EnemyAni->m_DstRect.right + 300, EnemyAni->m_DstRect.bottom + 300);
	
	//D2DRender::GetRenderTarget()->DrawRectangle(&midRect, D2DRender::GetID2D1SolidColorBrush());
	//D2DRender::GetRenderTarget()->DrawRectangle(&maxRect, D2DRender::GetID2D1SolidColorBrush());

	D2DRender::GetRenderTarget()->SetTransform(D2D1::IdentityMatrix());

}
