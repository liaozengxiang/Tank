#include "GameApp.h"
#include "../Resource/resource.h"
#include "../Core/Sprite.h"

// 定义全局唯一应用程序实例对象
CGameApp theApp;

CGameApp::CGameApp()
{
}

CGameApp::~CGameApp()
{
}

bool CGameApp::OnInitInstance(STARTUP_INFO *pInfo)
{
	pInfo->strTitle   = "坦克大战网络版";
	pInfo->nIcon      = IDI_MAIN;
	pInfo->bHideMouse = true;

	return true;
}

bool CGameApp::OnInitResource()
{
	HTEXTURE hTexture = m_pHGE->Texture_Load("Resource/Image/Splash.bmp");
	CSprite *pSpr = new CSprite(hTexture, 0, 0, 376, 222);
	
	AddChild(pSpr);
	pSpr->MoveTo((800 - pSpr->GetWidth()) / 2, (600 - pSpr->GetHeight()) / 2);

	return true;
}
