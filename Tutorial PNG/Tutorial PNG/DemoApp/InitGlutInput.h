#pragma once
#include "vgl.h"
#include <iostream>

class InitGlutInput
{
public:
	enum Mouse_Btn{
		LEFT	= 0,
		MIDDLE	= 1,
		RIGHT	= 2
	};

	enum Mouse_State{
		PRESS	= 0,
		UP		= 1
	};

	enum SpecialKey{
		KEY_F1 = 1,
		KEY_F2 = 2,
		KEY_F3 = 3,
		KEY_F4 = 4,
		KEY_F5 = 5,
		KEY_F6 = 6,
		KEY_F7 = 7,
		KEY_F8 = 8,
		KEY_F9 = 9,
		KEY_F10 = 10,
		KEY_F11 = 11,
		KEY_F12 = 12,
		KEY_ENTER = 13,
		KEY_ESC = 27,
		KEY_SPACE = 32,
		KEY_LEFT = 100,
		KEY_UP = 101,
		KEY_RIGHT = 102,
		KEY_DOWN = 103,
		KEY_LEFT_SHIFT = 112,
		KEY_RIGHT_SHIFT = 113,
		KEY_LEFT_CTRL = 114,
		KEY_RIGHT_CTRL = 115,
		KEY_LEFT_ALT = 116,
		KEY_RIGHT_ALT = 117,
		KEY_D1 = 49,
		KEY_D2 = 50,
		KEY_D3 = 51,
		KEY_D4 = 52,
		KEY_D5 = 53,
		KEY_D6 = 54,
		KEY_D7 = 55,
		KEY_D8 = 56,
		KEY_D9 = 57,
		KEY_D0 = 48,
		KEY_DELETE = 127,
	};
protected:
	bool m_Keyboard[256];

	static InitGlutInput* target_input; 
	static void KeyboardFunc(unsigned char key, int x, int y);
	static void KeyboardUpFunc(unsigned char key, int x, int y);
	static void SKeyboardFunc(int key, int x, int y);
	static void SKeyboardUpFunc(int key, int x, int y);
	static void MotionFunc(int x, int y);
	static void MouseFunc(int button, int state, int x, int y);
public:
	InitGlutInput(void);
	~InitGlutInput(void);

	void Initialize();
private:
	void Input_Keyboard(int key,bool status);
protected:
	virtual void KeyDown(int key);
	virtual	void KeyUp(int key);
	virtual	void KeyPress(int key);
	virtual void Input_Mouse(int button, int state, int x, int y);

public:
	bool isKeyPress(int key){return m_Keyboard[key];}
};

