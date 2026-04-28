#pragma once
class InputClass
{
public:
	InputClass() {}
	InputClass(const InputClass&) {}
	~InputClass() {}

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	void Initialize();

	bool IsKeyDown(unsigned int);

private:
	bool m_keys[256];
};

