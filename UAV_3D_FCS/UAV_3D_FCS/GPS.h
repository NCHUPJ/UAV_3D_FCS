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
	//double m_LOTD = 0.0;                   //��ʱ����  7��8��9��10
	//double m_LATD = 0.0;                   //��ʱγ��  11��12��13��14
	//double m_SPH = 0.0;                    //��׼��ѹ�߶�  15��16
	//double m_PRH = 0.0;                    //��ѹ�����߶�  17��18
	//double m_RH = 0.0;                     //���ߵ�߶�  19��20
private:
	////���ڴ�ſؼ�������δ�С�ı���
	//CRect       m_rectCtrl;

	////�������ڻ��Ʊ���������DC
	//CDC			m_dcPlate;

	////�ڻ������н�ͼ�λ��Ƶ���λͼ��
	//CBitmap		m_bitmapPlate;

	////�ɵ�λ��ָ��
	//CBitmap     *m_pbitmapOldPlate;

	////�Ƿ���Ҫ�ػ澲̬����
	//bool m_reqRedrawStaticBgd = true;
public:
	//���¿ؼ�����
	//void SetCurrentData(const TSPIDC& tspidc);
	//Ϊ���ƿؼ���׼��
	//void DrawStaticPrepare(CDC* p_dc);
	
	//���ƾ�̬����
	virtual void DrawStaticBackground(CDC *pDC);
	//���ƶ�̬����
	virtual void DrawDynamicBackground(CDC *pDC);
	//DECLARE_MESSAGE_MAP()
	//afx_msg void OnPaint();
};

