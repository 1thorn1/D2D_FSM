//#include "DRun.h"
//
//void DRun::Enter()
//{
//	AnimationScene* DRunAni;
//	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
//	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
//	DRunAni->SetAnimation(8, 0);
//	// FPlayer이면 반대 방향을 보게 바꾸지
//}
//
//void DRun::Update()
//{
//	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
//	// 플레이어의 콜라이더와 공의 콜라이더가 닿으면
//	// 중력과 탄성을 받아 공을 튀기기
//	if (KeyManager.IsKeyDown('W') || KeyManager.IsKeyDown(VK_UP))
//	{
//		// 점프 실행
//		fsm->SetCurState("Jump");
//
//		if (KeyManager.IsKeyDown('W') && KeyManager.IsKeyDown(VK_SHIFT))
//		{
//			// 세게 치기
//		}
//		if (KeyManager.IsKeyDown(VK_UP) && KeyManager.IsKeyDown(VK_RETURN))
//		{
//			// 세게 치기
//		}
//		
//	}
//	if (KeyManager.IsKeyDown('A') || KeyManager.IsKeyDown(VK_LEFT))
//	{
//		// 그냥 현재 애니메이션 재생, 앞으로 이동
//		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
//		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;
//		if (KeyManager.IsKeyDown('A') && KeyManager.IsKeyDown(VK_SHIFT))
//		{
//			// 세이브 모션 취하기
//		}
//
//	}
//
//	if (KeyManager.IsKeyDown('D') || KeyManager.IsKeyDown(VK_RIGHT))
//	{
//		// 그냥 현재 애니메이션 재생, 뒤으로 이동
//		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
//		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
//		if (KeyManager.IsKeyDown('D') && KeyManager.IsKeyDown(VK_SHIFT)) 
//		{
//			// 세이브 모션 취하기
//		}
//	}
//
//	// enter + 방향키 , shift + a,d => save 모션
//}
//
//void DRun::Exit()
//{
//}
//
//void DRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
//{
//}
