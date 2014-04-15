/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:ScreenDisplay.h
**Latest modified Data:2013-4-3  9:39:09
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-3  9:39:09
**Version:v1.0
**Description:
**
**
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**************************************************************************/
#ifndef __SCREENDISPLAY_H__
#define __SCREENDISPLAY_H__

#ifndef NULL
#define NULL 0 
#endif

#include "..\Message\ImageMsg.h"
#include "..\CxImage\ximage.h"
//#include <windows.h>
class ScreenDisplay
{
public:
	ScreenDisplay(void);
	~ScreenDisplay(void);

	/**
	   @brief:��ʼ����ʾ�࣬��Ҫ������ʾ���ڵľ�����Լ���ʾ���������ش�С
	   @Parameter:HWND hDisplayWin
	   @Parameter:int width
	   @Parameter:int height
	   @Return:bool
	*/
	bool Initialize(HWND hDisplayWin,int WinWidth,int WinHeight,int ServerWidth,int ServerHeight);
	/**
	   @brief:������ʾ���ڴ�С
	   @Parameter:int width
	   @Parameter:int height
	   @Return:bool
	*/
	bool SetSize(int width,int height);
	/**
	   @brief:�������棬����ͼ��
	   @Return:void
	*/
	void Display();
	/**
	   @brief:����ͼ����Ϣ����ѹ����֪��������
	   @Parameter:ByteArrayMsg * imageMsg
	   @Return:void
	*/
	void RecvImageMsg(ByteArrayMsg* imageMsg);
	/**
	   @brief:������ʾ������
	   @Return:int
	*/
	int  GetDisplayWidth();
	/**
	   @brief:������ʾ����߶�
	   @Return:int
	*/
	int  GetDisplayHeight();
	/**
	   @brief:����Զ��������
	   @Return:int
	*/
	int  GetSeverWidth();
	/**
	   @brief:����Զ������߶�
	   @Return:int
	*/
	int	 GetServerHeight();
	/**
	   @brief:������ʾ���ڿ�ȣ���ʾ���ڴ�С����ʾ�ֱ��ʲ�ͬ��
	   @Return:int
	*/
	int  GetWinWidth();
	/**
	   @brief:������ʾ���ڸ߶�
	   @Return:int
	*/
	int  GetWinHeigth();
	/**
	   @brief:��Զ������ı�ֱ���ʱ����Ҫ���ô˺���֪ͨ��ʾ��
	   @Parameter:int ServerWidth
	   @Parameter:int ServerHeight
	   @Return:void
	*/
	void SetServerSize(int ServerWidth,int ServerHeight);
	/**
	   @brief:���ص�ǰԶ������ͼ���HBitmap
	   @Return:HBITMAP
	*/
	CxImage  GetDisplayImage();
	/**
	   @brief:�Ŵ�Զ������ͼ��
	   @Return:bool
	*/
	bool ScaleUp();
	/**
	   @brief:��СԶ������ͼ��
	   @Return:bool
	*/
	bool ScaleDown();
	/**
	   @brief:��Զ������ͼ�����ŵ����طֱ��ʴ�С
	   @Return:void
	*/
	void Scale2LocalSize();
	/**
	   @brief:����ʾ����ͼ����գ��ڷŴ����С��ʾ��ʱ���õ���
	   @Return:bool
	*/
	bool	ReflashDC();
private:	
	/**
	   @brief:������ʾ����
	   @Parameter:HWND hDisplayWin
	   @Return:bool
	*/
	bool SetDevice(HWND hDisplayWin);
	/**
	   @brief:��Զ������͵�ǰ��ʾ�ֱ��ʱ������ŵ�ǰ��Ҫ���Ƶ�ͼ���ľ���λ��
	   @Parameter:RECT srcRect
	   @Return:RECT
	*/
	RECT	ScaleRect(RECT srcRect);
	HWND	m_hClientWnd;
	HDC		m_hClientDC;
	HDC		m_hMemDC;
	HBITMAP m_hBitmap;
	HGDIOBJ m_hOldBmp;
	CxImage	m_FrameBuffer;

	//��ʾ���ڵĴ�С
	int		m_WinWidth;
	int		m_WinHeight;
	//Զ������ķֱ���
	int		m_ServerWidth;
	int		m_ServerHeight;
	//��ǰҪ��ʾ�ķֱ���
	int		m_DisplayWidth;
	int		m_DisplayHeight;
	
};

#endif

