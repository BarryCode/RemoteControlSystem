/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:MouseMsg.h
**Latest modified Data:2013-4-7  9:35:40
**Latest Version:v1.0
**Description:�����Ϣ��
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-7  9:35:40
**Version:v1.0
**Description:�����Ϣ��
**
**
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**************************************************************************/
/*MouseMsg�������Ϣ���࣬����m_buffer������Ϣ��ʵ������
  �������з�ʽ���£�
  ����		������			�ֽ���
  __int8	MsgType			(1bits)
  int		x				(4bits)
  int		y				(4bits)
  int		status			(4bits) 

  status�������У�
  #define RCS_MOUSE_LEFT_UP			0xFFFF
  #define RCS_MOUSE_LEFT_DOWN		0xFFFE
  #define RCS_MOUSE_RIGHT_UP		0xFFFD
  #define RCS_MOUSE_RIGHT_DOWN		0XFFFC
  �������ĸ���Ϣ֮�⣬����м����������ƶ���status����ֵ��ʾ
*/
#ifndef __MOUSEMSG_H__
#define __MOUSEMSG_H__
#include "ByteArrayMsg.h"

#define RCS_MOUSE_LEFT_UP		WM_LBUTTONUP
#define RCS_MOUSE_LEFT_DOWN		WM_LBUTTONDOWN
#define RCS_MOUSE_LEFT_DBLCLK	WM_LBUTTONDBLCLK
#define RCS_MOUSE_RIGHT_UP		WM_RBUTTONUP
#define RCS_MOUSE_RIGHT_DOWN	WM_RBUTTONDOWN
#define RCS_MOUSE_RIGHT_DBLCLK	WM_RBUTTONDBLCLK
#define RCS_MOUSE_MINDLE_UP		WM_MBUTTONUP
#define RCS_MOUSE_MINDLE_DOWN	WM_MBUTTONDOWN
#define RCS_MOUSE_MINDLE_DBLCLK	WM_MBUTTONDBLCLK
#define RCS_MOUSE_WHEEL			WM_MOUSEWHEEL


class MouseMsg
	:public ByteArrayMsg
{
public:
	MouseMsg(void);
	~MouseMsg(void);

	/**
	   @brief:������������xֵ�����m_buffer == NULL����-1
	   @Return:int
	*/
	int   GetMouseX();
	/**
	   @brief:������������yֵ�����m_buffer == NULL����-1
	   @Return:int
	*/
	int   GetMouseY();
	/**
	   @brief:��������״̬�������趨��ο���ע�ͣ����m_buffer == NULL����0
	   @Return:int
	*/
	int   GetMouseStatus();
	/**
	   @brief:�����Ϣ
	   @Parameter:int x
	   @Parameter:int y
	   @Parameter:int status//status����ǹ��ֻ�����ֱ�Ӵ���������ֵ��
	                         �������갴�������£���ʹ��Ԥ����ĺ�RCS_MOUSE_XXX_XXX
	   @Return:bool
	*/
	bool  PacketMsg(int x,int y,int status);
};
#endif

