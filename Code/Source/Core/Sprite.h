/*
 * class CSprite
 * Copyright (C) 2015. All rights reserved.
 */

#ifndef ___SPRITE__20150122___
#define ___SPRITE__20150122___

#include "Object.h"
#include "../hge181/include/hgesprite.h"

class CSprite : public CObject
{
public:
	CSprite(HTEXTURE hTexture, int x, int y, int w, int h);
	virtual ~CSprite();

public:
	virtual void OnRender();

protected:
	hgeSprite*				m_pSprite;
};

#endif
