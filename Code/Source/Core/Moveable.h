#ifndef ___MOVEABLE__20150123___
#define ___MOVEABLE__20150123___

#include "Object.h"

class CMoveable : public CObject
{
public:
	enum EDirection	{ UP, RIGHT, DOWN, LEFT };

public:
	CMoveable(int nSpeed, EDirection eDirection, const RECT *pMoveableRect);
	virtual ~CMoveable();

public:
	void AcceptDirection(EDirection eDirection);

protected:
	int					m_nSpeed;						// 每次按键运动的像素
	EDirection			m_eDirection;					// 当前运动的方向
	RECT				m_moveableRect;
};

#endif
