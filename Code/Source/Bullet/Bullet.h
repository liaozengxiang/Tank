#ifndef ___BULLET__20150123___
#define ___BULLET__20150123___

#include "../Core/Flyable.h"
#include "../Core/Sprite.h"

class CBullet : public CFlyable
{
public:
	CBullet(HTEXTURE hTexture, int x, int y, int w, int h, int nSpeed, EDirection eDirection, const RECT *pFlyableRect);
	virtual ~CBullet();

public:
	virtual void OnFrame(float fDelta);
	virtual void OnRender();

protected:
	CSprite*					m_pSprite;
};

#endif
