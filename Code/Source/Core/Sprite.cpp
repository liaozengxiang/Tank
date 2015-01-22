#include "Sprite.h"

#pragma comment(lib, "../Source/hge181/lib/vc/hgehelp.lib")

CSprite::CSprite(HTEXTURE hTexture, int x, int y, int w, int h)
{
	m_pSprite = new hgeSprite(hTexture, x, y, w, h);
	SetWidth(w);
	SetHeight(h);
}

CSprite::~CSprite()
{
	delete m_pSprite;
	m_pSprite = NULL;
}

void CSprite::OnRender()
{
	m_pSprite->Render(m_nPosX, m_nPosY);
}
