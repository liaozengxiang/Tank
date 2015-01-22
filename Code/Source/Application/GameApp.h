#ifndef ___GAME__APP__20150122___
#define ___GAME__APP__20150122___

#include "../Core/Application.h"

class CGameApp : public CApplication
{
public:
	CGameApp();
	virtual ~CGameApp();

protected:
	virtual bool OnInitInstance(STARTUP_INFO *pInfo);
	virtual bool OnInitResource();
};

// 声明全局应用程序实例对象
extern CGameApp theApp;

#endif
