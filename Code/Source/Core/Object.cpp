#include "Object.h"

void CObject::AddChild(CObject *pChild)
{
	m_childrenSet.insert(pChild);
}

void CObject::RemoveChild(CObject *pChild)
{
	m_childrenSet.erase(pChild);
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
