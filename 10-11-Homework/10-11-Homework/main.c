#include <gl/glut.h>
#include <stdio.h>
const GLdouble FRUSTDIM = 100.f;
const GLdouble FRUSTNEAR = 320.f;
const GLdouble FRUSTFAR = 660.f;
float	g_triangle_rotation;
float	ne_g_triangle_rotation;
float	g_rotation_speed;
enum { SPHERE = 1, CONE };
enum { NONE, FIELD };
int rendermode = FIELD;
const int TEXDIM = 256;
GLdouble focus = 420.;

/*
** Create a single component texture map
*/
GLfloat *make_texture(int maxs, int maxt)
{
    int s, t;
    static GLfloat *texture;

    texture = (GLfloat *)malloc(maxs * maxt * sizeof(GLfloat));
    for(t = 0; t < maxt; t++) {
        for(s = 0; s < maxs; s++) {
            texture[s + maxs * t] = ((s >> 4) & 0x1) ^ ((t >> 4) & 0x1);
        }
    }
    return texture;
}

void menu(int selection)
{
	rendermode = selection;
	glutPostRedisplay();
}

void key(unsigned char key, int x, int y)
{
	if (key == '\033')
		exit(0);
}

//��������ǽ��
void drawWalls() 
{
	static GLfloat wall_mat[] = { 1.f, 1.f, 1.f, .7f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wall_mat);
	/* walls */
	glBegin(GL_QUADS);
	/* left wall */
	glNormal3f(1.f, 0.f, 0.f);
	glVertex3f(-100.f, -100.f, -320.f);
	glVertex3f(-100.f, -100.f, -640.f);
	glVertex3f(-100.f, 100.f, -640.f);
	glVertex3f(-100.f, 100.f, -320.f);

	/* right wall */
	glNormal3f(-1.f, 0.f, 0.f);
	glVertex3f(100.f, -100.f, -320.f);
	glVertex3f(100.f, 100.f, -320.f);
	glVertex3f(100.f, 100.f, -640.f);
	glVertex3f(100.f, -100.f, -640.f);

	/* ceiling */
	glNormal3f(0.f, -1.f, 0.f);
	glVertex3f(-100.f, 100.f, -320.f);
	glVertex3f(-100.f, 100.f, -640.f);
	glVertex3f(100.f, 100.f, -640.f);
	glVertex3f(100.f, 100.f, -320.f);

	/* back wall */
	glNormal3f(0.f, 0.f, 1.f);
	glVertex3f(-100.f, -100.f, -640.f);
	glVertex3f(100.f, -100.f, -640.f);
	glVertex3f(100.f, 100.f, -640.f);
	glVertex3f(-100.f, 100.f, -640.f);
	glEnd();
}

void render(GLfloat dx, GLfloat dy, GLfloat dz)
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	/* ���Ƶ����texture */
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glNormal3f(0.f, 1.f, 0.f);
	glTexCoord2i(0, 0);
	glVertex3f(-100.f, -100.f, -320.f);
	glTexCoord2i(1, 0);
	glVertex3f(100.f, -100.f, -320.f);
	glTexCoord2i(1, 1);
	glVertex3f(100.f, -100.f, -640.f);
	glTexCoord2i(0, 1);
	glVertex3f(-100.f, -100.f, -640.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//����ԭʼ������ת
	glPushMatrix(); 
	/*���ƶ���ת����*/
	glTranslatef(-10.f , -80.f , -600.f);
	/*��ת*/
	glRotatef(g_triangle_rotation, 0.0f, 1.0f, 0.0f);
	/*��ת�Ƕ�*/
	glTranslatef(-50.f + 10, 10.f, -1.f + 10);
	//���ú�������������
	glCallList(SPHERE);
	g_triangle_rotation += g_rotation_speed;
	glPopMatrix(); 
	
	//����ԭʼ׵��
	glPushMatrix();
	glTranslatef(-10.f, -80.f, -600.f);
	glCallList(CONE);
	glPopMatrix();

	/************���ƾ��棬�Լ���������������׵��****************/
	glEnable(GL_STENCIL_TEST); //Enable using the stencil buffer
	glColorMask(0, 0, 0, 0); //Disable drawing colors to the screen
	glDisable(GL_DEPTH_TEST); //Disable depth testing
	glStencilFunc(GL_ALWAYS, 1, 1); //Make the stencil test always pass
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//����͸���ڵ���
	drawWalls();
	glColorMask(1, 1, 1, 1); //Enable drawing colors to the screen
	glEnable(GL_DEPTH_TEST); //Enable depth testing
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Make the stencil buffer not change

	//����
	glPushMatrix();
	glTranslatef(-10.f, -80.f, -705.f);
	glRotatef(g_triangle_rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(-50.f + 10, 10.f, -1.f + 10);
	glCallList(SPHERE);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10.f, -80.f, -705.f);
	glCallList(CONE);
	glPopMatrix();

	//����
	glPushMatrix();
	glTranslatef(-170.f, -80.f, -600.f);
	glRotatef(ne_g_triangle_rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(25.f + 10, 10.f, -1.f + 10);
	glCallList(SPHERE);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-170.f, -80.f, -600.f);
	glCallList(CONE);
	glPopMatrix();

	//����
	glPushMatrix();
	glTranslatef(170.f, -80.f, -600.f);
	glRotatef(ne_g_triangle_rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(25.f + 10, 10.f, -1.f + 10);
	glCallList(SPHERE);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(170.f, -80.f, -600.f);
	glCallList(CONE);
	ne_g_triangle_rotation = ne_g_triangle_rotation - g_rotation_speed;
	glPopMatrix();

	//����
	glPushMatrix();
	glTranslatef(-10.f, -160.f, -600.f);
	glRotatef(g_triangle_rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(-50.f + 10, 10.f, -1.f + 10);
	glCallList(SPHERE);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10.f, -160.f, -600.f);
	glCallList(CONE);
	glPopMatrix();

	//����
	glPushMatrix();
	glTranslatef(-10.f, 160.f, -600.f);
	glRotatef(g_triangle_rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(-50.f + 10, 10.f, -1.f + 10);
	glCallList(SPHERE);
	glPopMatrix();
	glPushMatrix();
	glScalef(1, -1, 1);
	glTranslatef(-10.f, -180.f, -600.f);
	glCallList(CONE);
	glPopMatrix();

	glDisable(GL_STENCIL_TEST); //Disable using the stencil buffer
	/***************************************************************/

	glEnable(GL_BLEND);
	//����ʵ���ǽ�棬ǰ����û��Ƶ���͸���ڵ���
	drawWalls();
	glDisable(GL_BLEND);
	
	if (glGetError()) /* to catch programming errors; should never happen */
		//printf("Oops! I screwed up my OpenGL calls somewhere\n");
	glFlush(); /* high end machines may need this */
}

//��ʼ�����ã�����3D����ʵ���Ա�ʵ��������
void display() {
	GLfloat *tex;
	static GLfloat lightpos[] = { 50.f, 50.f, -320.f, 1.f };
	static GLfloat sphere_mat[] = { 1.f, .5f, 0.f, 1.f };
	static GLfloat cone_mat[] = { 0.f, .5f, 1.f, 1.f };
	GLUquadricObj *sphere, *cone, *base;

	//�����Ҽ��˵�
	glutCreateMenu(menu);
	glutAddMenuEntry("Normal", NONE);
	glutAddMenuEntry("Motion Blur", FIELD);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	/* draw a perspective scene */
	glMatrixMode(GL_PROJECTION);
	glFrustum(-FRUSTDIM, FRUSTDIM, -FRUSTDIM, FRUSTDIM, FRUSTNEAR, FRUSTFAR);
	glMatrixMode(GL_MODELVIEW);

	/* turn on features */
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/* place light 0 in the right place */
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	/* remove back faces to speed things up */
	glCullFace(GL_BACK);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	/*��������ʵ�����Ա�ʵ�������������*/
	glNewList(SPHERE, GL_COMPILE);
	sphere = gluNewQuadric();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sphere_mat);
	gluSphere(sphere, 20.f, 20, 20);
	gluDeleteQuadric(sphere);
	glEndList();

	/*����׵��ʵ�����Ա�ʵ���������׵��*/
	glNewList(CONE, GL_COMPILE);
	cone = gluNewQuadric();
	base = gluNewQuadric();
	glRotatef(-90.f, 1.f, 0.f, 0.f);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cone_mat);
	gluDisk(base, 0., 20., 20, 1);
	gluCylinder(cone, 20., 0., 60., 20, 20);
	gluDeleteQuadric(cone);
	gluDeleteQuadric(base);
	glEndList();

	/* load pattern for current 2d texture */
	tex = make_texture(TEXDIM, TEXDIM);
	glTexImage2D(GL_TEXTURE_2D, 0, 1, TEXDIM, TEXDIM, 0, GL_RED, GL_FLOAT, tex);
	free(tex);
}

/* ����ģ��Ч�� */
void redraw()
{
	int i;
	int min, max;
	int count;
	GLfloat scale, dx, dy, dz;

	dx = .5f;
	dy = 1.f;
	dz = -2.f;

	glPushMatrix();
	switch (rendermode) {
	case NONE:
		render(0.f, 0.f, 0.f);
		break;
	case FIELD:
		/*����ģ����Ч��������Խ��β����Խ��*/
		max = 66;

		glClear(GL_ACCUM_BUFFER_BIT);

		for (i = 0; i < max; i++) {
			render(dx * 15 * i, dy * 15 * i, dz * 15 * i);
			glAccum(GL_ACCUM, 1.f / max);
		}
		glAccum(GL_RETURN, 1.f);
		break;
	}

	glPopMatrix();



	glutSwapBuffers();
}

/* Parse arguments, and set up interface between OpenGL and window system */
main(int argc, char *argv[])
{
	g_rotation_speed = 0.82f;
	g_triangle_rotation = 0;
	ne_g_triangle_rotation = 0.f;

	glutInit(&argc, argv);
	glutInitWindowSize(512, 512);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_ACCUM | GLUT_SINGLE);
	(void)glutCreateWindow("Q3-��̬ģ��+����-10-11-A10515001");
	glutDisplayFunc(redraw);
	glutKeyboardFunc(key);

	display(); 
	glutIdleFunc(redraw);

	glutMainLoop();
}

