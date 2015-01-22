#ifndef ___OBJECT__20150122___
#define ___OBJECT__20150122___

#pragma warning(disable : 4786)
#include <set>

class CObject
{
public:
	void AddChild(CObject *pChild);
	void RemoveChild(CObject *pChild);

protected:
	virtual void OnFrame(float fDelta);
	virtual void OnRender();

protected:
	std::set<CObject *>			m_childrenSet;
};

#endif
