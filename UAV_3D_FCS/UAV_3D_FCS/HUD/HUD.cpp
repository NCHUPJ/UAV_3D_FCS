#include "stdafx.h"
#include "../stdafx.h"
#include "HUD.h"


CHUD::CHUD()
{
}


CHUD::~CHUD()
{
}


/*! @function
********************************************************************************
* 函数名   : SetCurrentData
* 功能     : 留给HUD控制器的接口，用来设置HUD控件的数据
* 参数     : tspidc 从HUDViewControl发送来的数据包
* 返回值   : void
* 作者     : 陈登龙 南昌航空大学信息工程学院自动控制系
* 日期     : 2017-03-04
*******************************************************************************/
void CHUD::SetCurrentData(const TSPIDC& tspidc)
{ 
	//数据更新赋值
	m_TSPIDC.m_ANGP = tspidc.m_ANGP;


	//重绘
	Invalidate();
}



BEGIN_MESSAGE_MAP(CHUD, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


/*! @function
********************************************************************************
* 函数名   : OnPaint
* 功能     : 绘图函数
* 参数     : void
* 返回值   : void 
* 备注     : 所有的绘图操作都应该在这个函数中完成，使用双缓存技术(MemoryDC.h)
			 防止屏幕闪烁,先绘制静态部分，再绘制动态部分。
*******************************************************************************/
void CHUD::OnPaint()
{
	CPaintDC dc(this);  

	//将对话框中静态文本框控件的大小坐标赋给m_rectCtrl
	GetClientRect(&m_rectCtrl);

	//memDC为一虚拟的dc，在CMemoryDC类的构造函数中将实际的dc
	CMemoryDC memDC(&dc, &m_rectCtrl);

	if (m_reqRedrawStaticBgd)
	{ 
		//在缓冲区内绘制HUD静态图形
		if ((m_dcPlate == nullptr) || (m_bitmapPlate.m_hObject == nullptr))
		{
			//创建一个和实际dc匹配的虚拟设备描述表(m_dcHudPlate)
			m_dcPlate.CreateCompatibleDC(&dc);

			DrawStaticPrepare(&dc);
		}
		else
		{
			m_dcPlate.DeleteDC();
			//创建一个和实际dc匹配的虚拟设备描述表(m_dcHudPlate)
			m_dcPlate.CreateCompatibleDC(&dc);
			m_bitmapPlate.DeleteObject();

			DrawStaticPrepare(&dc);
		}

		//在位图m_bitmapHUDPlate中利用虚拟dc(m_dcHUDPlate)绘制HUD静态背景
		DrawStaticBackground(&m_dcPlate);

		//只需要绘制一次静态背景，如果拖出界面不能重新显示静态背景，就去掉这个标记
		m_reqRedrawStaticBgd = false;
	}
	

	//将缓冲区内绘制完成的位图一次性拷贝到显示屏中显示
	memDC.BitBlt(0, 0, m_rectCtrl.Width(), m_rectCtrl.Height(), &m_dcPlate, 0, 0, SRCCOPY);

	//动态背景需要重复绘制，才能实现动画效果
	DrawDynamicBackground(&memDC);
}




 
/*! @function
********************************************************************************
* 函数名   : DrawStaticPrepare
* 功能     : 绘图函数
* 参数     : void
* 返回值   : void
* 备注     : 绘制控件的静态部分
*******************************************************************************/
void CHUD::DrawStaticPrepare(CDC* p_dc)
{ 
	//创建一个和实际dc、实际矩形控件区域相互兼容的位图
	m_bitmapPlate.CreateCompatibleBitmap(p_dc, m_rectCtrl.Width(), m_rectCtrl.Height());

	//利用m_dcHUDPlate将位图选中
	m_pbitmapOldPlate = m_dcPlate.SelectObject(&m_bitmapPlate); 
}


/*! @function
********************************************************************************
* 函数名   : DrawStaticBackground
* 功能     : 绘制HUD的静态背景
* 参数     : pDC 绘图指针
* 返回值   : void
* 备注     : 使用pDC指针来绘制
*******************************************************************************/
void CHUD::DrawStaticBackground(CDC *pDC)
{ 
}



/*! @function
********************************************************************************
* 函数名   : DrawDynamicBackground
* 功能     : 绘制HUD的动态背景
* 参数     : pDC 绘图指针
* 返回值   : void
* 备注     : 使用pDC指针来绘制
*******************************************************************************/
void CHUD::DrawDynamicBackground(CDC *pDC)
{


}






