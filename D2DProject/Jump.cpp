#include "Jump.h"
#include "GameManager.h"

void Jump::Initialize()
{
	this->gravityScale = 200.f;
	this->jumpForce = 200.f;
	this->velocity = 0.0f;
	this->isJumping = false;
}

void Jump::Enter()
{
	velocity = -jumpForce;
	isJumping = false;

	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/Jump.txt");
	DRunAni->SetAnimation(2, 0);
}

void Jump::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// jump 애니메이션 지속 재생 -> 땅에 떨어질 때 까지
	// 점프 애니메이션이 끝나면 idle or jump 상태로 변경
	// 공의 콜라이더와 플레이어의 콜라이더가 닿으면 Attack 모션으로 변경
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			fsm->SetCurState("PAttack"); // 중력을 계속 받아서 점프를 해야함 -> 수정 필요
		}
		if (KeyManager.IsKeyDown(owner->input.right))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		}
		if (KeyManager.IsKeyDown(owner->input.left))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		}
	}
	velocity += gravityScale * TimeManager::GetDeltaTime();
	owner->m_pRootScene->m_RelativeLocation.y += velocity * TimeManager::GetDeltaTime(); // 이거 변수 만들어서 쓰는 거는 왜 안되지??
	if (owner->m_pRootScene->m_RelativeLocation.y >= 500)
	{
		owner->m_pRootScene->m_RelativeLocation.y = 500;
		fsm->SetCurState("PIdle");
		Debug.Log("맞음");
	}
	else
	{
		Debug.Log("틀림");
	}

}

void Jump::Exit()
{
}

void Jump::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
