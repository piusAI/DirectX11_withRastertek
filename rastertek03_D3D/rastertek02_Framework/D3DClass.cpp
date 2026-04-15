#include "D3DClass.h"

D3DClass::D3DClass()
{
}

bool D3DClass::Initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen, float screenDepth, float screenNear)
{
	HRESULT result;
	IDXGIFactory* factory;
	IDXGIAdapter* adapter;
	IDXGIOutput* adapterOutput;
	unsigned int numModes, i, numerator, denominator;
	unsigned long long stringLength;
	DXGI_MODE_DESC* displayModeList;
	DXGI_ADAPTER_DESC adapterDesc;

	int error;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	D3D_FEATURE_LEVEL featureLevel;
	ID3D11Texture2D* backBufferPtr;
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;

	D3D11_RASTERIZER_DESC rasterDesc;
	float fieldOfView, screenAspect;

	//vsync 이 변수로 D3D가 유저 모니터 새로고침률에 맞춰 render 또는 최대한 빠르게 렌더할지 결정
	m_vsync_enabled = vsync;

	return false;

	// 컴퓨터마다 다른 새로고침률 정보 쿼리 및 계산
	// DX는 buffer flip대신 blit을 수행해서 성능 저하
	// DXGI : DX에서 그래픽카드, 어댑터, 출력장치 관리하는 레이어
	// Factory : 객체 만들어주는 관리자
	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	// DXGI 관리하는 factory 만들어서 factory 포인터에 넣음
	if (FAILED(result))
	{
		return false;
	}

	result = factory->EnumAdapters(0, &adapter);
	if (FAILED(result)) return false;
	// 여기까지
	// Before we can initialize Direct3D we have to get the refresh rate from the video card/monitor. Each computer may be slightly different so we will need to query for that information. We query for the numerator and denominator values and then pass them to DirectX during the setup and it will calculate the proper refresh rate. If we don't do this and just set the refresh rate to a default value which may not exist on all computers then DirectX will respond by performing a blit instead of a buffer flip which will degrade performance and give us annoying errors in the debug output.
}

void D3DClass::BeginScene(float, float, float, float)
{
	
}

void D3DClass::EndScene()
{

}
