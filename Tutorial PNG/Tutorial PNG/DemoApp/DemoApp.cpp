#include <windows.h>
#include "DemoApp.h"
#include "TextureApp.h"

DempApp::DempApp(void) :
	m_Angle(2),
	pic(0),
	pos(0.0),
m_CoinRotation(0.0)
{
	Initialize();
}


DempApp::~DempApp(void)
{
}

void DempApp::Initialize()
{
	InitOpenGLApp::Initialize("App",140,140,1200,720);
	InitGlutInput::Initialize();

	m_Coin    = TextureApp::GenTexture("Media\\Texture\\coin.png"); // 分配一个纹理对象的编号
	m_Background = TextureApp::GenTexture("Media\\Texture\\background.jpg"); // 分配一个纹理对象的编号
	m_Stand = TextureApp::GenTexture("Media\\Texture\\stand.png"); // 分配一个纹理对象的编号
	m_Run = TextureApp::GenTexture("Media\\Texture\\run.png"); // 分配一个纹理对象的编号
}

void DempApp::Finalize()
{
	// delete named textures,释放内存
	glDeleteTextures(1,&m_Coin);
}

//void DempApp::timerFunction(int)
//{
//	glPushMatrix();
//	glBindTexture(GL_TEXTURE_2D, m_Stand);//载入纹理，马里奥站立图
//	glBegin(GL_QUADS);
//	//第一个参数是X坐标，0.0是纹理的左侧，1.0是纹理的右侧。第二个参数是Y坐标，0.0是纹理的底部，1.0是纹理的顶部。
//	glTexCoord2d(0, 0); glVertex2d(0.0, -0.85);//左下
//	glTexCoord2d(1, 0); glVertex2d(0.3, -0.85);//右下
//	glTexCoord2d(1, 1); glVertex2d(0.3, -0.3);//右上
//	glTexCoord2d(0, 1); glVertex2d(0.0, -0.3);//左上
//	glEnd();
//	glPopMatrix();
//
//	glutPostRedisplay();
//	//glutTimerFunc(100, DempApp::timerFunction, 1);
//}

void DempApp::Display(bool auto_redraw)
{	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.02f, 0.3f, 0.55f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//将引入的值与颜色缓冲中已有的值混合

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, m_Background);//载入纹理，背景纹理图
	glBegin(GL_QUADS);
	//第一个参数是X坐标，0.0是纹理的左侧，1.0是纹理的右侧。第二个参数是Y坐标，0.0是纹理的底部，1.0是纹理的顶部。
	glTexCoord2d(0, 0); glVertex2d(-1, -1);
	glTexCoord2d(1, 0); glVertex2d(1, -1);
	glTexCoord2d(1, 1); glVertex2d(1, 1);
	glTexCoord2d(0, 1); glVertex2d(-1, 1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.305, 0.1, 0);
	glScaled(0.5, 0.5, 0);
	glRotatef(m_CoinRotation, 0, 1, 0);
	glTranslated(-0.15, 0, 0);
	glBindTexture(GL_TEXTURE_2D, m_Coin);//载入纹理，金币纹理图
	glBegin(GL_QUADS);
	//第一个参数是X坐标，0.0是纹理的左侧，1.0是纹理的右侧。第二个参数是Y坐标，0.0是纹理的底部，1.0是纹理的顶部。
	glTexCoord2d(0, 0); glVertex2d(0, 0);
	glTexCoord2d(1, 0); glVertex2d(0.3, 0);
	glTexCoord2d(1, 1); glVertex2d(0.3, 0.5);
	glTexCoord2d(0, 1); glVertex2d(0, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(pos, 0, 0);
	
	if (pic == 0) {
		glBindTexture(GL_TEXTURE_2D, m_Stand);//载入纹理，马里奥站立图
	}
	else {
		glBindTexture(GL_TEXTURE_2D, m_Run);//载入纹理，马里奥走路图
	}
	
	glBegin(GL_QUADS);
	//第一个参数是X坐标，0.0是纹理的左侧，1.0是纹理的右侧。第二个参数是Y坐标，0.0是纹理的底部，1.0是纹理的顶部。
	glTexCoord2d(0, 0); glVertex2d(0.0, -0.85);//左下
	glTexCoord2d(1, 0); glVertex2d(0.3, -0.85);//右下
	glTexCoord2d(1, 1); glVertex2d(0.3, -0.3);//右上
	glTexCoord2d(0, 1); glVertex2d(0.0, -0.3);//左上
	glEnd();
	glPopMatrix();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	InitOpenGLApp::Display(false);
}

void DempApp::Update()
{
	pos -= 0.001;
		if (pic == 0)
			pic = 1;
		else
			pic = 0;
	m_CoinRotation += m_Angle;
	if (abs(m_CoinRotation)>=90)
	{
		m_Angle *= -1;
	}
	glutPostRedisplay();
}

void DempApp::KeyDown( int key )
{
	InitGlutInput::KeyDown(key);
	
	if (key == KEY_ENTER)
	{
		TextureApp::ScreenShot(std::string("ScreenShot"));
	}
}
