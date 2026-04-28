#include "InputClass.h"


void InputClass::Initialize()
{
	int i;


	//모든 키 눌리지 않은 상태로 초기화!
	// 윈도우의 Virtual Key code가 0~255범위임
	for (int i = 0; i < 256; i++)
	{
		m_keys[i] = false;
	}
	return;
}

void InputClass::KeyUp(unsigned int input)
{
	//해당키 키배열에 저장
	m_keys[input] = true;
	return;
}

void InputClass::KeyDown(unsigned int input)
{
	// release처럼 떼면 해당 상태 지우기
	m_keys[input] = false;
	return;
}

bool InputClass::IsKeyDown(unsigned int key)
{
	// 눌렸는지 상태 return
	return m_keys[key];
}

