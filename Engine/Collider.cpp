#include "pch.h"
#include "Collider.h"

void Collider_BTOB::Initialize()
{
}

void Collider_BTOB::Update()
{
	// 바운드 박스가 충돌하면 -> 움직이지 못하고 멈추게
	// 이걸 보고 생각해보자... 게임오브젝트의 바운드 박스와 게임오브젝트의 바운드 박스..
	// 내가 아닌 게임오브젝트의 바운드 박스라고 생각할까?
	//if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	//{
	//	fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 0;
	//}

	// 얘도 한 번 보고 확인해보자
	//for (GameObject*& obj : m_GameObjects)
	//{
	//	if (obj == mainCamera) continue; // 카메라는 카운트 하지 않는다
	//	if (mainCamera->m_BoundBox.CheckIntersect(obj->m_BoundBox)) // 카메라 바운드 박스와 다른 오브젝트의 바운드 박스가 겹치는지 체크
	//	{
	//		obj->Render();
	//		count++;
	//	}
	//}
	
	// 바운드 박스를 가진게 플레이어, 땅... 
	// 헐 생각해보니까 콜라이더 각 벽마다 다 따로 만들어야함
	// 플레이어 2, 땅, 옆 벽 2, 하늘 1, 중간 벽 1
	
	//Debug.Log("하...");

}

void Collider_BTOC::Initialize()
{
}

void Collider_BTOC::Update()
{
}
