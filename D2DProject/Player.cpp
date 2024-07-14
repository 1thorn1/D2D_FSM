#include "Player.h"

Player::Player(const std::wstring& animationFilePath)
{
	AnimationScene* m_pPlayer = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/run.png", &m_pPlayer->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(animationFilePath, &m_pPlayer->m_pAnimationAsset);
	m_pPlayer->SetAnimation(1, 0);
	m_pPlayer->m_RelativeLocation = { 200 ,200 };
	SetRootScene(m_pPlayer);
}

Player::~Player()
{
}

void Player::SetAnimationFilePath(const std::wstring& animationFilePath)
{
	ResourceManager::pInstance->CreateAnimationAsset(animationFilePath, &m_pPlayer->m_pAnimationAsset);
}

void Player::Update()
{
	__super::Update();
}
