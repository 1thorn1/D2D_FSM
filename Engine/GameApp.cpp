#include "pch.h"
#include "GameApp.h"

// 윈도우 창 띄우기,
// 메세지 루프 돌리기
void GameApp::Initialize(HINSTANCE hInstance)
{
	m_hInstance = hInstance;

	InitWindow();
	D2DRender::InitDirect2D(m_hWnd);
}

HWND GameApp::InitWindow()
{
    const TCHAR* appName = TEXT("디투디 연습을 게을리하지 말 것");

    // Step 1: Registering the Window Class
    WNDCLASS wndClass;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = appName;
    RegisterClass(&wndClass);

    // Step 2: Creating the Window
    RECT rect{ 0, 0, 1024, 600 };
    ::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    // Get the dimensions of the primary monitor
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Calculate the position for centering the window
    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;

    m_hWnd = CreateWindow(appName, appName, WS_OVERLAPPED | WS_SYSMENU,
        posX, posY, windowWidth, windowHeight, NULL, NULL, m_hInstance, NULL);

    ShowWindow(m_hWnd, SW_SHOWNORMAL);
    UpdateWindow(m_hWnd);

    return m_hWnd;
}


void GameApp::FixedUpdate()
{
	
}

void GameApp::Update()
{
	
}


void GameApp::Run()
{
    MSG msg;

    // 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Update();
			Render();
		}
	}
}
void GameApp::Render()
{
}

void GameApp::Uninitialize()
{
}

LRESULT GameApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
