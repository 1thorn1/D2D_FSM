#pragma once

class FiniteStateMachine;

class FSMState //interface
{
public:
	FSMState(FiniteStateMachine* pOwner, std::string Name)
		:m_pOwner(pOwner)
		, m_Name(Name)
	{}
	~FSMState() {}

	std::string m_Name;
	FiniteStateMachine* m_pOwner;

public:
	void SetOwner(FiniteStateMachine* pOwner) { m_pOwner = pOwner; }
	const std::string& GetName() { return m_Name; }

	virtual void Initialize() {}
	virtual void Enter()  = 0;	// �� ����� �ְ� ������ �ʰ� �ϻ�
	virtual void Update() = 0;
	virtual void Exit()   = 0;
};