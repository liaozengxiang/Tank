#ifndef ___TANK__20150122___
#define ___TANK__20150122___

#include "../Core/Sprite.h"
#include "../Core/Moveable.h"
#include "../Bullet/Bullet.h"
#include <vector>

class CTank : public CMoveable
{
public:
	CTank(const char *lpszTankImage, int x, int y, int nWidth, int nHeight, int nSpeed, const RECT *pMoveableRect);
	virtual ~CTank();

protected:
	virtual void OnFrame(float fDelta);
	virtual void OnRender();
	virtual void OnKey(int nKey);

protected:
	HTEXTURE							m_hTexture;				// 坦克的纹理，二列从上至下为: 坦克向上、坦克向右、坦克向下、坦克向左
	std::vector<CSprite *>				m_vecSprite[2];			// 4 个方向的坦克精灵
	int									m_nShowIndex;			// 当前显示的是第几组，由 0-1 变换
	CBullet*							m_pBullets[2];
};

#endif
