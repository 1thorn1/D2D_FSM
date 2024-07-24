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
	//velocity = -boundForce;
	isBound = false;
	Initialize();
}

VBall::~VBall()
{
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
	velocity.y += gravityScale * time;
	m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation += velocity * TimeManager::GetDeltaTime();


		// Áß·Â¹Þ¾Æ¼­ ¶³¾îÁü
	//m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation += ;
	
	// Æ¨°Ü¼­ ¹Ù´Ú¿¡ ´ê¾ÒÀ» ¶§ÀÇ ¹Ý»çº¤ÅÍ ±¸ÇØÁÖ±â
	if (m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation.y >= 500)
	{
		velocity.y *= -1.f;
	}
}

void VBall::Render()
{
	__super::Render();
}
