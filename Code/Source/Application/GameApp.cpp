#include "GameApp.h"
#include "../Resource/resource.h"
#include "../Core/Sprite.h"
#include "../Tank/Tank.h"
#include "../Bullet/Bullet.h"

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
	pInfo->strTitle    = "坦克大战网络版";
	pInfo->nIcon       = IDI_MAIN;
	pInfo->bHideMouse  = false;
	pInfo->bShowSplash = false;
	pInfo->nFPS        = 80;

	return true;
}

bool CGameApp::OnInitResource()
{
	// 背景
	HTEXTURE hTexture = m_pHGE->Texture_Load("Resource/Image/Splash.bmp");
	CSprite *pSpr = new CSprite(hTexture, 0, 0, 376, 222);
	
	AddChild(pSpr);
	pSpr->MoveTo((800 - pSpr->GetWidth()) / 2, (600 - pSpr->GetHeight()) / 2);

	// 玩家 1
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = 800;
	rect.bottom = 600;
	CTank *pTank = new CTank("Resource/Image/Player1.bmp", 2*3*28, 0, 28, 28, 1, &rect);
	AddChild(pTank);

	return true;
}
