// This is the main project file for VC++ application project
// generated using an Application Wizard.

#define GLUT_DISABLE_ATEXIT_HACK

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../freeglut/glut.h"

static int draw_mode = 1;
static int action = 0;
static GLuint inner_mode = GL_SMOOTH;
static GLuint tex_state = GL_TRUE;
static int state_chang;

float anklea = 0, anklex = 0, ankley = 0, anklez = 1;
float plama, plamx = 0, plamy = 0, plamz = 0;
float anklef1a[2], anklef1x[2], anklef1y[2], anklef1z[2];
float anklef2a[3], anklef2x[3], anklef2y[3], anklef2z[3];
float anklef3a[3], anklef3x[3], anklef3y[3], anklef3z[3];
float anklef4a[3], anklef4x[3], anklef4y[3], anklef4z[3];
float anklef5a[3], anklef5x[3], anklef5y[3], anklef5z[3];
float BOX_WIDTH = 24.0f;
float BOX_THICK = 10.0f;
float BOX_HEIGHT = 30.0f;

float run_step = 0;
float heng_step = 0;
float fly_step = 0; 
float foot_BOX_WIDTH = 6.0f;
float foot_BOX_THICK = 8.0f;
float foot_BOX_HEIGHT = 2.0f;

enum { body_0_angle, body_125_angle, body_90_angle , run,heng, fly};
int rendermode = body_0_angle;

int state = 1;

static int WinWidth = 1200;
static int WinHeight = 1000;

//对手指的角度等数据初始化
void standby() {
	state = 1;
	anklea = 120, anklex = 0, ankley = 0, anklez = 1;  //¤â´x
	plama = 0, plamx = 0, plamy = 0, plamz = 0;  //¤â´x

	anklef1a[0] = 5;	//­手与拇指最长一节的关节，旋转方向和旋转角度数据
	anklef1x[0] = 0;
	anklef1y[0] = 0;
	anklef1z[0] = 1;
	anklef1a[1] = -20;	//拇指最长一节与中间一节的关节，旋转方向和旋转角度数据
	anklef1x[1] = 0;
	anklef1y[1] = 0;
	anklef1z[1] = 1;

	anklef2a[0] = 5;	//­手与食指最长一节的关节，旋转方向和旋转角度数据
	anklef2x[0] = 0;
	anklef2y[0] = 0;
	anklef2z[0] = 1;
	anklef2a[1] = 5;	//食指最长一节与中间一节的关节，旋转方向和旋转角度数据
	anklef2x[1] = 0;
	anklef2y[1] = 0;
	anklef2z[1] = 1;
	anklef2a[2] = -30;	//­食指中间一节与最外一节的关节，旋转方向和旋转角度数据
	anklef2x[2] = 0;
	anklef2y[2] = 0;
	anklef2z[2] = 1;

	anklef3a[0] = 5;	//­手与中指最长一节的关节，旋转方向和旋转角度数据
	anklef3x[0] = 0;
	anklef3y[0] = 0;
	anklef3z[0] = 1;
	anklef3a[1] = 0;	//最长一节与中间一节的关节，旋转方向和旋转角度数据
	anklef3x[1] = 0;
	anklef3y[1] = 0;
	anklef3z[1] = 1;
	anklef3a[2] = 0;	//­中间一节与最外一节的关节，旋转方向和旋转角度数据
	anklef3x[2] = 0;
	anklef3y[2] = 0;
	anklef3z[2] = 1;

	anklef4a[0] = 5;	
	anklef4x[0] = 0;
	anklef4y[0] = 0;
	anklef4z[0] = 1;
	anklef4a[1] = 10;	
	anklef4x[1] = 0;
	anklef4y[1] = 0;
	anklef4z[1] = 1;
	anklef4a[2] = 10;	
	anklef4x[2] = 0;
	anklef4y[2] = 0;
	anklef4z[2] = 1;

	anklef5a[0] = 15;	
	anklef5x[0] = 0;
	anklef5y[0] = 0;
	anklef5z[0] = 1;
	anklef5a[1] = 15;	
	anklef5x[1] = 0;
	anklef5y[1] = 0;
	anklef5z[1] = 1;
	anklef5a[2] = 10;	
	anklef5x[2] = 0;
	anklef5y[2] = 0;
	anklef5z[2] = 1;
}

//画头
void drawHead(void)
{
	glPushMatrix();
	glScalef(1.5, 1, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(15.0, 30.0, 30.0);
	glPopMatrix();
}

void drawEye()
{
	glPushMatrix();
	glScalef(1, 1, 1);
	glColor3ub(255, 0, 0);
	glutSolidSphere(3.0, 10.0, 10.0);
	glPopMatrix();
}
//画身体中间躯干
void drawTrunk(void)
{
	//glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glRotatef(0, 1.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);

	//Top face
	glColor3f(1.0f, 0.6f, 0.f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-BOX_WIDTH , BOX_HEIGHT , -BOX_THICK );
	glVertex3f(-BOX_WIDTH , BOX_HEIGHT , BOX_THICK );
	glVertex3f(BOX_WIDTH , BOX_HEIGHT , BOX_THICK );
	glVertex3f(BOX_WIDTH , BOX_HEIGHT , -BOX_THICK );

	//Bottom face
	glColor3f(1.0f, 0.6f, 0.f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-BOX_WIDTH , -BOX_HEIGHT , -BOX_THICK );
	glVertex3f(BOX_WIDTH , -BOX_HEIGHT , -BOX_THICK );
	glVertex3f(BOX_WIDTH , -BOX_HEIGHT , BOX_THICK );
	glVertex3f(-BOX_WIDTH , -BOX_HEIGHT , BOX_THICK );

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(-BOX_WIDTH , -BOX_HEIGHT , -BOX_THICK );
	glVertex3f(-BOX_WIDTH , -BOX_HEIGHT , BOX_THICK );
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(-BOX_WIDTH , BOX_HEIGHT , BOX_THICK );
	glVertex3f(-BOX_WIDTH , BOX_HEIGHT , -BOX_THICK );

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(BOX_WIDTH , -BOX_HEIGHT , -BOX_THICK );
	glVertex3f(BOX_WIDTH , BOX_HEIGHT , -BOX_THICK );
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(BOX_WIDTH , BOX_HEIGHT , BOX_THICK );
	glVertex3f(BOX_WIDTH , -BOX_HEIGHT , BOX_THICK );

	glEnd();
	glBegin(GL_QUADS);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(-BOX_WIDTH , -BOX_HEIGHT , BOX_THICK );
	glVertex3f(BOX_WIDTH , -BOX_HEIGHT , BOX_THICK );
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(BOX_WIDTH , BOX_HEIGHT , BOX_THICK );
	glVertex3f(-BOX_WIDTH , BOX_HEIGHT , BOX_THICK );

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(-BOX_WIDTH , -BOX_HEIGHT , -BOX_THICK );
	glVertex3f(-BOX_WIDTH , BOX_HEIGHT , -BOX_THICK );
	glColor3f(1.0f, 0.6f, 0.f);
	glVertex3f(BOX_WIDTH , BOX_HEIGHT , -BOX_THICK );
	glVertex3f(BOX_WIDTH , -BOX_HEIGHT , -BOX_THICK );

	glEnd();

	glPopMatrix();
}

//画左臂部分
void draw_left_hand(void)
{

	//大臂
	glPushMatrix();
	glScalef(4, 1, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(7.0, 30.0, 30.0);
	glPopMatrix();

		//小臂和大臂之间链接球
	glPushMatrix();
	glTranslatef(-25.0f, 0.0, 0.0);
	//glRotatef(0, 0, 0, 1);
	glColor3ub(219, 156, 53);
	glutSolidSphere(5.0, 30.0, 30.0);
	glPopMatrix();


	//小臂
	glPushMatrix();
	glTranslatef(-20.0, -20.0, 0.0);
	glRotatef(-60, 0, 0, 1);
	glScalef(4, 1, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(6.0, 30.0, 30.0);
	glPopMatrix();


	//小臂和手(这里也是个球)之间的球`
	glPushMatrix();
	glTranslatef(-7.0, -40.0, 0.0);
	glColor3ub(219, 156, 53);
	glutSolidSphere(3.0, 30.0, 30.0);
	glPopMatrix();

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//手掌
	glPushMatrix();
	glTranslatef(-3.0, -48.0, 3);
	glPushMatrix();
	glColor3ub(255, 102, 125);
	glScalef(1, 1, 0.5);
	glutSolidSphere(8, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();
	////.\手掌 结束///

}

//画右臂部分
void draw_right_hand(void)
{
	//大臂
	glPushMatrix();
	glScalef(4, 1, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(7.0, 30.0, 30.0);
	glPopMatrix();


	//小臂和大臂之间链接球
	glPushMatrix();
	glTranslatef(25.0f, 0.0, 0.0);
	//glRotatef(0, 0, 0, 1);
	glColor3ub(219, 156, 53);
	glutSolidSphere(5.0, 30.0, 30.0);
	glPopMatrix();


	//小臂
	glPushMatrix();
	glTranslatef(17.0, -20.0, 0.0);
	glRotatef(60, 0, 0, 1);
	glScalef(4, 1, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(6.0, 30.0, 30.0);
	glPopMatrix();


	//小臂和手(这里也是个球)之间的球`
	glPushMatrix();
	glTranslatef(5.0, -42.0, 0.0);
	glColor3ub(219, 156, 53);
	glutSolidSphere(3.0, 30.0, 30.0);
	glPopMatrix();

	//手掌
	glPushMatrix();
	glTranslatef(-3.0, -48.0, 3);
	glPushMatrix();
	glColor3ub(255, 102, 125);
	glScalef(1, 1, 0.5);
	glutSolidSphere(8, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();
	////.\手掌 结束//////////////////////////////////////
}

void draw_hand()
{
	//手指开始////////////////////////////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(-3.0, -48.0, 11);
	///拇指开始/////////////
	glPushMatrix();
	glRotatef(-45, 0, 0, 1);
	glTranslatef(-2.0, 0.5, -3);//第一个参数越大越往下，第二个参数越大越往左
								//­手与拇指最长一节的关节
	glPushMatrix();
	glTranslatef(-6, -4, 0.0);
	glRotatef(anklef1a[0], anklef1x[0], anklef1y[0], anklef1z[0]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();
	//拇指最长一节
	glTranslatef(-4, 0, 0);//­¹«ü¸`3
	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();
	////­拇指最长一节与中间一节的关节
	glTranslatef(-4, 0, 0);//­¹«ü¤¤Ãö¸`
	glRotatef(anklef1a[1], anklef1x[1], anklef1y[1], anklef1z[1]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//拇指中间一节
	glTranslatef(-3.0, 0, 0.0);//­¹«ü¸`2
	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	////拇指结束////////////////

	////食指开始/////////////////////
	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	glTranslatef(-13.0, 0.0, -3);//第一个参数越大越往下，第二个参数越大越往左
								 //­手与食指最长一节的关节
	glPushMatrix();
	glTranslatef(0, 0, 0.0);
	glRotatef(anklef2a[2], anklef2x[0], anklef2y[0], anklef2z[0]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();
	//食指最长一节
	glTranslatef(-4, 0, 0);//­¹«ü¸`3
	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();
	////­最长一节与中间一节的关节
	glTranslatef(-4, 0, 0);//­¹«ü¤¤Ãö¸`
	glRotatef(anklef2a[1], anklef2x[1], anklef2y[1], anklef2z[1]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//­食指中间一节
	glTranslatef(-3.0, 0, 0.0);//­¹«ü¸`2
	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();
	//食指中间一节与最外一节的关节
	glTranslatef(-3, 0, 0.0);
	glRotatef(anklef2a[2], anklef2x[2], anklef2y[2], anklef2z[2]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//食指最外一节
	glTranslatef(-2.5, 0.0, 0.0);
	glPushMatrix();
	glRotatef(20.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//.\食指手指结束
	///////////////

	////中指开始/////////////////////
	glPushMatrix();
	glRotatef(-5, 0, 0, 1);
	glTranslatef(-14.0, -2.0, -3);//第一个参数越大越往下，第二个参数越大越往左
								  //­手与中指最长一节的关节
	glPushMatrix();
	glTranslatef(0, 0, 0.0);
	glRotatef(anklef3a[2], anklef3x[0], anklef3y[0], anklef3z[0]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();
	//手指最长一节
	glTranslatef(-4, 0, 0);//­¹«ü¸`3
	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();
	////­最长一节与中间一节的关节
	glTranslatef(-4, 0, 0);//­¹«ü¤¤Ãö¸`
	glRotatef(anklef3a[1], anklef3x[1], anklef3y[1], anklef3z[1]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//­中间一节
	glTranslatef(-3.0, 0, 0.0);//­¹«ü¸`2
	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();
	//中间一节与最外一节的关节
	glTranslatef(-3, 0, 0.0);
	glRotatef(anklef3a[2], anklef3x[2], anklef3y[2], anklef3z[2]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//最外一节
	glTranslatef(-2.5, 0.0, 0.0);
	glPushMatrix();
	glRotatef(0.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//.\中指手指结束
	///////////////

	////名指开始/////////////////////
	glPushMatrix();
	glRotatef(-30, 0, 0, 1);
	glTranslatef(-13, -4.0, -3);//第一个参数越大越往下，第二个参数越大越往左
								//­手与名指最长一节的关节
	glPushMatrix();
	glTranslatef(0, 0, 0.0);
	glRotatef(anklef4a[2], anklef4x[0], anklef4y[0], anklef4z[0]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();
	//最长一节
	glTranslatef(-4, 0, 0);//­¹«ü¸`3
	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();
	////­最长一节与中间一节的关节
	glTranslatef(-4, 0, 0);//­¹«ü¤¤Ãö¸`
	glRotatef(anklef4a[1], anklef2x[1], anklef2y[1], anklef2z[1]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//­中间一节
	glTranslatef(-3.0, 0, 0.0);//­¹«ü¸`2
	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();
	//中间一节与最外一节的关节
	glTranslatef(-3, 0, 0.0);
	glRotatef(anklef4a[2], anklef4x[2], anklef4y[2], anklef4z[2]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//最外一节
	glTranslatef(-2.5, 0.0, 0.0);
	glPushMatrix();
	glRotatef(0.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//.\名指手指结束

	////小拇指开始/////////////////////
	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	glTranslatef(-10, 2, -3);//第一个参数越大越往下，第二个参数越大越往左
							 //­手与小拇指最长一节的关节
	glPushMatrix();
	glTranslatef(0, 0, 0.0);
	glRotatef(anklef5a[2], anklef5x[0], anklef5y[0], anklef5z[0]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();
	//最长一节
	glTranslatef(-3, 0, 0);//­¹«ü¸`3
	glPushMatrix();
	glScalef(0.8, 0.5, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();
	////­最长一节与中间一节的关节
	glTranslatef(-3, 0, 0);//­¹«ü¤¤Ãö¸`
	glRotatef(anklef5a[1], anklef5x[1], anklef5y[1], anklef5z[1]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//­中间一节
	glTranslatef(-2.0, 0, 0.0);//­¹«ü¸`2
	glPushMatrix();
	glScalef(0.8, 0.5, 1);//对球体进行比例克隆，第一个参数越小可以变扁，第二个越大越胖
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);//绘制一个球体，第一第二个参数是经纬线，第一个是半径
	glPopMatrix();
	//中间一节与最外一节的关节
	glTranslatef(-2.5, 0, 0.0);
	glRotatef(anklef5a[2], anklef5x[2], anklef5y[2], anklef5z[2]);
	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();
	//最外一节
	glTranslatef(-2, 0.0, 0.0);
	glPushMatrix();
	glRotatef(-20.0, 0, 1, 1.0);
	glScalef(0.5, 0.45, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//.\小拇指手指结束
	glPopMatrix();
	//.\手指部分结束/////////////////////////
}

//画左腿
void draw_left_leg()
{
	glPushMatrix();
	glScalef(1, 3, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(8.0, 30.0, 30.0);
	glPopMatrix();
}
//画右腿
void draw_right_leg()
{
	glPushMatrix();
	glScalef(1, 3, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(8.0, 30.0, 30.0);
	glPopMatrix();
}

//画左脚
void draw_left_foot(void)
{
	glPushMatrix();
	glRotatef(0, 1.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);

	//Top face
	glColor3f(1.0f, 0.8f, 0.f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);

	//Bottom face
	glColor3f(1.0f, 0.8f, 0.f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, BOX_HEIGHT, -foot_BOX_THICK);

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);

	glEnd();

	glColor3f(1.0f, 0.8f, 0.f);
	glBegin(GL_QUADS);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);

	glEnd();

	glPopMatrix();
}

//画右脚
void draw_right_foot()
{
	glPushMatrix();
	glRotatef(0, 1.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);

	//Top face
	glColor3f(1.0f, 0.8f, 0.f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);

	//Bottom face
	glColor3f(1.0f, 0.8f, 0.f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, BOX_HEIGHT, -foot_BOX_THICK);

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);

	glEnd();

	glColor3f(1.0f, 0.8f, 0.f);
	glBegin(GL_QUADS);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, foot_BOX_THICK);

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(-foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(-foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glColor3f(1.0f, 0.8f, 0.f);
	glVertex3f(foot_BOX_WIDTH, foot_BOX_HEIGHT, -foot_BOX_THICK);
	glVertex3f(foot_BOX_WIDTH, -foot_BOX_HEIGHT, -foot_BOX_THICK);

	glEnd();

	glPopMatrix();
}

//组装身体
void draw(float body_angle)
{
	//glRotatef(body_angle, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 60.0, -210.0);
	glRotatef(body_angle, 0, 1, 0);
	drawHead();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8.0, 63.0, -170.0);
	glRotatef(body_angle, 0, 1, 0);
	drawEye();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 17.0, -200.0);
	glRotatef(body_angle, 0, 1, 0);
	drawTrunk();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50.0, 40.0, -195.0);
	if (body_angle == 0)
	{
		glRotatef(body_angle, 0, 1, 0);
		draw_left_hand();
		draw_hand();
	}
	else {
		glTranslatef(35.0, 0.0, 25.0);
		glRotatef(body_angle, 0, 1, 0);
		draw_left_hand();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30.0, 40.0, -195.0);
	if (body_angle == 0)
	{
		glRotatef(body_angle, 0, 1, 0);
	}
	else {
		glTranslatef(-35.0, 0.0, -25.0);
		glRotatef(body_angle, 0, 1, 0);
	}
	draw_right_hand();
	glPopMatrix();

	glPushMatrix();
	if (body_angle == 90)
	{
		glTranslatef(-14.0, -35.0, -200);
		glRotatef(body_angle, 0, 1, 0);
		draw_left_leg();
	}
	else {
		glTranslatef(-24.0, -35.0, -200);
		glRotatef(body_angle, 0, 1, 0);
		draw_left_leg();
	}
	
	glPopMatrix();

	glPushMatrix();
	if (body_angle == 90.0)
	{
		glTranslatef(-11.0, -35.0, -220);
		glRotatef(body_angle, 0, 1, 0);
		draw_right_leg();
	}
	else {
		glTranslatef(7.0, -35.0, -200);
		glRotatef(body_angle, 0, 1, 0);
		draw_right_leg();
	}
	glPopMatrix();

	glPushMatrix();
	if (body_angle == 90.0)
	{
		glTranslatef(-15.0, -60.0, -202);
		glRotatef(body_angle, 0, 1, 0);
		draw_left_foot();
	}
	else {
		glTranslatef(-25.0, -60.0, -202);
		glRotatef(body_angle, 0, 1, 0);
		draw_left_foot();
	}
	glPopMatrix();

	glPushMatrix();
	if (body_angle == 90.0)
	{
		glTranslatef(-10.0, -60.0, -222);
		glRotatef(body_angle, 0, 1, 0);
		draw_right_foot();
	}
	else {
		glTranslatef(8.0, -60.0, -202);
		glRotatef(body_angle, 0, 1, 0);
		draw_right_foot();
	}
	glPopMatrix();

	glPopMatrix();
}

void timerFunction(int value)
{
	action = value;
	if (action == 1)
	{
		glPushMatrix();
		glTranslatef(run_step, 0.0, 0.0);
		draw(90);
		glPopMatrix();

	}

	glutPostRedisplay();
	glutTimerFunc(5, timerFunction, 1);
}

void timerRUNHengFunction(int value)
{
	action = value;
	if (action == 2)
	{
		glPushMatrix();
		glTranslatef(0.0, 0.0, heng_step);
		draw(90);
		glPopMatrix();

	}
	glutPostRedisplay();
	glutTimerFunc(5, timerFunction, 1);
}

void timerFLYFunction(int value)
{
	action = value;
	if (action == 3)
	{
		glPushMatrix();
		glTranslatef(0.0, fly_step,0.0);
		draw(90);
		glPopMatrix();

	}
	glutPostRedisplay();
	glutTimerFunc(5, timerFunction, 1);
}

//被gludisplayfun调用
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(inner_mode);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	switch (rendermode) {
		case body_0_angle:
		run_step = 0;
		fly_step = 0;
		heng_step = 0;
		draw(0.0f);
		break;

		case body_125_angle:
		run_step = 0;
		fly_step = 0;
		heng_step = 0;
		draw(125.0f);
		break;

		case body_90_angle:
		run_step = 0;
		fly_step = 0;
		heng_step = 0;
		draw(90.0f);
		break;

		case run:
		//走路
		fly_step = 0;
		heng_step = 0;
		timerFunction(1);
		break;

		case heng:
		//横着走
		timerRUNHengFunction(2);
		break;

		case fly:
		run_step = 0;
		heng_step = 0;
		//飞行
		timerFLYFunction(3);
		break;
	}
	run_step = run_step + 0.4;
	fly_step = fly_step + 0.4;
	heng_step = heng_step + 0.4;
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	WinWidth = w;
	WinHeight = h;
	GLfloat aspect;
	aspect = (GLfloat)w / (GLfloat)h;
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	if (aspect > 1.0f)
		glViewport((w - h) / 2.0f, 0, (GLsizei)h, (GLsizei)h);
	else
		glViewport(0, (h - w) / 2.0f, (GLsizei)w, (GLsizei)w);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.2f, 1.0f, 200.0f);//观察的视景体在世界坐标系中的具体大小
	glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
	GLfloat  ambientLight[] = { 1, 1, 1, 0.0f };
	GLfloat  diffuseLight[] = { 0, 0, 0, 1.0f };
	GLfloat  specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat  ambientLight2[] = { 0.9f, 0.1f, 0.1f, 1.0f };
	GLfloat  specular2[] = { 0.3f, 0.3f, 0.3f, 1.3f };
	GLfloat  specref[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat  pos[] = { 0.0f, 20.0f, -100.0f, 1.0f };
	GLfloat  dir[] = { 0.0f, 0.0f, -1.0f };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);//设置0号光源的环境光属性
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);//设置0号光源的散射光属性
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);//设置0号光源的镜面反射光属性
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, ambientLight2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular2);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 100);
	glLightfv(GL_LIGHT1, GL_POSITION, pos);//设置0号光源的位置属性

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
}

void menu(int selection)
{
	rendermode = selection;
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	int main_menu, action_menu, count_menu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	//glutInitWindowSize(1200,600);	//< Dual view
	glutInitWindowSize(WinWidth, WinHeight);	//< Single view

	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);

	init();
	standby();

	//菜单
	glutCreateMenu(menu);
	glutAddMenuEntry("Normal", body_0_angle);
	glutAddMenuEntry("Rotate90", body_90_angle);
	glutAddMenuEntry("Rotate125", body_125_angle);
	glutAddMenuEntry("Run", run);
	glutAddMenuEntry("Run_heng", heng);
	glutAddMenuEntry("Fly", fly);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutReshapeFunc(reshape);//改变窗口后调用
	glutDisplayFunc(display);
	glutTimerFunc(5, timerFunction, 1);//注册一个定时调用函数，持续定时

	glutMainLoop();
	return 0;

}

