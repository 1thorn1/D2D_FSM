#pragma once
#include "Component.h"

class FSMState;

class FiniteStateMachine
	: public Component
{
	FSMState* m_pCurrState = nullptr;			 // 현재 상태
	FSMState* m_pPreState = nullptr;			 // 이전 상태
	std::map<std::string, FSMState*> m_pStates;  // 생성된 FSMState 저장하기
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void Update();

	void SetCurState(std::string stateName);

	template<typename T>
	void CreateState(const std::string StateName)
	{
		T* pState = new T(this, StateName);
		pState->Initialize();
		m_pStates.insert(std::make_pair(pState->GetName(), pState));
	}
};