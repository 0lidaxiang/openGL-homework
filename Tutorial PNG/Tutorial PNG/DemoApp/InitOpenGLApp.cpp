#include "InitOpenGLApp.h"

int InitOpenGLApp::Width = 1080;
int InitOpenGLApp::Height = 720;


InitOpenGLApp::InitOpenGLApp(void)
{
	
}


InitOpenGLApp::~InitOpenGLApp(void)
{
}

InitOpenGLApp * InitOpenGLApp::target_app = NULL;
void InitOpenGLApp::DisplayFunc()
{
	target_app->Display();
}

void InitOpenGLApp::ReshapeFunc( int width,int height )
{
	target_app->Reshape(width,height);
}

void InitOpenGLApp::CloseFunc()
{
	target_app->Finalize();
}

void InitOpenGLApp::IdleFunc()
{
	target_app->Update();
}

void InitOpenGLApp::Initialize(const char* title, /*Title of Screen */ int x, int y, /*Position of Screen */ int width, int height /*width and height of Screen */ )
{
	int one = 1;
	char * name = "name";

	target_app = this;
	Width = width;
	Height = height;

#ifdef _DEBUG
	glutInitContextFlags(GLUT_DEBUG);
#endif
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitContextVersion(3, 3);

	glutInitWindowSize(Width, Height);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	
	glutInit(&one, &name);

	glutCreateWindow( title ? title : "OpenGL Application" );
	glutDisplayFunc(DisplayFunc);
	glutReshapeFunc(ReshapeFunc);
	glutIdleFunc(IdleFunc);
	glutCloseFunc(CloseFunc);

	glewInit();
}

void InitOpenGLApp::Display( bool auto_redraw /*= true*/ )
{
	glutSwapBuffers();
	if (auto_redraw)
	{
		glutPostRedisplay();
	}
}

void InitOpenGLApp::Reshape( int width, int height )
{
	Width = width;
	Height = height;

	glViewport(0, 0, width, height);
}

void InitOpenGLApp::Finalize( void )
{

}

void InitOpenGLApp::Start( void )
{
	glutMainLoop();
}

void InitOpenGLApp::Update( void )
{

}





