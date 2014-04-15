/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:SetupMsg.h
**Latest modified Data:2013-4-7  11:24:43
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-7  11:24:43
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
#ifndef __SETUPMSG_H__
#define __SETUPMSG_H__
#include "bytearraymsg.h"
/*SetupMsg��������Ϣ���࣬����m_buffer������Ϣ��ʵ������
  �������з�ʽ���£�
  ����		������			�ֽ���
  __int8	Type			(1bits)
  int		SetupType		(4bits)
  int		value1			(4bits) 
   int		value2			(4bits) 
*/
#define	RCS_SETUP_MSG_PERMISSION	0x5100	//�û�Ȩ�ޣ��ۿ����ǿ��ƻ�����IP������
#define	RCS_SETUP_MSG_PIXEL			0x5200   //��Ļ�ֱ���value1���ȣ�value2��߶�
#define	RCS_SETUP_MSG_TILE			0x5300   //ͼ��ֿ����ã�value1�����ָ������value������ָ����
#define	RCS_SETUP_MSG_IMAGE_QUALITY	0x5400	//ͼ����������Value1��ʾͼ������
#define	RCS_SETUP_MSG_FRAME			0x5500	//��ʾ֡�ʣ���Value1��ʾ��ʾ֡��
#define	RCS_SETUP_MSG_STOP			0X5600  //��ͣ��ʾԶ�����棬value1==1ʱ��ͣ��0ʱ��ʼ����ͼ��
//������Ϣ��Ȩ������ʱ�Ķ�ӦValue1ֵ
// ����Ȩ�޵�value2�У�-1 �˺�������� 0 ֻ�йۿ�Ȩ��  1 ����Ȩ��
// IP��ֹ��value2�У�   0 ����ֹ�� 1 ����

#define	RCS_PERMISSION_CONTROL		0x5110	//����Ȩ��
#define	RCS_PERMISSION_IP			0x5130	//����IP

class SetupMsg :
	public ByteArrayMsg
{
public:
	SetupMsg(void);
	~SetupMsg(void);

	/**
	   @brief:����������Ϣ������
	   @Return:int
	*/
	int		GetStatusType();
	/**
	   @brief:������Ҫ���õĵ�һ��ֵ
	   @Return:int
	*/
	int		GetValue1();
	/**
	   @brief:������������Ϣ��Ҫ�ڶ���ֵ��Ϊ���䣬������Ҫ���õĵڶ���ֵ�����򷵻�0
	   @Return:int
	*/
	int		GetValue2();
	/**
	   @brief:�����Ϣvalue2Ϊ��չֵ������Ҫ��������ֵ��ʱ���õ�
	   @Parameter:int setupType//������Ϣ�������ʹ��Ԥ����ĺ�RCS_SETUP_MSG_XXX
	   @Parameter:int value1//��������Ϣ��Ȩ������ʱ����ʹ��Ԥ����ĺ�RCS_PERMISSION_XXX����ֵ
	   @Parameter:int value2
	   @Return:bool
	*/
	bool	PacketMsg(int setupType,int  value1,int value2 = 0);
};
#endif
