#include "VBall.h"

AnimationScene* VBall::m_Ball = nullptr;

VBall::VBall()
{
	m_Ball = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/Vball.png", &m_Ball->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(L"CSV/DBall.txt", &m_Ball->m_pAnimationAsset);
	SetRootScene(m_Ball);
	m_Ball->SetAnimation(12, 0);
	m_Ball->m_RelativeLocation = { 512 + 200, 600 - 200 };
	m_Ball->m_RelativeScale = { 1.8f,1.8f };

	position = 0.0f;
	isBound = false;
	Initialize();
}

VBall::~VBall()
{
}

bool VBall::CheckCollision()
{
	Vector2F diff = m_Ball->m_RelativeLocation - SPlayer::SPlayerAni->m_RelativeLocation;
	float distance = diff.length();
	return distance < (m_Ball->m_DstRect.bottom * 0.5 + SPlayer::SPlayerAni->m_DstRect.bottom * 0.5);
}

void VBall::ResolveCollision()
{
	// ���⺤�� ����ȭ
	Vector2F CollisionNormal = (m_Ball->m_RelativeLocation - SPlayer::SPlayerAni->m_RelativeLocation).normalize();
	// �����ϱ�?
	Vector2F RelativeVelocity = vb_velocity - SPlayer::sp_velocity;

	float VelocityAlongNormal = RelativeVelocity.dot(CollisionNormal);

	if (VelocityAlongNormal > 0)
	{
		return;
	}

	// �ݻ�����׿�?
	float e = 1.3f; 
	
	float j = -(1 + e) * VelocityAlongNormal; // �ݻ��� ����
	// �ݻ��� ����
	//j /= (1 / (m_Ball->m_DstRect.bottom * 0.5) + 1 / (SPlayer::SPlayerAni->m_DstRect.bottom * 0.5));

	Vector2F impulse = CollisionNormal * j;
	vb_velocity += impulse * (1 / (m_Ball->m_DstRect.bottom * 0.5));
	SPlayer::sp_velocity += impulse * (1 / (SPlayer::SPlayerAni->m_DstRect.bottom * 0.5));
}

void VBall::Initialize()
{
	this->gravityScale = 200.f;
	this->boundForce = 200.f;
	//this->velocity = 100.0f;
	this->isBound = false;
}

void VBall::Update()
{
	__super::Update();
	float time = TimeManager::GetDeltaTime();

	vb_velocity.y += gravityScale * time;
	m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation += vb_velocity * time;

	// ���� ���� �־��...

// ƨ�ܼ� �ٴڿ� ����� ���� �ݻ纤�� �����ֱ�
	if (m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation.y >= 500)
	{
		//vb_velocity.x = -vb_velocity.x * 0.8f;
		vb_velocity.y *= -0.8f;
	}
	if (m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation.x <= Object::m_Object->m_RelativeLocation.x + 18
	 || m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation.y < Object::m_Object->m_RelativeLocation.y)
	{
		ResolveCollision();
	}

	if (CheckCollision()) { ResolveCollision(); }


}

void VBall::Render()
{
	__super::Render();
}
