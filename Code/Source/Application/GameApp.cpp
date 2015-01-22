#include "GameApp.h"

// 定义全局唯一应用程序实例对象
CGameApp theApp;

CGameApp::CGameApp()
{
}

CGameApp::~CGameApp()
{
}

void CGameApp::OnSetTitle(std::string &strAppTitle)
{
	strAppTitle = "坦克大战网络版";
}
