#include "stdafx.h"
#include "GPS.h"


CGPS::CGPS()
{
}


CGPS::~CGPS()
{
}



//BEGIN_MESSAGE_MAP(CGPS, CUavView)
//	ON_WM_PAINT()
//END_MESSAGE_MAP()

//
//void CGPS::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//	// TODO:  在此处添加消息处理程序代码
//	// 不为绘图消息调用 CWnd::OnPaint()
//
//	//将对话框中静态文本框控件的大小坐标赋给m_rectCtrl
//	GetClientRect(&m_rectCtrl);
//
//	//memDC为一虚拟的dc，在CMemoryDC类的构造函数中将实际的dc
//	CMemoryDC memDC(&dc, &m_rectCtrl);
//
//	if (m_reqRedrawStaticBgd)
//	{
//		//在缓冲区内绘制HUD静态图形
//		if ((m_dcPlate == nullptr) || (m_bitmapPlate.m_hObject == nullptr))
//		{
//			//创建一个和实际dc匹配的虚拟设备描述表(m_dcHudPlate)
//			m_dcPlate.CreateCompatibleDC(&dc);
//
//			DrawStaticPrepare(&dc);
//		}
//		else
//		{
//			m_dcPlate.DeleteDC();
//			//创建一个和实际dc匹配的虚拟设备描述表(m_dcHudPlate)
//			m_dcPlate.CreateCompatibleDC(&dc);
//			m_bitmapPlate.DeleteObject();
//
//			DrawStaticPrepare(&dc);
//		}
//
//		//在位图m_bitmapHUDPlate中利用虚拟dc(m_dcHUDPlate)绘制HUD静态背景
//		DrawStaticBackground(&m_dcPlate);
//
//		//只需要绘制一次静态背景，如果拖出界面不能重新显示静态背景，就去掉这个标记
//		m_reqRedrawStaticBgd = false;
//	}
//
//
//	//将缓冲区内绘制完成的位图一次性拷贝到显示屏中显示
//	memDC.BitBlt(0, 0, m_rectCtrl.Width(), m_rectCtrl.Height(), &m_dcPlate, 0, 0, SRCCOPY);
//
//	//动态背景需要重复绘制，才能实现动画效果
//	DrawDynamicBackground(&memDC); 
//}
//
//
///*! @function
//********************************************************************************
//* 函数名   : SetCurrentData
//* 功能     : 留给HUD控制器的接口，用来设置HUD控件的数据
//* 参数     : tspidc 从HUDViewControl发送来的数据包
//* 返回值   : void
//* 作者     : 陈登龙 南昌航空大学信息工程学院自动控制系
//* 日期     : 2017-03-04
//*******************************************************************************/
//void CGPS::SetCurrentData(const TSPIDC& tspidc)
//{
//	//数据更新赋值
//	m_LOTD = tspidc.m_LOTD;                  //即时经度  7、8、9、10
//	m_LATD = tspidc.m_LATD;                  //即时纬度  11、12、13、14
//	m_SPH  = tspidc.m_SPH;                   //标准气压高度  15、16
//	m_PRH  = tspidc.m_PRH;                   //气压修正高度  17、18
//	m_RH   = tspidc.m_RH;                    //无线电高度  19、20 
//	 
//	//重绘
//	Invalidate();
//}
//
//
//
///*! @function
//********************************************************************************
//* 函数名   : DrawStaticPrepare
//* 功能     : 绘图函数
//* 参数     : void
//* 返回值   : void
//* 备注     : 绘制控件的静态部分
//*******************************************************************************/
//void CGPS::DrawStaticPrepare(CDC* p_dc)
//{
//	//创建一个和实际dc、实际矩形控件区域相互兼容的位图
//	m_bitmapPlate.CreateCompatibleBitmap(p_dc, m_rectCtrl.Width(), m_rectCtrl.Height());
//
//	//利用m_dcHUDPlate将位图选中
//	m_pbitmapOldPlate = m_dcPlate.SelectObject(&m_bitmapPlate);
//}


/*! @function
********************************************************************************
* 函数名   : DrawStaticBackground
* 功能     : 绘制GPS的静态背景
* 参数     : pDC 绘图指针
* 返回值   : void
* 备注     : 使用pDC指针来绘制，显示下面的五个数据的静态文字部分
			 m_LOTD                 //即时经度(°) 
			 m_LATD                 //即时纬度(°)
			 m_SPH                  //标准气压高度(ft)
			 m_PRH                  //气压修正高度(ft)
			 m_RH                   //无线电高度(ft)
			 显示格式：
				变量名称：变量值
			 控件为黑色背景
*******************************************************************************/
void CGPS::DrawStaticBackground(CDC *pDC)
{
	  
}



/*! @function
********************************************************************************
* 函数名   : DrawDynamicBackground
* 功能     : 绘制GPS的动态背景
* 参数     : pDC 绘图指针
* 返回值   : void
* 备注     : 使用pDC指针来绘制，显示下面的五个数据的动态变量部分
			m_LOTD                 //即时经度(°)
			m_LATD                 //即时纬度(°)
			m_SPH                  //标准气压高度(ft)
			m_PRH                  //气压修正高度(ft)
			m_RH                   //无线电高度(ft)
			显示格式：
				变量名称：变量值
			控件为黑色背景
*******************************************************************************/
void CGPS::DrawDynamicBackground(CDC *pDC)
{


}

