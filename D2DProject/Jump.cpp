#include "Jump.h"
#include "GameManager.h"

void Jump::Initialize()
{
	gravityScale = 300.f;
	jumpForce = 200.f;
	velocity = 0.0f;
	isJumping = false;
}

void Jump::Enter()
{
	velocity = -1.5 * jumpForce;
	isJumping = false;

	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/Jump.txt");
	DRunAni->SetAnimation(2, 0);
}

void Jump::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// jump �ִϸ��̼� ���� ��� -> ���� ������ �� ����
	// ���� �ִϸ��̼��� ������ idle or jump ���·� ����
	// ���� �ݶ��̴��� �÷��̾��� �ݶ��̴��� ������ Attack ������� ����
	float speed = 200.0f;
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			fsm->SetCurState("PAttack"); // �߷��� ��� �޾Ƽ� ������ �ؾ��� -> ���� �ʿ�
		}
		if (KeyManager.IsKeyDown(owner->input.right))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1 * speed * TimeManager::GetDeltaTime();
		}
		if (KeyManager.IsKeyDown(owner->input.left))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1 * speed * TimeManager::GetDeltaTime();
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
		if (KeyManager.IsKeyDown(owner->input.right))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		}
		if (KeyManager.IsKeyDown(owner->input.left))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		}
	}

}

void Jump::Exit()
{
}

void Jump::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
