#include "Object.h"

BitmapScene* Object::m_Object = nullptr;
Vector2F     Object::ob_velocity = { 0.0f,0.0f };

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
	// ���� ������Ʈ�� x ��ǥ >= �÷��̾� �ִϸ��̼� x��ǥ - �÷��̾� �ִϸ��̼� �ʺ��̸�,
	// �÷��̾� ����� x ��ǥ���� �۾����� ���ϰ� �ϱ�
	if (m_Object->m_RelativeLocation.x + 18 + SPlayer::SPlayerAni->m_DstRect.bottom * 0.5
		> SPlayer::SPlayerAni->m_RelativeLocation.x)
	{
		Debug.Log("m_Object->m_RelativeLocation.x: "
			+ std::to_string(SPlayer::SPlayerAni->m_RelativeLocation.x));
		SPlayer::SPlayerAni->m_RelativeLocation.x
			= m_Object->m_RelativeLocation.x + 18 + SPlayer::SPlayerAni->m_DstRect.bottom * 0.5;
	}

}

void Object::Render()
{
	__super::Render();
}