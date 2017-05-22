
// ChildView.h : CChildView 类的接口
//


#pragma once
#include "Hero.h"
#include "Map.h"
#include "Snow.h"


// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

public:
//定义变量，定义一个矩形

// 特性
public:
	Hero m_hero;
	Map m_map;
	Snow snow;
	CRect m_client;            //保存客户区大小	
	CDC m_cacheDC;                //缓冲DC
	CBitmap m_cacheBitmap;        //缓冲位图

	int count;

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:

	//相应
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//计时
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//屏幕地址
	void GetMapStartX();
	int GetScreenX(int xHero, int mapWidth);

};

