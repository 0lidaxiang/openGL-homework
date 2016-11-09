#pragma once
#include "InitOpenGLApp.h"
#include "InitGlutInput.h"

class DempApp : 
	public InitOpenGLApp,
	public InitGlutInput
{
private:
	double m_Angle;
	double m_CoinRotation;
	GLuint m_Coin;
	GLuint m_Background;
	GLuint m_Stand;
	GLuint m_Run;
	int pic;
	double pos;
public:
	DempApp(void);
	~DempApp(void);

	void Initialize();
protected:
	//void updatePic();
	void Update();
	void KeyDown(int key);
	void Display(bool auto_redraw = true);
	void Finalize();
private:
};


