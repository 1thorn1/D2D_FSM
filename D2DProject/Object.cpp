#include "Object.h"

Object::Object()
{
	m_Object = GameObject::CreateComponent<BitmapScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/Cflag.png", &m_Object->m_pBitmap);
	m_Object->m_RelativeLocation = { 512 - 9,300 };
	D2D_SIZE_F size = m_Object->GetBitmap()->GetSize();
	m_Object->GetOwner()->m_BoundBox.m_Extend = { size.width,size.height };
	SetRootScene(m_Object);
}

Object::~Object()
{
}

void Object::Initialize()
{
}

void Object::Update()
{
	__super::Update();
}

void Object::Render()
{
	__super::Render();
}
