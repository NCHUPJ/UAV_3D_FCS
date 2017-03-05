/***************************************************************
* Copyright (c) 2016, �µ���
* All rights reserved.
*
* �ļ����ƣ�FlightSysViewControl.cpp
* ժ    Ҫ�����ڱ���Ŀ�ķ��п���ģ�����ͼ���cpp�ļ�
*
* ��ǰ�汾��1.0
* ��    �ߣ��µ���
* ������ڣ�2016-10-21
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
	/* ����g_Bus�ϵ����ݰ� */
	g_Bus.Attach([this](const TSPIDC& tspidc){ UpdateTSPIDC(tspidc); }, "TSPIDC");

	memset(&m_TSPIDC, 0, sizeof(m_TSPIDC));
}

CFlightSysViewControl::~CFlightSysViewControl()
{
	if (m_DataIsComing)
	{
		//������ݵ�������϶������˶�ʱ����������Ҫ�ͷŵ�
		KillTimer(FlightSysViewControlSpace::HUDTimerID);
	}

	/* �ͷ�g_Bus�ϵ����ݰ� */
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


// CFlightSysViewControl ���

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


// CFlightSysViewControl ��Ϣ�������


void CFlightSysViewControl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	ShowScrollBar(SB_BOTH, FALSE);
}


void CFlightSysViewControl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//���ݸ���
	m_GPS.SetCurrentData(m_TSPIDC);

	CFormView::OnTimer(nIDEvent);
}


/*! @function
********************************************************************************
* ������   : UpdateTSPIDC
* ����     : ������Ϣ�����ϵ�TSPIDC����
* ����     : tspidc ���յ���TSPIDC���ݰ�
* ����ֵ   : void
* ����     : �µ��� �ϲ����մ�ѧ��Ϣ����ѧԺ�Զ�����ϵ
* ����     : 2017-03-04
*******************************************************************************/
void CFlightSysViewControl::UpdateTSPIDC(const TSPIDC& tspidc)
{
	if (!m_DataIsComing)
	{
		/* ��ʹ�ûص����� */
		SetTimer(FlightSysViewControlSpace::HUDTimerID, FlightSysViewControlSpace::HUDTimerElapse, NULL);

		//�����Ѿ�������ʹ�������Ƿ�ֹ�ظ�������ʱ��
		m_DataIsComing = true;
	}


	{
		std::lock_guard<std::mutex>  locker(m_MutexSendReq);
		m_TSPIDC = tspidc;
	}
}
