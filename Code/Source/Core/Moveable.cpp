#include "Moveable.h"

CMoveable::CMoveable(int nSpeed, EDirection eDirection, const RECT *pMoveableRect)
{
	m_nSpeed       = nSpeed;
	m_eDirection   = eDirection;
	m_moveableRect = *pMoveableRect;
}

CMoveable::~CMoveable()
{
}

void CMoveable::AcceptDirection(EDirection eDirection)
{
	if (m_eDirection == eDirection)
	{
		POINT pt;
		pt.x = m_nPosX;
		pt.y = m_nPosY;
		if (eDirection == UP)
		{
			pt.y -= m_nSpeed;
		}
		else if (eDirection == RIGHT)
		{
			pt.x += m_nSpeed;
		}
		else if (eDirection == DOWN)
		{
			pt.y += m_nSpeed;
		}
		else if (eDirection == LEFT)
		{
			pt.x -= m_nSpeed;
		}

		if (PtInRect(&m_moveableRect, pt))
		{
			m_nPosX = pt.x;
			m_nPosY = pt.y;
		}
	}
	else
	{
		m_eDirection = eDirection;
	}
}
