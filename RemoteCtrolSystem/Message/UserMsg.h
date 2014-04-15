/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:UserMsg.h
**Latest modified Data:2013-4-7  11:11:15
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-7  11:11:15
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
#ifndef __USERMSG_H__
#define __USERMSG_H__
#include "bytearraymsg.h"
/*SetupMsg��������Ϣ���࣬����m_buffer������Ϣ��ʵ������
  �������з�ʽ���£�
  ����		������			�ֽ���
  __int8	Type			(1bits)
  char*		uesrname		(20bits)
  char*		password			(20bits) 
*/
class UserMsg :
	public ByteArrayMsg
{
public:
	UserMsg(void);
	~UserMsg(void);

	/**
	   @brief:�����û�������ȷ�������pUsernameָ����ڴ���С����20bits
	   @Parameter:char * pUsername
	   @Return:bool
	*/
	bool  GetUsername(char* pUsername);
	/**
	   @brief:�������룬��ȷ�������pPasswordָ����ڴ���С����20bits
	   @Parameter:char * pPassword
	   @Return:bool
	*/
	bool  GetPassword(char* pPassword);
	/**
	   @brief:�����Ϣ
	   @Parameter:char * Username
	   @Parameter:char * Password
	   @Return:bool
	*/
	bool  PacketMsg(char* Username,char* Password);
};
#endif

