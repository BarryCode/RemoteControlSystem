/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   SendImageThread.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:   κط
**Create date:  2013/05/03   9:07
**Version:
**Description: 
**
**
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**
**************************************************************************/
#ifndef __SENDIMAGETHREAD_H__
#define __SENDIMAGETHREAD_H__

#include "../Thread/Thread.h"
#include "../Graphic/ScreenShot.h"
#include "../SocketIPv4/TcpConnection.h"
#include <queue>

class SendImageThread : public Thread
{
public:
	SendImageThread(void);
	~SendImageThread(void);

protected:
	void Run();  //�߳����к���

	/////////////////һ���ǽ������ִ���//////
private:
	std::queue<ByteArrayMsg*>	m_SendQueue;  //������Ļ�ֿ����ݵĶ���
	ScreenShot		m_ScreenShooter; //��Ļ��ͼ����
	int				m_Frame; //��ͼ֡��
	TCPConnection* m_connection;
	bool Init();  
	

public:
	/**
	 * @Brief SetConnection ���ø��߳�����������Ӷ���
	 * @Parameter TCPConnection * _connection  ���Ӷ���ָ��
	 * @Returns void
	 * @Remark  
	 **/
	void SetConnection(TCPConnection* _connection);
	/**
	 * @Brief SetFrame ���÷���ͼƬ��֡��
	 * @Parameter int frame  ֡��
	 * @Returns bool
	 * @Remark  
	 **/
	bool SetFrame(int frame);
	/**
	 * @Brief SetImageQuality ����ͼ��ѹ��������
	 * @Parameter int quality ����ֵ
	 * @Returns bool
	 * @Remark  
	 **/
	bool SetImageQuality(int quality);
	/**
	 * @Brief SetTileNumber  ��ֻͼ��ֿ������
	 * @Parameter int Horz  ����ֿ�����
	 * @Parameter int Vert  ����ֿ�����
	 * @Returns void
	 * @Remark  
	 **/
	void SetTileNumber(int Horz,int Vert);
};
#endif//__SENDIMAGETHREAD_H__