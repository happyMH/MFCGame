
// ChildView.h : CChildView ��Ľӿ�
//


#pragma once
#include "Hero.h"
#include "Map.h"
#include "Snow.h"


// CChildView ����

class CChildView : public CWnd
{
// ����
public:
	CChildView();

public:
//�������������һ������

// ����
public:
	Hero m_hero;
	Map m_map;
	Snow snow;
	CRect m_client;            //����ͻ�����С	
	CDC m_cacheDC;                //����DC
	CBitmap m_cacheBitmap;        //����λͼ

	int count;

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:

	//��Ӧ
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//��ʱ
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//��Ļ��ַ
	void GetMapStartX();
	int GetScreenX(int xHero, int mapWidth);

};

