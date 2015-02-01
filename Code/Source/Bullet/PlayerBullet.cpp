#include "PlayerBullet.h"

CPlayerBullet::CPlayerBullet()
{
	m_nLevel = 1;
}

CPlayerBullet::~CPlayerBullet()
{
	std::vector<CBullet *>::const_iterator it = m_vecBullets.begin();
	for (; it != m_vecBullets.end(); ++it)
	{
		delete *it;
	}

	m_vecBullets.clear();
}

void CPlayerBullet::Fire(CFlyable::EDirection eDirection)
{
	int nMaxBullets = 1;
	if (m_nLevel == 4)
	{
		nMaxBullets = 2;
	}

	if (m_vecBullets.size() < nMaxBullets)
	{
//		CBullet *pBullet = new CBullet(m_hTexture, x, y, w, h, nSpeed, eDirection, rect);
//		m_vecBullets.push_back(pBullet);
	}
}

void CPlayerBullet::Upgrade()
{
	if (m_nLevel < 4)
	{
		++m_nLevel;
	}
}

void CPlayerBullet::OnFrame(float fDelta)
{

}

void CPlayerBullet::OnRender()
{

}
 