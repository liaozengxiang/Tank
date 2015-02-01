#include "Tank.h"
#include "../Core/Application.h"

CTank::CTank(const char *lpszTankImage, int x, int y, int nWidth, int nHeight, int nSpeed, const RECT *pMoveableRect)
	: CMoveable(nSpeed, CMoveable::DOWN, pMoveableRect)
{
	m_hTexture = CApplication::LoadTexture(lpszTankImage);

	SetWidth(nWidth);
	SetHeight(nHeight);

	m_vecSprite[0].reserve(4);
	m_vecSprite[1].reserve(4);
	for (int i = 0; i < 4; ++i)
	{
		CSprite *pSprite1 = new CSprite(m_hTexture, x, y + i * nHeight, nWidth, nHeight);
		m_vecSprite[0].push_back(pSprite1);

		pSprite1->SetWidth(nWidth);
		pSprite1->SetHeight(nHeight);

		CSprite *pSprite2 = new CSprite(m_hTexture, x + nWidth, y + i * nHeight, nWidth, nHeight);
		m_vecSprite[1].push_back(pSprite2);
		
		pSprite2->SetWidth(nWidth);
		pSprite2->SetHeight(nHeight);
	}

	m_nShowIndex = 0;

	m_pBullets[0] = NULL;
	m_pBullets[1] = NULL;
}

CTank::~CTank()
{
}

void CTank::OnFrame(float fDelta)
{
	CObject::OnFrame(fDelta);

	if (m_pBullets[0] != NULL)
	{
		RECT rect = { 0, 0, 800-8-1, 600-8-1 };
		POINT pt = { m_pBullets[0]->GetLeft(), m_pBullets[0]->GetTop() };

		if (!PtInRect(&rect, pt))
		{
			RemoveChild(m_pBullets[0]);
			delete m_pBullets[0];
			m_pBullets[0] = NULL;
		}
	}
}

void CTank::OnRender()
{
	CObject::OnRender();
	m_vecSprite[m_nShowIndex][m_eDirection]->OnRender();
}

void CTank::OnKey(int nKey)
{
	if (nKey == HGEK_UP)
	{
		AcceptDirection(CMoveable::UP);
		m_vecSprite[m_nShowIndex][m_eDirection]->MoveTo(m_nPosX, m_nPosY);
	}
	else if (nKey == HGEK_RIGHT)
	{
		AcceptDirection(CMoveable::RIGHT);
		m_vecSprite[m_nShowIndex][m_eDirection]->MoveTo(m_nPosX, m_nPosY);
	}
	else if (nKey == HGEK_DOWN)
	{
		AcceptDirection(CMoveable::DOWN);
		m_vecSprite[m_nShowIndex][m_eDirection]->MoveTo(m_nPosX, m_nPosY);
	}
	else if (nKey == HGEK_LEFT)
	{
		AcceptDirection(CMoveable::LEFT);
		m_vecSprite[m_nShowIndex][m_eDirection]->MoveTo(m_nPosX, m_nPosY);
	}

	if (nKey == HGEK_CTRL)
	{
		if (m_pBullets[0] == NULL)
		{
			// ×Óµ¯
			RECT rect;
			rect.left = 0;
			rect.top = 0;
			rect.right = 800;
			rect.bottom = 600;

			HGE *pHGE = hgeCreate(HGE_VERSION);
			HTEXTURE hTexture = pHGE->Texture_Load("Resource/Image/Bullet.bmp");
			CBullet *pBullet = new CBullet(hTexture, 2*8, 0, 8, 8, 300, (CFlyable::EDirection)(int)m_eDirection, &rect);
			pBullet->MoveTo(m_nPosX + m_nWidth / 2 - pBullet->GetWidth() / 2, m_nPosY + m_nHeight / 2 - pBullet->GetHeight() / 2);
			AddChild(pBullet);

			pHGE->Release();
			m_pBullets[0] = pBullet;
		}
	}
}
