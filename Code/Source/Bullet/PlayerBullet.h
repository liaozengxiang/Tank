#ifndef ___PLAYER__BULLET__20150126___
#define ___PLAYER__BULLET__20150126___

#include "Bullet.h"
#include <vector>

class CPlayerBullet : public CObject
{
public:
	CPlayerBullet();
	virtual ~CPlayerBullet();

public:
	void Fire(CFlyable::EDirection eDirection);
	void Upgrade();

	virtual void OnFrame(float fDelta);
	virtual void OnRender();

private:
	int						m_nLevel;				// 子弹的火力等级
	std::vector<CBullet *>	m_vecBullets;			// 玩家拥有的子弹
};

#endif
