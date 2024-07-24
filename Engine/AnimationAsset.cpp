#include "pch.h"
#include "AnimationAsset.h"
#include "ResourceManager.h"


bool AnimationAsset::LoadAnimation(std::wstring FilePath)
{
	//텍스트 파일을 열어서 csv파일 목록을 읽어온다.
	// 아래 함수로 csv파일을 처리한다.
	if (FilePath == std::wstring(L"CSV/midnight.txt"))
	{
		// 배경의 CSV 열기
		LoadAnimationFromCSV(0, L"CSV/midnight.txt");
	}

	// 플레이어의 CSV 열기
	if (FilePath == std::wstring(L"CSV/KenIdle.txt"))
	{
		LoadAnimationFromCSV(1, L"CSV/KenIdle.txt");
	}
	if (FilePath == std::wstring(L"CSV/KenAttack.txt"))
	{
		LoadAnimationFromCSV(2, L"CSV/KenAttack.txt");
	}
	if (FilePath == std::wstring(L"CSV/KenMove.txt"))
	{
		LoadAnimationFromCSV(3, L"CSV/KenMove.txt");
	}

	// 적의 CSV 열기
	if (FilePath == std::wstring(L"CSV/EIdle.txt"))
	{
		LoadAnimationFromCSV(4, L"CSV/EIdle.txt");
	}
	if (FilePath == std::wstring(L"CSV/EAttack.txt"))
	{
		LoadAnimationFromCSV(5, L"CSV/EAttack.txt");
	}
	if (FilePath == std::wstring(L"CSV/EMove.txt"))
	{
		LoadAnimationFromCSV(6, L"CSV/EMove.txt");
	}

	// 삒껫쯖의 CSV 열기
	if (FilePath == std::wstring(L"CSV/Attack.txt"))
	{
		LoadAnimationFromCSV(7, L"CSV/Attack.txt");
	}
	if (FilePath == std::wstring(L"CSV/DRun.txt"))
	{
		LoadAnimationFromCSV(8, L"CSV/DRun.txt");
	}
	if (FilePath == std::wstring(L"CSV/Jump.txt"))
	{
		LoadAnimationFromCSV(9, L"CSV/Jump.txt");
	}
	if (FilePath == std::wstring(L"CSV/Idle.txt"))
	{
		LoadAnimationFromCSV(10, L"CSV/Idle.txt");
	}

	if (FilePath == std::wstring(L"CSV/flag.txt"))
	{
		LoadAnimationFromCSV(11, L"CSV/flag.txt");
	}
	if (FilePath == std::wstring(L"CSV/DBall.txt"))
	{
		LoadAnimationFromCSV(12, L"CSV/DBall.txt");
	}
	return true;
}


bool AnimationAsset::LoadAnimationFromCSV(int index, const wchar_t* fileName)
{
	std::wifstream file(fileName);
	if (!file.is_open())
	{
		return false;
	}

	std::wstring line;	// 한 줄의 문자열
	int FrameCount = 0;	// 프레임의 개수
	{
		std::getline(file, line);	// 첫번째 줄 읽기
		std::wstringstream wss(line);
		wss >> FrameCount;
	}

	m_Animations.resize(15);
	m_Animations[index].Frames.resize(FrameCount);
	for (int i = 0; i < FrameCount; i++)
	{
		std::getline(file, line);	 // 첫번째 줄 읽기
		std::wstringstream wss(line); // 한 줄 읽어서 wstringstream에 저장
		std::wstring token;
		{
			getline(wss, token, L',');	// wss의 내용을 ,를 기준으로 문자열을 분리
			m_Animations[index].Frames[i].Source.left = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.top = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.right = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.bottom = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Center.x = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Center.y = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Duration = _wtof(token.c_str());
		}
	}
}
