#include "IdleState.h"

void IdleState::Enter()
{
	player.SetAnimationFilePath(L"CSV/Run.txt");
}

void IdleState::Update()
{
	// 특정 키 눌렀을 때 특정 Idle 스프라이트가 작동하게끔
	// 플레이어 애니메이션의 루트 씬인 걸 알았으면 좋겠는데 어캐 알게 하지 ㅇㅅㅇㅠ
	//if (KeyManager.IsKeyDown('W'))
	//{
	//	m_pRootScene->m_RelativeLocation.y -= 1;
	//}
	//if (KeyManager.IsKeyDown('A'))
	//{
	//	m_pRootScene->m_RelativeLocation.x -= 1;
	//}
	//if (KeyManager.IsKeyDown('S'))
	//{
	//	m_pRootScene->m_RelativeLocation.y += 1;
	//}
	//if (KeyManager.IsKeyDown('D'))
	//{
	//	m_pRootScene->m_RelativeLocation.x += 1;
	//}
}

void IdleState::Exit()
{
	// 동작을 끝내고 다음 동작이 이어질 수 있게 만듦
}
