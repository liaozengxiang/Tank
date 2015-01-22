#include "Tank.h"
#include "../Core/Application.h"

CTank::CTank(const char *lpszTankImage, int x, int y, int nWidth, int nHeight)
{
	m_hTexture = CApplication::LoadTexture(lpszTankImage);

	SetWidth(nWidth);
	SetHeight(nHeight);

	m_vecSprite.reserve(4);
	for (int i = 0; i < 4; ++i)
	{
		CSprite *pSprite = new CSprite(m_hTexture, x, y + i * nHeight, nWidth, nHeight);
		m_vecSprite.push_back(pSprite);

		pSprite->SetWidth(nWidth);
		pSprite->SetHeight(nHeight);
	}

	m_eDirection = TANK_DIRECTION::DOWN;
}

CTank::~CTank()
{
}

void CTank::ChangeDirection(TANK_DIRECTION::ETankDirection eDirection)
{
	if (m_eDirection != eDirection)
	{
		m_vecSprite[eDirection]->MoveTo(m_nPosX, m_nPosY);
		m_eDirection = eDirection;
	}
	else
	{
		int nOffset = GetWidth() / 4;
		if (eDirection == TANK_DIRECTION::UP)
		{
			m_vecSprite[m_eDirection]->Offset(0, -nOffset);
			Offset(0, -nOffset);
		}
		else if (eDirection == TANK_DIRECTION::DOWN)
		{
			m_vecSprite[m_eDirection]->Offset(0, nOffset);
			Offset(0, nOffset);
		}
		else if (eDirection == TANK_DIRECTION::LEFT)
		{
			m_vecSprite[m_eDirection]->Offset(-nOffset, 0);
			Offset(-nOffset, 0);
		}
		else
		{
			m_vecSprite[m_eDirection]->Offset(nOffset, 0);
			Offset(nOffset, 0);
		}
		
	}
}

void CTank::OnFrame(float fDelta)
{
	CObject::OnFrame(fDelta);
}

void CTank::OnRender()
{
	m_vecSprite[m_eDirection]->OnRender();
}

void CTank::OnKey(int nKey)
{
	if (nKey == HGEK_UP)
	{
		ChangeDirection(TANK_DIRECTION::UP);
	}
	else if (nKey == HGEK_RIGHT)
	{
		ChangeDirection(TANK_DIRECTION::RIGHT);
	}
	else if (nKey == HGEK_DOWN)
	{
		ChangeDirection(TANK_DIRECTION::DOWN);
	}
	else if (nKey == HGEK_LEFT)
	{
		ChangeDirection(TANK_DIRECTION::LEFT);
	}
}
