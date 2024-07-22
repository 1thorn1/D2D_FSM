#include "pch.h"
#include "AnimationAsset.h"
#include "ResourceManager.h"


bool AnimationAsset::LoadAnimation(std::wstring FilePath)
{
	//�ؽ�Ʈ ������ ��� csv���� ����� �о�´�.
	// �Ʒ� �Լ��� csv������ ó���Ѵ�.
	if (FilePath == std::wstring(L"CSV/midnight.txt"))
	{
		// ����� CSV ����
		LoadAnimationFromCSV(0, L"CSV/midnight.txt");
	}

	// �÷��̾��� CSV ����
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

	// ���� CSV ����
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

	// �����Q�� CSV ����
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
	return true;
}


bool AnimationAsset::LoadAnimationFromCSV(int index, const wchar_t* fileName)
{
	std::wifstream file(fileName);
	if (!file.is_open())
	{
		return false;
	}

	std::wstring line;	// �� ���� ���ڿ�
	int FrameCount = 0;	// �������� ����
	{
		std::getline(file, line);	// ù��° �� �б�
		std::wstringstream wss(line);
		wss >> FrameCount;
	}

	m_Animations.resize(15);
	m_Animations[index].Frames.resize(FrameCount);
	for (int i = 0; i < FrameCount; i++)
	{
		std::getline(file, line);	 // ù��° �� �б�
		std::wstringstream wss(line); // �� �� �о wstringstream�� ����
		std::wstring token;
		{
			getline(wss, token, L',');	// wss�� ������ ,�� �������� ���ڿ��� �и�
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
