#include "ApplicationClass.h"
#include <cstdio>



bool ApplicationClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	m_Direct3D = new D3DClass;
	char msg[128];
	sprintf_s(msg, "Width: %d Height: %d\n", screenWidth, screenHeight);
	OutputDebugStringA(msg);

	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L" D3D 초기화 불가!", L"에러", MB_OK);
		return false;
	}

	m_Camera = new CameraClass();

	m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

	m_Model = new ModelClass;
	result = m_Model->Initialize(m_Direct3D->GetDevice());

	if (!result)
	{
		MessageBox(hwnd, L"모델 초기화 불가", L"ERROR!", MB_OK);
		return false;
	}

	m_ColorShader = new ColorShaderClass();
	
	result = m_ColorShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Color Shader obj 초기화 불가", L"ERROR!", MB_OK);
		return false;
	}


	return true;
	
}

void ApplicationClass::Shutdown()
{

	if (m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}
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
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;

	m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	m_Camera->Render();

	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);

	m_Model->Render(m_Direct3D->GetDeviceContext());

	result = m_ColorShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix);

	if (!result) return false;
	//  Scene시작전에 Buffer 지우기
	//m_Direct3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	m_Direct3D->EndScene();

	return true;
}