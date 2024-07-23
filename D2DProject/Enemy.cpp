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
	 // �ٿ�� �ڽ��� �ʱ�ȭ ���� �� �Ф�
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
		// �߽����� �������� ��Ŀ����� �ϱ� ���� �߽����� ���� �Ű���
		D2D1::Matrix3x2F::Translation(-center.width, -center.height) *
		// �̹����� ���(������ Scale�� ����)�� Scene�� ����� ����
		EnemyAni->m_ImageTransform * EnemyAni->m_WorldTransform
		// ī�޶��� �����
		* dynamic_cast<CameraScene*>(m_pOwner->mainCamera->m_pRootScene)->m_CameraMatrix); //-> ī�޶� �߽� �������� ���� ��ǥ

	// ���ʹ��� �ڽ� �ݶ��̴� or �ִϸ��̼� ����� �����ͼ� ũ�⸦ Ű���� 
	// +  �� ũ�⸸ŭ�� �ݶ��̴��� ������ֱ�
	D2D1_RECT_F midRect = D2D1::RectF(-10, -10, EnemyAni->m_DstRect.right + 10, EnemyAni->m_DstRect.bottom + 10);
	D2D1_RECT_F maxRect = D2D1::RectF(-300, -300, EnemyAni->m_DstRect.right + 300, EnemyAni->m_DstRect.bottom + 300);
	
	//D2DRender::GetRenderTarget()->DrawRectangle(&midRect, D2DRender::GetID2D1SolidColorBrush());
	//D2DRender::GetRenderTarget()->DrawRectangle(&maxRect, D2DRender::GetID2D1SolidColorBrush());

	D2DRender::GetRenderTarget()->SetTransform(D2D1::IdentityMatrix());

}
