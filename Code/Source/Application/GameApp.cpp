#include "GameApp.h"
#include "../Core/Sprite.h"

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

bool CGameApp::InitInstance()
{
	HTEXTURE hTex = m_pHGE->Texture_Load("Resource/Image/Splash.bmp");
	CSprite *pSpr = new CSprite(hTex, 0, 0, 376, 222);

	AddChild(pSpr);
	pSpr->MoveTo((800 - pSpr->GetWidth()) / 2, (600 - pSpr->GetHeight()) / 2);

	return true;
}
