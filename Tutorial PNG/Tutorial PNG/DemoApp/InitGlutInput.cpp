#include "InitGlutInput.h"


InitGlutInput::InitGlutInput(void)
{
	memset(m_Keyboard,0,sizeof(bool)*256);
}


InitGlutInput::~InitGlutInput(void)
{
}

InitGlutInput * InitGlutInput::target_input = NULL;
void InitGlutInput::KeyboardFunc( unsigned char key, int x, int y )
{
	target_input->Input_Keyboard(key,true);
}

void InitGlutInput::KeyboardUpFunc( unsigned char key, int x, int y )
{
	target_input->Input_Keyboard(key,false);
}

void InitGlutInput::SKeyboardFunc( int key, int x, int y )
{
	target_input->Input_Keyboard(key,true);
}

void InitGlutInput::SKeyboardUpFunc( int key, int x, int y )
{
	target_input->Input_Keyboard(key,false);
}

void InitGlutInput::MouseFunc( int button, int state, int x, int y )
{
	target_input->Input_Mouse(button,state,x,y);
}

void InitGlutInput::MotionFunc( int x, int y )
{
	target_input->Input_Mouse(0,0,x,y);
}

/////////////////////////////////////////////////////////////////////////

void InitGlutInput::Initialize()
{
	target_input = this;

	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SKeyboardFunc);
	glutSpecialUpFunc(SKeyboardUpFunc);
	glutMouseFunc(MouseFunc);
	glutMotionFunc(MotionFunc);
}

void InitGlutInput::Input_Keyboard( int key,bool status )
{
	if (status)
	{
		if(!m_Keyboard[key])KeyDown(key);
		else KeyPress(key);
		m_Keyboard[key] = true;
	}else{
		KeyUp(key);
		m_Keyboard[key] = false;
	}
}

void InitGlutInput::KeyUp( int key )
{
	glutPostRedisplay();
}

void InitGlutInput::KeyDown( int key )
{
	switch(key){
	case KEY_ESC:
		glutLeaveMainLoop();
		break;
	case KEY_F4:
		glutFullScreenToggle();
		break;
	}
	glutPostRedisplay();
}

void InitGlutInput::KeyPress( int key )
{
	glutPostRedisplay();
}

void InitGlutInput::Input_Mouse( int button, int state, int x, int y )
{
	glutPostRedisplay();
}



