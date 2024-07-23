#include "FDRun.h"

void FDRun::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
	DRunAni->SetAnimation(8, 1);
	// FPlayer이면 반대 방향을 보게 바꾸지
}

void FDRun::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// 플레이어의 콜라이더와 공의 콜라이더가 닿으면
	// 중력과 탄성을 받아 공을 튀기기
	//if (KeyManager.IsKeyDown('W'))
	//{
	//	// 점프 실행
	//	fsm->SetCurState("DJump");

	//	// 실행이 끝나고 착지하면 다시 FDRun으로 가게
	//	if (KeyManager.IsKeyDown(VK_SHIFT))
	//	{
	//		// 세게 치기
	//	}

	//}
	//if (KeyManager.IsKeyDown('A'))
	//{
	//	// 그냥 현재 애니메이션 재생, 앞으로 이동
	//	fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
	//	m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;
	//	if ( KeyManager.IsKeyDown(VK_SHIFT))
	//	{
	//		// 세이브 모션 취하기
	//	}
	//}

	//if (KeyManager.IsKeyDown('D'))
	//{
	//	// 그냥 현재 애니메이션 재생, 뒤으로 이동
	//	fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
	//	m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
	//	if (KeyManager.IsKeyDown(VK_SHIFT))
	//	{
	//		// 세이브 모션 취하기
	//	}
	//}

	// enter + 방향키 , shift + a,d => save 모션
}

void FDRun::Exit()
{
}

void FDRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
