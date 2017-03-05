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
	TSPIDC m_TSPIDC;			//���ݰ�

	//���ڴ�ſؼ�������δ�С�ı���
	CRect       m_rectCtrl;

	//�������ڻ��Ʊ���������DC
	CDC			m_dcPlate;

	//�ڻ������н�ͼ�λ��Ƶ���λͼ��
	CBitmap		m_bitmapPlate;

	//�ɵ�λ��ָ��
	CBitmap     *m_pbitmapOldPlate;

	//�Ƿ���Ҫ�ػ澲̬����
	bool m_reqRedrawStaticBgd = true;


	
	//Ϊ���ƿؼ���׼��
	void DrawStaticPrepare(CDC* pDC);
	
	//���ƾ�̬����,���������д
	virtual void DrawStaticBackground(CDC *pDC) = 0;
	
	//���ƶ�̬����,���������д
	virtual void DrawDynamicBackground(CDC *pDC) = 0;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

public:
	//���¿ؼ�����
	void SetCurrentData(const TSPIDC& tspidc);
};

