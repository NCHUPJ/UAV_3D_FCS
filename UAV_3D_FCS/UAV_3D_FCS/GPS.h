#pragma once
#include "afxwin.h" 

#include "UavView.h"

class CGPS :
	public CUavView
{
public:
	CGPS();
	~CGPS();
private:
	//double m_LOTD = 0.0;                   //即时经度  7、8、9、10
	//double m_LATD = 0.0;                   //即时纬度  11、12、13、14
	//double m_SPH = 0.0;                    //标准气压高度  15、16
	//double m_PRH = 0.0;                    //气压修正高度  17、18
	//double m_RH = 0.0;                     //无线电高度  19、20
private:
	////用于存放控件区域矩形大小的变量
	//CRect       m_rectCtrl;

	////缓冲区内绘制背景的虚拟DC
	//CDC			m_dcPlate;

	////在缓冲区中将图形绘制到此位图中
	//CBitmap		m_bitmapPlate;

	////旧的位置指针
	//CBitmap     *m_pbitmapOldPlate;

	////是否需要重绘静态背景
	//bool m_reqRedrawStaticBgd = true;
public:
	//更新控件数据
	//void SetCurrentData(const TSPIDC& tspidc);
	//为绘制控件做准备
	//void DrawStaticPrepare(CDC* p_dc);
	
	//绘制静态背景
	virtual void DrawStaticBackground(CDC *pDC);
	//绘制动态背景
	virtual void DrawDynamicBackground(CDC *pDC);
	//DECLARE_MESSAGE_MAP()
	//afx_msg void OnPaint();
};

