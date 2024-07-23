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
	// jump �ִϸ��̼� ���� ��� -> ���� ������ �� ����
	// ���� �ִϸ��̼��� ������ idle or jump ���·� ����
	// ���� �ݶ��̴��� �÷��̾��� �ݶ��̴��� ������ Attack ������� ����
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
	owner->m_pRootScene->m_RelativeLocation.y += velocity * deltaTime; // �̰� ���� ���� ���� �Ŵ� �� �ȵ���??

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
