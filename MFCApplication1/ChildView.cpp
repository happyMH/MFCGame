
// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ChildView.h"
#include "Resource.h"
#include <iostream>
#include "Hero.h"
#include "Map.h"
#include <random>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//��ʱ��������
#define TIMER_PAINT 1
#define TIMER_HEROMOVE 2

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CChildView ��Ϣ�������

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	//���ر���--�ذ�
	CString backGround_file_name("backGround_1.png");
	m_map.Initialzation(backGround_file_name);

	//��������--Ӣ��
	CString hero_file_name("maliao.png");
	m_hero.Initialzation(hero_file_name);


	//����Ч��--ѩ��ͼ��
	CString cstrings[7];
	for (int i = 0; i < 7; i++)
	{
		char buf[20];
		sprintf_s(buf, "snow1_0%d.png", i);
		cstrings[i] = buf;
	}
	snow.Initialzation(cstrings, 7);

	//����Ч��--ѩ��λ�ó�ʼ��
	for (int i = 0; i < snow.number; i++)
	{
		snow.snows[i].x = rand() % 1000;
		snow.snows[i].y = rand() % 750;
		snow.snows[i].number = rand() % 7;

	}
	
	count = 0;
	
	return TRUE;
}

void CChildView::OnPaint() 
{
	//��õ�ǰ���ڵ�DCָ��         
	CDC *cDc = this->GetDC();   

	//��ô��ڵĴ�С
	GetClientRect(&m_client);         

	//��������DC
	m_cacheDC.CreateCompatibleDC(NULL);
	m_cacheBitmap.CreateCompatibleBitmap(cDc, m_client.Width(), m_client.Height());
	m_cacheDC.SelectObject(&m_cacheBitmap);
	
	GetMapStartX();
	//��һ��������һ������--------------------------------------------
	m_map.backGround.Draw(m_cacheDC, 0, 0, m_client.Width(), m_client.Height(), m_map.xMapStart, 0, m_client.Width(), m_client.Height());

	//�ڶ���������һ������--------------------------------------------
	m_hero.hero.Draw(m_cacheDC, GetScreenX(m_hero.x,m_map.mapWidth),m_hero.y,m_hero.width, m_hero.heigth ,m_hero.frame * m_hero.width, (m_hero.direct % 2) * m_hero.heigth, m_hero.width, m_hero.heigth);

	//������������ѩ��------------------------------------------------
	for (int i = 0; i < snow.number; i++)
	{
		snow.snow_images[snow.snows[i].number].Draw(m_cacheDC, snow.snows[i].x, snow.snows[i].y, snow.snow_images[snow.snows[i].number].GetWidth(), snow.snow_images[snow.snows[i].number].GetHeight());
		snow.snows[i].y += 1;
		if (snow.snows[i].y >= 600)
			snow.snows[i].y = 0;
		if (rand() % 2 == 0)
			snow.snows[i].x += 1;
		else
			snow.snows[i].x -= 1;

		if (snow.snows[i].x < 0)
			snow.snows[i].x = m_client.Width();
		else if (snow.snows[i].x > m_client.Width())
			snow.snows[i].x = 0;
	}

	//����DC���������DC��
	cDc->BitBlt(0, 0, m_client.Width(), m_client.Height(), &m_cacheDC, 0, 0, SRCCOPY);

	//�ڻ�����ͼ��ʹ��������Ч
	ValidateRect(&m_client);

	//�ͷŻ���DC
	m_cacheDC.DeleteDC();

	//�ͷŶ���
	m_cacheBitmap.DeleteObject();

	//�ͷ�DC
	ReleaseDC(cDc);	
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//nChar��ʾ���µļ�ֵ
	switch (nChar)
	{
	case 'd':
	case 'D':
		m_hero.direct = Right;
		m_hero.frame = (m_hero.frame + 1) % 2;
		m_hero.x += m_hero.speed;
		break;
	case 'a':
	case 'A':
		m_hero.direct = Left;
		m_hero.frame = (m_hero.frame + 1) % 2;
		m_hero.x -= m_hero.speed;
		break;
	case 'w':
	case 'W':
		m_hero.direct = Up;
		m_hero.y -= m_hero.speed;
		break;
	case 's':
	case 'S':
		m_hero.direct = Down;
		m_hero.y += m_hero.speed;
		break;
	case 't':
	case 'T':
		SetTimer(TIMER_HEROMOVE, 100, NULL);     //������ʱ��
		break;
	case 'i':
	case 'I':
		KillTimer(TIMER_HEROMOVE);               //������ʱ��
	}
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_hero.x = point.x;
	m_hero.y = point.y;
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case TIMER_PAINT:OnPaint(); 
		break;
	case TIMER_HEROMOVE:
		{
			if (count % 50 == 0)
				m_hero.direct = (m_hero.direct + 1) % 2;

			//���ߵĻ���
			m_hero.frame++;

			//���ߵľ���
			switch (m_hero.direct)
			{
			case Left:
				m_hero.x -= m_hero.speed;
				break;
			case Right:
				m_hero.x += m_hero.speed;
				break;
			case Up:
				m_hero.y -= m_hero.speed;
				break;
			case Down:
				m_hero.y += m_hero.speed;
				break;
			}

			if (m_hero.frame == 2)
				m_hero.frame = 0;

			count++;
		}
		break;
	}
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//����һ��10ms����һ����Ϣ�Ķ�ʱ��
	SetTimer(TIMER_PAINT, 10, NULL);
	//�����������߶�����ʱ��
	SetTimer(TIMER_HEROMOVE, 200, NULL);

	return 0;
}

void CChildView::GetMapStartX()
{
	if (m_hero.x < m_map.mapWidth - m_client.Width() / 2 && m_hero.x > m_client.Width() / 2)
		m_map.xMapStart = m_hero.x - m_client.Width() / 2;

}

int CChildView::GetScreenX(int xHero, int mapWidth)
{
	//������ﲻ������ߺ����ұ߰����Ļ��ʱ����ô����ʹ�����Ļ�м�
	if (xHero < mapWidth - m_client.Width() / 2 && xHero > m_client.Width() / 2)
		return m_client.Width() / 2;
	else if (xHero <= m_client.Width() / 2)
		return xHero;
	else
		return m_client.Width() - (mapWidth - xHero);
}
