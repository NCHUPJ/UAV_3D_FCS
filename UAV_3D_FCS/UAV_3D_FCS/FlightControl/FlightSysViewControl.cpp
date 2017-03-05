/***************************************************************
* Copyright (c) 2016, 陈登龙
* All rights reserved.
*
* 文件名称：FlightSysViewControl.cpp
* 摘    要：用于本项目的飞行控制模块的视图类的cpp文件
*
* 当前版本：1.0
* 作    者：陈登龙
* 完成日期：2016-10-21
***************************************************************/

#include "stdafx.h"
#include "../stdafx.h"
#include "../UAV_3D_FCS.h"
#include "FlightSysViewControl.h"


// CFlightSysViewControl
extern MessageBus g_Bus;
IMPLEMENT_DYNCREATE(CFlightSysViewControl, CFormView)

CFlightSysViewControl::CFlightSysViewControl()
	: CFormView(IDD_FCS)
{
	/* 接收g_Bus上的数据包 */
	g_Bus.Attach([this](const TSPIDC& tspidc){ UpdateTSPIDC(tspidc); }, "TSPIDC");

	memset(&m_TSPIDC, 0, sizeof(m_TSPIDC));
}

CFlightSysViewControl::~CFlightSysViewControl()
{
	if (m_DataIsComing)
	{
		//如果数据到来，则肯定开启了定时器，这里需要释放掉
		KillTimer(FlightSysViewControlSpace::HUDTimerID);
	}

	/* 释放g_Bus上的数据包 */
	g_Bus.Remove<void, const TSPIDC&>("TSPIDC");
}

void CFlightSysViewControl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GPS, m_GPS);
}

BEGIN_MESSAGE_MAP(CFlightSysViewControl, CFormView)
	ON_WM_SIZE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CFlightSysViewControl 诊断

#ifdef _DEBUG
void CFlightSysViewControl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFlightSysViewControl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFlightSysViewControl 消息处理程序


void CFlightSysViewControl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	ShowScrollBar(SB_BOTH, FALSE);
}


void CFlightSysViewControl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//数据更新
	m_GPS.SetCurrentData(m_TSPIDC);

	CFormView::OnTimer(nIDEvent);
}


/*! @function
********************************************************************************
* 函数名   : UpdateTSPIDC
* 功能     : 接收消息总线上的TSPIDC数据
* 参数     : tspidc 接收到的TSPIDC数据包
* 返回值   : void
* 作者     : 陈登龙 南昌航空大学信息工程学院自动控制系
* 日期     : 2017-03-04
*******************************************************************************/
void CFlightSysViewControl::UpdateTSPIDC(const TSPIDC& tspidc)
{
	if (!m_DataIsComing)
	{
		/* 不使用回调函数 */
		SetTimer(FlightSysViewControlSpace::HUDTimerID, FlightSysViewControlSpace::HUDTimerElapse, NULL);

		//数据已经到来，使用这个标记防止重复开启定时器
		m_DataIsComing = true;
	}


	{
		std::lock_guard<std::mutex>  locker(m_MutexSendReq);
		m_TSPIDC = tspidc;
	}
}
