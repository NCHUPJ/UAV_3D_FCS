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
//	// TODO:  �ڴ˴������Ϣ����������
//	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
//
//	//���Ի����о�̬�ı���ؼ��Ĵ�С���긳��m_rectCtrl
//	GetClientRect(&m_rectCtrl);
//
//	//memDCΪһ�����dc����CMemoryDC��Ĺ��캯���н�ʵ�ʵ�dc
//	CMemoryDC memDC(&dc, &m_rectCtrl);
//
//	if (m_reqRedrawStaticBgd)
//	{
//		//�ڻ������ڻ���HUD��̬ͼ��
//		if ((m_dcPlate == nullptr) || (m_bitmapPlate.m_hObject == nullptr))
//		{
//			//����һ����ʵ��dcƥ��������豸������(m_dcHudPlate)
//			m_dcPlate.CreateCompatibleDC(&dc);
//
//			DrawStaticPrepare(&dc);
//		}
//		else
//		{
//			m_dcPlate.DeleteDC();
//			//����һ����ʵ��dcƥ��������豸������(m_dcHudPlate)
//			m_dcPlate.CreateCompatibleDC(&dc);
//			m_bitmapPlate.DeleteObject();
//
//			DrawStaticPrepare(&dc);
//		}
//
//		//��λͼm_bitmapHUDPlate����������dc(m_dcHUDPlate)����HUD��̬����
//		DrawStaticBackground(&m_dcPlate);
//
//		//ֻ��Ҫ����һ�ξ�̬����������ϳ����治��������ʾ��̬��������ȥ��������
//		m_reqRedrawStaticBgd = false;
//	}
//
//
//	//���������ڻ�����ɵ�λͼһ���Կ�������ʾ������ʾ
//	memDC.BitBlt(0, 0, m_rectCtrl.Width(), m_rectCtrl.Height(), &m_dcPlate, 0, 0, SRCCOPY);
//
//	//��̬������Ҫ�ظ����ƣ�����ʵ�ֶ���Ч��
//	DrawDynamicBackground(&memDC); 
//}
//
//
///*! @function
//********************************************************************************
//* ������   : SetCurrentData
//* ����     : ����HUD�������Ľӿڣ���������HUD�ؼ�������
//* ����     : tspidc ��HUDViewControl�����������ݰ�
//* ����ֵ   : void
//* ����     : �µ��� �ϲ����մ�ѧ��Ϣ����ѧԺ�Զ�����ϵ
//* ����     : 2017-03-04
//*******************************************************************************/
//void CGPS::SetCurrentData(const TSPIDC& tspidc)
//{
//	//���ݸ��¸�ֵ
//	m_LOTD = tspidc.m_LOTD;                  //��ʱ����  7��8��9��10
//	m_LATD = tspidc.m_LATD;                  //��ʱγ��  11��12��13��14
//	m_SPH  = tspidc.m_SPH;                   //��׼��ѹ�߶�  15��16
//	m_PRH  = tspidc.m_PRH;                   //��ѹ�����߶�  17��18
//	m_RH   = tspidc.m_RH;                    //���ߵ�߶�  19��20 
//	 
//	//�ػ�
//	Invalidate();
//}
//
//
//
///*! @function
//********************************************************************************
//* ������   : DrawStaticPrepare
//* ����     : ��ͼ����
//* ����     : void
//* ����ֵ   : void
//* ��ע     : ���ƿؼ��ľ�̬����
//*******************************************************************************/
//void CGPS::DrawStaticPrepare(CDC* p_dc)
//{
//	//����һ����ʵ��dc��ʵ�ʾ��οؼ������໥���ݵ�λͼ
//	m_bitmapPlate.CreateCompatibleBitmap(p_dc, m_rectCtrl.Width(), m_rectCtrl.Height());
//
//	//����m_dcHUDPlate��λͼѡ��
//	m_pbitmapOldPlate = m_dcPlate.SelectObject(&m_bitmapPlate);
//}


/*! @function
********************************************************************************
* ������   : DrawStaticBackground
* ����     : ����GPS�ľ�̬����
* ����     : pDC ��ͼָ��
* ����ֵ   : void
* ��ע     : ʹ��pDCָ�������ƣ���ʾ�����������ݵľ�̬���ֲ���
			 m_LOTD                 //��ʱ����(��) 
			 m_LATD                 //��ʱγ��(��)
			 m_SPH                  //��׼��ѹ�߶�(ft)
			 m_PRH                  //��ѹ�����߶�(ft)
			 m_RH                   //���ߵ�߶�(ft)
			 ��ʾ��ʽ��
				�������ƣ�����ֵ
			 �ؼ�Ϊ��ɫ����
*******************************************************************************/
void CGPS::DrawStaticBackground(CDC *pDC)
{
	  
}



/*! @function
********************************************************************************
* ������   : DrawDynamicBackground
* ����     : ����GPS�Ķ�̬����
* ����     : pDC ��ͼָ��
* ����ֵ   : void
* ��ע     : ʹ��pDCָ�������ƣ���ʾ�����������ݵĶ�̬��������
			m_LOTD                 //��ʱ����(��)
			m_LATD                 //��ʱγ��(��)
			m_SPH                  //��׼��ѹ�߶�(ft)
			m_PRH                  //��ѹ�����߶�(ft)
			m_RH                   //���ߵ�߶�(ft)
			��ʾ��ʽ��
				�������ƣ�����ֵ
			�ؼ�Ϊ��ɫ����
*******************************************************************************/
void CGPS::DrawDynamicBackground(CDC *pDC)
{


}

