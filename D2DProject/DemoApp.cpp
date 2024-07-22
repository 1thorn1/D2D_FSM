#include "DemoApp.h"
#include "Player.h"
#include "Enemy.h"
#include "FPlayer.h"
#include "SPlayer.h"

Player* DemoApp::m_pPlayer = nullptr;

void DemoApp::Initialize(HINSTANCE hInstance)
{
	__super::Initialize(hInstance);

	// 카메라 생성.
	GameObject* clone;
	clone = tempWorld.CreateGameObject<GameObject>();
	clone->m_pRootScene = clone->CreateComponent<CameraScene>();
	tempWorld.mainCamera = clone; // 메인카메라 설정 잊지말기!

	//백그라운드 생성 -> 함수로 만들겠음
	clone = tempWorld.CreateGameObject<GameObject>();
	AnimationScene* Background = clone->CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/midnight.png", &Background->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(L"CSV/midnight.txt", &Background->m_pAnimationAsset);
	Background->SetAnimation(0, 0);
	clone->m_pRootScene = Background;


	// 새로운 백그라운드
	clone = tempWorld.CreateGameObject<GameObject>();
	BitmapScene* Background1 = clone->CreateComponent<BitmapScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/background.bmp", &(Background1->m_pBitmap));
	Background1->m_RelativeLocation = { 510,300 };
	Background1->m_RelativeScale = { 1.65f,1.3f };

	// 삒깿쯖을 생성
	//clone = tempWorld.CreateGameObject<GameObject>();
	//AnimationScene* Background2 = clone->CreateComponent<AnimationScene>();
	//ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/realpikachuuu.png", &Background2->m_pBitmap);
	//ResourceManager::pInstance->CreateAnimationAsset(L"CSV/DRun.txt", &Background2->m_pAnimationAsset);
	//Background2->SetAnimation(8, 0);
	//Background2->m_RelativeScale = { 2.2f,2.2f };
	//clone->m_pRootScene = Background2;

	// 상대 삒깾쯖을 만들어
	//clone = tempWorld.CreateGameObject<GameObject>();
	//AnimationScene* Background3 = clone->CreateComponent<AnimationScene>();
	//ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/realpikachuuu.png", &Background3->m_pBitmap);
	//ResourceManager::pInstance->CreateAnimationAsset(L"CSV/DRun.txt", &Background3->m_pAnimationAsset);
	//Background3->SetAnimation(8, 1);
	//Background3->m_RelativeLocation = {-600,0};
	//Background3->m_RelativeScale = { 2.2f,2.2f };
	//clone->m_pRootScene = Background3;

	// 배구공도 ㅇㅅㅇ
	//clone = tempWorld.CreateGameObject<GameObject>();
	//AnimationScene* Background4 = clone->CreateComponent<AnimationScene>();
	//ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/Vball.png", &Background4->m_pBitmap);
	//ResourceManager::pInstance->CreateAnimationAsset(L"CSV/DBall.txt", &Background4->m_pAnimationAsset);
	//Background4->SetAnimation(10, 0);
	//Background4->m_RelativeLocation = { -500,0 };
	//Background4->m_RelativeScale = { 1.3f,1.3f };
	//clone->m_pRootScene = Background4;

	// 중간 콜라이더?
	//clone = tempWorld.CreateGameObject<GameObject>();
	//BitmapScene* Background5 = clone->CreateComponent<BitmapScene>();
	//ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/nashigoraeng.png", &(Background5->m_pBitmap));
	//Background5->m_RelativeLocation = { 512,400 };
	//Background5->m_RelativeScale = { 0.525f, 0.525f };


	clone = tempWorld.CreateGameObject<FPlayer>();
	clone = tempWorld.CreateGameObject<SPlayer>();

	// 적 생성
	clone = tempWorld.CreateGameObject<Enemy>();
	
	// 플레이어 생성
	m_pPlayer = tempWorld.CreateGameObject<Player>();
}

void DemoApp::CheckKeyInput()
{
	InputManager KeyManager;

	//if (KeyManager.IsKeyDown(VK_LEFT))
	//{
	//	tempWorld.mainCamera->m_pRootScene->m_RelativeLocation.x -= 1;
	//}
	//if (KeyManager.IsKeyDown(VK_RIGHT))
	//{
	//	tempWorld.mainCamera->m_pRootScene->m_RelativeLocation.x += 1;
	//}
}

void DemoApp::PrintUsedVRAM()
{
	D2DRender::GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	D2D1_RECT_F rect1 = { 0,0, 100,100 };
	std::wstring Vram = L"VRAM CHECK: " + std::to_wstring(D2DRender::GetUsedVRAM());
	D2DRender::GetRenderTarget()->DrawTextW(Vram.c_str(), static_cast<UINT32>(Vram.size()), D2DRender::GetIDWriteTextFormat(), rect1, D2DRender::GetID2D1SolidColorBrush());

	D2D1_RECT_F rect2 = { 0,50, 150,300 };
	std::wstring key = L"Create : C key, Release: R key, Reverse: <- key";
	D2DRender::GetRenderTarget()->DrawTextW(key.c_str(), static_cast<UINT32>(key.size()), D2DRender::GetIDWriteTextFormat(), rect2, D2DRender::GetID2D1SolidColorBrush());

	rect2 = { 0,150, 250,400 };
	key = L"Object count : " + std::to_wstring(tempWorld.count);
	D2DRender::GetRenderTarget()->DrawTextW(key.c_str(), static_cast<UINT32>(key.size()), D2DRender::GetIDWriteTextFormat(), rect2, D2DRender::GetID2D1SolidColorBrush());
}


void DemoApp::FixedUpdate()
{

}

void DemoApp::Update()
{
	CheckKeyInput();
	tempWorld.Update();
}


void DemoApp::Render()
{
	D2DRender::GetRenderTarget()->BeginDraw();
	D2DRender::GetRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	tempWorld.Render();
	//PrintUsedVRAM();
	D2DRender::GetRenderTarget()->EndDraw();
}
