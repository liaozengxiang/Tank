/*
 * class CApplication
 * Copyright (C) 2015. All rights reserved.
 */

#ifndef ___APPLICATION__20150122___
#define ___APPLICATION__20150122___

#include "../hge181/include/hge.h"

class CApplication
{
public:
	CApplication();
	virtual ~CApplication();

	bool Initialize();
	bool Start();

protected:
	bool InitHGE();
	virtual bool InitInstance();
	virtual void ExitInstance();

protected:
	static bool FrameFunc();
	static bool RenderFunc();
	static bool ExitFunc();

	void OnFrame();
	void OnRender();

protected:
	HGE*					m_pHGE;
};

// 声明全局应用程序实例对象
extern CApplication theApp;

#endif
