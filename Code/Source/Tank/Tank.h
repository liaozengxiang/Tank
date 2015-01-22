#ifndef ___TANK__20150122___
#define ___TANK__20150122___

#include "../Core/Sprite.h"
#include <vector>

namespace TANK_DIRECTION
{
	enum ETankDirection { UP, RIGHT, DOWN, LEFT };
}

class CTank : public CObject
{
public:
	CTank(const char *lpszTankImage, int x, int y, int nWidth, int nHeight);
	virtual ~CTank();

public:
	void ChangeDirection(TANK_DIRECTION::ETankDirection eDirection);

protected:
	virtual void OnFrame(float fDelta);
	virtual void OnRender();
	virtual void OnKey(int nKey);

protected:
	HTEXTURE							m_hTexture;				// 坦克的纹理，从上至下为: 坦克向上、坦克向右、坦克向下、坦克向左
	TANK_DIRECTION::ETankDirection		m_eDirection;			// 坦克目前的方向
	std::vector<CSprite *>				m_vecSprite;			// 4 个方向的坦克精灵
};

#endif
