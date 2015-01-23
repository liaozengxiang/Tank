#include "Bullet.h"

CBullet::CBullet(HTEXTURE hTexture, int x, int y, int w, int h, int nSpeed, EDirection eDirection, const RECT *pFlyableRect)
	: CFlyable(nSpeed, eDirection, pFlyableRect)
{
	m_pSprite = new CSprite(hTexture, x, y, w, h);
}

CBullet::~CBullet()
{
}

void CBullet::OnFrame(float fDelta)
{
	CFlyable::OnFrame(fDelta);
	m_pSprite->MoveTo(m_nPosX, m_nPosY);
}

void CBullet::OnRender()
{
	m_pSprite->OnRender();
}
