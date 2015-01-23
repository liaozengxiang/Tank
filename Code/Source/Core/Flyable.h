#ifndef ___FLYABLE__20150123___
#define ___FLYABLE__20150123___

#include "Object.h"

class CFlyable : public CObject
{
public:
	enum EDirection	{ UP, RIGHT, DOWN, LEFT };
	
public:
	CFlyable(int nSpeed, EDirection eDirection, const RECT *pFlyableRect);
	virtual ~CFlyable();
	
public:
	void SetDirection(EDirection eDirection);
	
public:
	virtual void OnFrame(float fDelta);
	
protected:
	int					m_nSpeed;						// 每秒运动的速率，单位为 pixel/s
	EDirection			m_eDirection;					// 当前运动的方向
	RECT				m_flyableRect;
};

#endif
