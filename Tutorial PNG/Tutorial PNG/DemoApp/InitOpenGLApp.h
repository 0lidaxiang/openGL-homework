#pragma once
#include "vgl.h"
#include <iostream>

class InitOpenGLApp
{
public:
	static int Width,Height;
protected:
	static InitOpenGLApp * target_app;
	static void DisplayFunc();
	static void ReshapeFunc(int width,int height);
	static void CloseFunc();
	static void IdleFunc();
public:
	InitOpenGLApp(void);
	~InitOpenGLApp(void);
public:
	virtual void Initialize(
		                    const char* title,    //Title of Screen 
							int x, int y,         //Position of Screen 
							int width, int height //width and height of Screen
							);
	virtual void Display(bool auto_redraw = true);

	virtual void Start(void);
	virtual void Finalize(void);
	virtual void Update(void);
	virtual void Reshape(int width, int height);
};

