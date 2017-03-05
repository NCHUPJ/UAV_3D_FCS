#pragma once
#include "afxwin.h"


#include "../protocol/FCToPCProtocolConvertToRealData.h"

#include <cmath>
#include "../MemoryDC.h"

class CHUD :
	public CWnd
{
public:
	CHUD();
	~CHUD();

private:
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
public:
	//更新控件数据
	void SetCurrentData(const TSPIDC& tspidc);
	//为绘制控件做准备
	void DrawStaticPrepare(CDC* p_dc);
	//绘制静态背景
	void DrawStaticBackground(CDC *pDC);
	//绘制动态背景
	void DrawDynamicBackground(CDC *pDC);

	DECLARE_MESSAGE_MAP()
	//绘制控件
	afx_msg void OnPaint();	
};

