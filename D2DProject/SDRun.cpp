#include "SDRun.h"

void SDRun::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
	DRunAni->SetAnimation(8, 0);
	// FPlayer이면 반대 방향을 보게 바꾸지
}

void SDRun::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// 플레이어의 콜라이더와 공의 콜라이더가 닿으면
	// 중력과 탄성을 받아 공을 튀기기
	if (KeyManager.IsKeyDown(VK_UP))
	{
		// 점프 실행
		fsm->SetCurState("DJump");
	}

	if (KeyManager.IsKeyHold(VK_LEFT))
	{
		// 그냥 현재 애니메이션 재생, 앞으로 이동
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;

		// 세이브 모션 취하기
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
		}
	}

	if (KeyManager.IsKeyHold(VK_RIGHT))
	{
		// 그냥 현재 애니메이션 재생, 뒤으로 이동
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			// 세이브 모션 취하기
		}
	}

	if (!KeyManager.IsKeyHold(VK_LEFT) && !KeyManager.IsKeyHold(VK_RIGHT))
	{
		fsm->SetCurState("PIdle");
	}
}

void SDRun::Exit()
{
}

void SDRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
