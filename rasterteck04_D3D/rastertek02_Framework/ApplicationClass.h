#pragma once
#include <Windows.h>
#include "D3DClass.h"
#include "CameraClass.h"
#include "ModelClass.h"
#include "ColorShaderClass.h"

// 시스템 클래스에서 생성되는 또 다른 객체임
// 모든 app 그래픽 기능 여기 클래스에 캡슐화!
// 향후 모든 그래픽 객체 포함할거임!

//////////////
// 전역 변수 //
// ///////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 100.f;
const float SCREEN_NEAR = 0.3f;

class ApplicationClass
{
	public:
		ApplicationClass() : m_Direct3D(0), m_Camera(0),
							m_Model(0), m_ColorShader(0){}
		ApplicationClass(const ApplicationClass&):m_Direct3D(0) {}
		~ApplicationClass() {}

		bool Initialize(int, int, HWND);
		void Shutdown();
		bool Frame();

private:
		bool Render();

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	ModelClass* m_Model;
	ColorShaderClass* m_ColorShader;
};

