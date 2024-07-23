#include "Jump.h"

void Jump::Initialize()
{
	this->gravityScale = 150.f;
	this->jumpForce = 200.f;
	this->position = 0.0f;
	this->velocity = 0.0f;
	this->isJumping = false;
}

void Jump::Enter()
{
	position = 0.0f;
	velocity = -jumpForce;
	isJumping = false;

	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/Jump.txt");
	DRunAni->SetAnimation(9, 0);
}

void Jump::Update()
{
	float deltaTime = timeManager.GetDeltaTime();

	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// jump 애니메이션 지속 재생 -> 땅에 떨어질 때 까지
	// 점프 애니메이션이 끝나면 idle or jump 상태로 변경
	// 공의 콜라이더와 플레이어의 콜라이더가 닿으면 Attack 모션으로 변경
	//if (KeyManager.IsKeyDown(VK_UP) && position == 0.0f)
	//{
	//	isJumping = true;
	//	if (KeyManager.IsKeyDown(VK_RETURN))
	//	{
	//		fsm->SetCurState("PAttack");
	//	}
	//}

	//if (isJumping)
	//{
	//	velocity = -jumpForce;
	//	isJumping = false;
	//}

	velocity += gravityScale * deltaTime;
	owner->m_pRootScene->m_RelativeLocation.y += velocity * deltaTime; // 이거 변수 만들어서 쓰는 거는 왜 안되지??

	/*if (KeyManager.IsKeyUp(VK_UP) && owner->m_pRootScene->m_RelativeLocation.y == 0)
	{
		fsm->SetCurState("PIdle");
	}*/
	//if (position < 0.0f)
	//{
	//	position = 0.0f;
	//	velocity = 0.0f;
	//}

}

void Jump::Exit()
{
}

void Jump::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
