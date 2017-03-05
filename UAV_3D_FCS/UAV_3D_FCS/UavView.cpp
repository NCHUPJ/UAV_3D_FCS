#include "stdafx.h"
#include "UavView.h"


CUavView::CUavView()
{
	memset(&m_TSPIDC, 0, sizeof(m_TSPIDC));
}


CUavView::~CUavView()
{
}


BEGIN_MESSAGE_MAP(CUavView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CUavView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()

	//���Ի����о�̬�ı���ؼ��Ĵ�С���긳��m_rectCtrl
	GetClientRect(&m_rectCtrl);

	//memDCΪһ�����dc����CMemoryDC��Ĺ��캯���н�ʵ�ʵ�dc
	CMemoryDC memDC(&dc, &m_rectCtrl);

	if (m_reqRedrawStaticBgd)
	{
		//�ڻ������ڻ���HUD��̬ͼ��
		if ((m_dcPlate == nullptr) || (m_bitmapPlate.m_hObject == nullptr))
		{
			//����һ����ʵ��dcƥ��������豸������(m_dcHudPlate)
			m_dcPlate.CreateCompatibleDC(&dc);

			DrawStaticPrepare(&dc);
		}
		else
		{
			m_dcPlate.DeleteDC();
			//����һ����ʵ��dcƥ��������豸������(m_dcHudPlate)
			m_dcPlate.CreateCompatibleDC(&dc);
			m_bitmapPlate.DeleteObject();

			DrawStaticPrepare(&dc);
		}

		//��λͼm_bitmapHUDPlate����������dc(m_dcHUDPlate)����HUD��̬����
		DrawStaticBackground(&m_dcPlate);

		//ֻ��Ҫ����һ�ξ�̬����������ϳ����治��������ʾ��̬��������ȥ��������
		m_reqRedrawStaticBgd = false;
	}


	//���������ڻ�����ɵ�λͼһ���Կ�������ʾ������ʾ
	memDC.BitBlt(0, 0, m_rectCtrl.Width(), m_rectCtrl.Height(), &m_dcPlate, 0, 0, SRCCOPY);

	//��̬������Ҫ�ظ����ƣ�����ʵ�ֶ���Ч��
	DrawDynamicBackground(&memDC);
}



/*! @function
********************************************************************************
* ������   : SetCurrentData
* ����     : ����HUD�������Ľӿڣ���������HUD�ؼ�������
* ����     : tspidc ��HUDViewControl�����������ݰ�
* ����ֵ   : void
* ����     : �µ��� �ϲ����մ�ѧ��Ϣ����ѧԺ�Զ�����ϵ
* ����     : 2017-03-04
*******************************************************************************/
void CUavView::SetCurrentData(const TSPIDC& tspidc)
{
	//���ݸ��¸�ֵ
	m_TSPIDC = tspidc;
	//�ػ�
	Invalidate();
}



/*! @function
********************************************************************************
* ������   : DrawStaticPrepare
* ����     : ��ͼ����
* ����     : void
* ����ֵ   : void
* ��ע     : ���ƿؼ��ľ�̬����
*******************************************************************************/
void CUavView::DrawStaticPrepare(CDC* pDC)
{
	//����һ����ʵ��dc��ʵ�ʾ��οؼ������໥���ݵ�λͼ
	m_bitmapPlate.CreateCompatibleBitmap(pDC, m_rectCtrl.Width(), m_rectCtrl.Height());

	//����m_dcHUDPlate��λͼѡ��
	m_pbitmapOldPlate = m_dcPlate.SelectObject(&m_bitmapPlate);
}

 
