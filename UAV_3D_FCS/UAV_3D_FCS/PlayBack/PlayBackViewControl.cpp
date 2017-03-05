// PlayBackViewControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "../stdafx.h"
#include "../UAV_3D_FCS.h"
#include "PlayBackViewControl.h"


// CPlayBackViewControl

IMPLEMENT_DYNCREATE(CPlayBackViewControl, CFormView)

CPlayBackViewControl::CPlayBackViewControl()
	: CFormView(IDD_PLAY_BACK)
{
	/* �������߿ؼ� */
	m_GraphicView.Create(IDD_DIALOG_GRAPHIC);
	m_GraphicView.ShowWindow(SW_HIDE);
}

CPlayBackViewControl::~CPlayBackViewControl()
{
}

void CPlayBackViewControl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPlayBackViewControl, CFormView)
	ON_BN_CLICKED(IDC_BTN_GRAPHIC, &CPlayBackViewControl::OnBnClickedBtnGraphic)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CPlayBackViewControl ���

#ifdef _DEBUG
void CPlayBackViewControl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPlayBackViewControl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPlayBackViewControl ��Ϣ�������


void CPlayBackViewControl::OnBnClickedBtnGraphic()
{
	/* ��ʾ���߿ؼ� */
	m_GraphicView.ShowWindow(SW_SHOW);
	m_GraphicView.InitGraphic();
}


void CPlayBackViewControl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	ShowScrollBar(SB_BOTH, FALSE);
}
