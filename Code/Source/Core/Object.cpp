#include "Object.h"

CObject::CObject()
{
	m_nPosX   = 0;
	m_nPosY   = 0;
	m_nWidth  = 0;
	m_nHeight = 0;
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
	std::set<CObject *>::const_iterator it = m_childrenSet.begin();
	for (; it != m_childrenSet.end(); ++it)
	{
		(*it)->OnFrame(fDelta);
	}
}

void CObject::OnRender()
{
	std::set<CObject *>::const_iterator it = m_childrenSet.begin();
	for (; it != m_childrenSet.end(); ++it)
	{
		(*it)->OnRender();
	}
}
