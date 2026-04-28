#pragma once

#include <DirectXMath.h>
using namespace DirectX;

class CameraClass
{
public:
	CameraClass(): m_positionX(0), m_positionY(0), m_positionZ(0),
					m_rotationX(0), m_rotationY(0), m_rotationZ(0){}
	CameraClass(const CameraClass& other) {}
	~CameraClass() {}

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);
	
	XMFLOAT3 GetPosition() { return XMFLOAT3(m_positionX, m_positionY, m_positionZ); }
	XMFLOAT3 GetRotation() { return XMFLOAT3(m_rotationX, m_rotationY, m_rotationZ); }

	void Render();
	void GetViewMatrix(XMMATRIX&);
private:
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	XMMATRIX m_viewMatrix;
};


