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
public:
	//���¿ؼ�����
	void SetCurrentData(const TSPIDC& tspidc);
	//Ϊ���ƿؼ���׼��
	void DrawStaticPrepare(CDC* p_dc);
	//���ƾ�̬����
	void DrawStaticBackground(CDC *pDC);
	//���ƶ�̬����
	void DrawDynamicBackground(CDC *pDC);

	DECLARE_MESSAGE_MAP()
	//���ƿؼ�
	afx_msg void OnPaint();	
};

