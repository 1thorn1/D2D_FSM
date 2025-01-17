#include "pch.h"
#include "Scene.h"

Scene::Scene()
{
	m_RelativeTransform = m_WorldTransform = D2D1::Matrix3x2F::Identity(); // 엥 이게 머야
}

Scene::~Scene()
{
}


void Scene::UpdateTransform()
{
	// 행렬 공식 -> 상대 복합 변환
	m_RelativeTransform =
		  D2D1::Matrix3x2F::Scale(D2D1::SizeF(m_RelativeScale.x, m_RelativeScale.y))
		* D2D1::Matrix3x2F::Rotation(m_RelativeRotation)
		* D2D1::Matrix3x2F::Translation(m_RelativeLocation.x, m_RelativeLocation.y);

	if (m_pParentScene != nullptr)
	{
		m_WorldTransform = m_RelativeTransform * m_pParentScene->m_WorldTransform;
	}
	else m_WorldTransform = m_RelativeTransform;
}

void Scene::Update()
{
	UpdateTransform();
}

void Scene::Render()
{
}