#include "Jump.h"

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
	DRunAni->SetAnimation(9, 0);
}

void Jump::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// jump �ִϸ��̼� ���� ��� -> ���� ������ �� ����
	// ���� �ִϸ��̼��� ������ idle or jump ���·� ����
	// ���� �ݶ��̴��� �÷��̾��� �ݶ��̴��� ������ Attack ������� ����
	if (KeyManager.IsKeyDown(VK_UP))
	{
		if (KeyManager.IsKeyDown(VK_RETURN))
		{ 
			fsm->SetCurState("PAttack"); // �߷��� ��� �޾Ƽ� ������ �ؾ��� -> ���� �ʿ�
		}
		if (KeyManager.IsKeyDown(VK_RIGHT))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		}
		if (KeyManager.IsKeyDown(VK_LEFT))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		}
	}


	velocity += gravityScale * TimeManager::GetDeltaTime();
	owner->m_pRootScene->m_RelativeLocation.y += velocity * TimeManager::GetDeltaTime(); // �̰� ���� ���� ���� �Ŵ� �� �ȵ���??

	if (owner->m_pRootScene->m_RelativeLocation.y >= 500)
	{
		owner->m_pRootScene->m_RelativeLocation.y = 500;
		fsm->SetCurState("PIdle");
		Debug.Log("����");
	}
	else
	{
		Debug.Log("Ʋ��");
	}

}

void Jump::Exit()
{
}

void Jump::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
