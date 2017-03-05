#pragma once

#include <cmath>

#include "afxwin.h"
#include "protocol/FCToPCProtocolConvertToRealData.h"
#include "MemoryDC.h"

class CUavView :
	public CWnd
{
public:
	CUavView();
	~CUavView();

protected:
	TSPIDC m_TSPIDC;			//数据包

	//用于存放控件区域矩形大小的变量
	CRect       m_rectCtrl;

	//缓冲区内绘制背景的虚拟DC
	CDC			m_dcPlate;

	//在缓冲区中将图形绘制到此位图中
	CBitmap		m_bitmapPlate;

	//旧的位置指针
	CBitmap     *m_pbitmapOldPlate;

	//是否需要重绘静态背景
	bool m_reqRedrawStaticBgd = true;


	
	//为绘制控件做准备
	void DrawStaticPrepare(CDC* pDC);
	
	//绘制静态背景,子类必须重写
	virtual void DrawStaticBackground(CDC *pDC) = 0;
	
	//绘制动态背景,子类必须重写
	virtual void DrawDynamicBackground(CDC *pDC) = 0;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

public:
	//更新控件数据
	void SetCurrentData(const TSPIDC& tspidc);
};

