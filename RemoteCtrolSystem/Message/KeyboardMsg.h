/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:KeyboardMsg.h
**Latest modified Data:2013-4-7  10:29:18
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-7  10:29:18
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
#ifndef __KEYBOARDMSG_H__
#define __KEYBOARDMSG_H__
#include "ByteArrayMsg.h"
/*MouseMsg�������Ϣ���࣬����m_buffer������Ϣ��ʵ������
  �������з�ʽ���£�
  ����		������			�ֽ���
  __int8	MsgType			(1bits)
  int		key				(4bits)
  int		status			(4bits) 

  status�������У�
  #define RCS_KEY_UP		0xFFFF
  #define RCS_KEY_DOWN		0xFFFE
  �������ĸ���Ϣ֮�⣬����м����������ƶ���status����ֵ��ʾ
*/
#define RCS_KEY_UP		0xFFFF
#define RCS_KEY_DOWN	0xFFFE
#define RCS_KEY_TASKMGR	0xFFFD
class KeyboardMsg :
	public ByteArrayMsg
{
public:
	KeyboardMsg(void);
	~KeyboardMsg(void);

	/**
	   @brief:���ؼ��̰�����Ӧ��ASCII��
	   @Return:int
	*/
	int   GetKey();
	/**
	   @brief:���ؼ��̵�״̬����RCS_KEY_UP���߷ſ�RCS_KEY_DOWN
	   @Return:int
	*/
	int   GetKeyStatus();
	/**
	   @brief:�����Ϣ
	   @Parameter:int key
	   @Parameter:int status
	   @Return:bool
	*/
	bool  PacketMsg(int key,int status);
};

#endif
