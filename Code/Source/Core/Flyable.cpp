#include "Flyable.h"

CFlyable::CFlyable(int nSpeed, EDirection eDirection, const RECT *pFlyableRect)
{
	m_nSpeed      = nSpeed;
	m_eDirection  = eDirection;
	m_flyableRect = *pFlyableRect;
}

CFlyable::~CFlyable()
{
}

void CFlyable::OnFrame(float fDelta)
{
	CObject::OnFrame(fDelta);
	
	POINT pt;
	pt.x = m_nPosX;
	pt.y = m_nPosY;
	int nOffset = fDelta * m_nSpeed;
	if (m_eDirection == UP)
	{
		pt.y -= nOffset;
	}
	else if (m_eDirection == RIGHT)
	{
		pt.x += nOffset;
	}
	else if (m_eDirection == DOWN)
	{
		pt.y += nOffset;
	}
	else if (m_eDirection == LEFT)
	{
		pt.x -= nOffset;
	}

	if (PtInRect(&m_flyableRect, pt))
	{
		m_nPosX = pt.x;
		m_nPosY = pt.y;
	}
}
