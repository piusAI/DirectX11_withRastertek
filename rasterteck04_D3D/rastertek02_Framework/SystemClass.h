#pragma once //요즘 쓰는거

#include <windows.h>
#include "InputClass.h"
#include "ApplicationClass.h"


class SystemClass
{
public:
	explicit SystemClass() : m_Input(0), m_Application(0){}
	SystemClass(const SystemClass&) {}
	~SystemClass() {}

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;
	InputClass* m_Input;
	ApplicationClass* m_Application;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static SystemClass* ApplicationHandle = 0;

