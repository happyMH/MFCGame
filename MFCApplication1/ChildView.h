
// ChildView.h : CChildView ��Ľӿ�
//


#pragma once
#include "Map.h"
#include "Snow.h"
#include "Character.h"


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
	Character m_hero;
	Character m_monster;
	Map m_map;
	Map m_map_mask;
	Snow snow;
	CRect m_client;            //����ͻ�����С	
	CDC m_cacheDC;                //����DC
	CBitmap m_cacheBitmap;        //����λͼ

	int count;
	int count_monster;

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
	//��ʼ��
	void Initialize();
	//��Ӧ
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//��ʱ
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//��Ļ��ַ
	void GetMapStartX();
	void GetMapStartY();
	int GetScreenHeroX(int xHero, int mapWidth);
	int GetScreenHeroY(int yHero, int mapHeight);
	int GetScreenMonsterX(int xMonster, int xHero);
	//�����ƶ�
	void Move_Monster();
	//�ж���ײ
	bool Is_Hit();
	//�ж��Ƿ���ͨ��
	bool Can_Pass(const Character &character);

};

