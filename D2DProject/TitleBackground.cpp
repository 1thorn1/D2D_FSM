#include "TitleBackground.h"

TitleBackground::TitleBackground()
{
	m_titlebackground = GameObject::CreateComponent<BitmapScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/title.bmp", &(m_titlebackground->m_pBitmap));
	//m_titlebackground->m_RelativeScale = { 1.65f,1.3f };
}

TitleBackground::~TitleBackground()
{
}

void TitleBackground::Intialize()
{
}

void TitleBackground::Update()
{
	__super::Update();
}

void TitleBackground::Render()
{
	__super::Render();
}
