/*
 * class CApplication
 * Copyright (C) 2015. All rights reserved.
 */

#ifndef ___APPLICATION__20150122___
#define ___APPLICATION__20150122___

#include "../hge181/include/hge.h"
#include "Object.h"
#include <string>

struct STARTUP_INFO
{
	int				nWidth;					// 窗口宽度
	int				nHeight;				// 窗口高度
	bool			bWindowed;				// 窗口显示还是全屏显示
	std::string		strTitle;				// 应用程序标题
	bool			bHideMouse;				// 是否隐藏鼠标
	bool			bShowSplash;			// 是否显示 hge 的欢迎界面
	int				nFPS;					// 游戏显示帧频
	int				nIcon;					// 应用程序图标资源 ID
};

class CApplication : public CObject
{
public:
	CApplication();
	virtual ~CApplication();

	bool Initialize();
	bool Start();

public:
	static HTEXTURE LoadTexture(const char *lpszImage);

protected:
	virtual bool OnInitInstance(STARTUP_INFO *pInfo);
	virtual void OnExitInstance();
	virtual bool OnInitResource();
	virtual void OnFrame(float fDelta);
	virtual void OnRender();

protected:
	static CApplication* GetInstance() { return m_pInstance; }
	static bool FrameFunc();
	static bool RenderFunc();
	static bool ExitFunc();

protected:
	bool InitHGE();

protected:
	static CApplication*	m_pInstance;					// 全局唯一应用程序实例指针
	HGE*					m_pHGE;							// hge 引擎指针
	STARTUP_INFO			m_startupInfo;					// 启动参数
};

#endif
