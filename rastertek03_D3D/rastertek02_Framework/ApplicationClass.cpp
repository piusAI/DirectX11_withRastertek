#include "ApplicationClass.h"


bool ApplicationClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	m_Direct3D = new D3DClass;

	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L" D3D 초기화 불가!", L"에러", MB_OK);
	}
	return true;
	
}

void ApplicationClass::Shutdown()
{
	// D3D도 객체 해제
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}
	
}

bool ApplicationClass::Frame()
{
	bool result;

	result = Render();
	if (!result) return false;
	return true;
}

//물고 물어서 Render까지 내려옴
bool ApplicationClass::Render()
{
	//  Scene시작전에 Buffer 지우기
	m_Direct3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	m_Direct3D->EndScene();

	return true;
}