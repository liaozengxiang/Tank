#include "Object.h"

CObject::CObject()
{
	m_nPosX   = 0;
	m_nPosY   = 0;
	m_nWidth  = 0;
	m_nHeight = 0;
	m_bShow   = true;
}

CObject::~CObject()
{
}

void CObject::AddChild(CObject *pChild)
{
	m_childrenSet.insert(pChild);
}

void CObject::RemoveChild(CObject *pChild)
{
	m_childrenSet.erase(pChild);
}

void CObject::MoveTo(int x, int y)
{
	m_nPosX = x;
	m_nPosY = y;
}

void CObject::Offset(int dx, int dy)
{
	m_nPosX += dx;
	m_nPosY += dy;
}

void CObject::SetWidth(int nWidth)
{
	m_nWidth = nWidth;
}

void CObject::SetHeight(int nHeight)
{
	m_nHeight = nHeight;
}

void CObject::OnFrame(float fDelta)
{
	if (m_bShow)
	{
		std::set<CObject *>::const_iterator it = m_childrenSet.begin();
		for (; it != m_childrenSet.end(); ++it)
		{
			(*it)->OnFrame(fDelta);
		}
	}
}

void CObject::OnRender()
{
	if (m_bShow)
	{
		std::set<CObject *>::const_iterator it = m_childrenSet.begin();
		for (; it != m_childrenSet.end(); ++it)
		{
			(*it)->OnRender();
		}
	}
}

void CObject::OnKey(int nKey)
{
	if (m_bShow)
	{
		std::set<CObject *>::const_iterator it = m_childrenSet.begin();
		for (; it != m_childrenSet.end(); ++it)
		{
			(*it)->OnKey(nKey);
		}
	}
}

bool CObject::HitTest(CObject *pOther) const
{
	RECT rect1;
	rect1.left   = m_nPosX;
	rect1.top    = m_nPosY;
	rect1.right  = rect1.left + m_nWidth;
	rect1.bottom = rect1.top + m_nHeight;

	RECT rect2;
	rect2.left   = pOther->m_nPosX;
	rect2.top    = pOther->m_nPosY;
	rect2.right  = rect2.left + pOther->m_nWidth;
	rect2.bottom = rect2.top + pOther->m_nHeight;

	RECT rect;
	return IntersectRect(&rect, &rect1, &rect2) ? true : false;
}
