/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   SystemMonitor.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:   κط
**Create date:  2013/05/03   9:10
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
#ifndef __SYSTEMMONITOR_H__
#define __SYSTEMMONITOR_H__

#include "FileSystemWatcher.h"
#include <vector>

class SystemMonitor
{
public:
	typedef void (*_AddApplicatinMonitor)(char *,char * , char *);
	typedef void (*_RemoveApplicationMonitor)();

	SystemMonitor();
	~SystemMonitor(void);

	/**
	 * @Brief SetName ���õ�ǰ����ص��û�
	 * @Parameter const char name[20] �û���
	 * @Returns void
	 * @Remark  
	 **/
	void SetName(const char name[20]);  
	/**
	 * @Brief SetIp ���õ�ǰ����ص��û����ڵ�IP��ַ
	 * @Parameter const char * ip ip��ַ
	 * @Returns void
	 * @Remark  
	 **/
	void SetIp(const char *ip);
	/**
	 * @Brief SetFilePath ���ñ����ؼ�¼���ļ�·��
	 * @Parameter const char path[MAX_PATH]  �ļ����ڵ�·��
	 * @Returns void
	 * @Remark  
	 **/
	void SetFilePath(const char path[MAX_PATH]);

	/**
	 * @Brief Start �������
	 * @Returns void
	 * @Remark  
	 **/
	void Start();
	/**
	 * @Brief Stop ֹͣ���
	 * @Returns void
	 * @Remark  
	 **/
	void Stop();

	/**
	 * @Brief isMonitorActive ���Ե�ǰ�ļ��״̬
	 * @Returns BOOL
	 * @Remark  
	 **/
	BOOL isMonitorActive();

private:
	BOOL isActive; //���浱ǰ���״̬
	std::vector<FileSystemWatcher*> m_vpFSW;  //����Ը����ļ��м�ص��ļ������
	_AddApplicatinMonitor appStartMonitor;  //Ӧ�ó���������DLL������������ַ
	_RemoveApplicationMonitor appStopMonitor; //Ӧ�ó���������DLL��ֹͣ��غ�����ַ
	char m_szFilePath[MAX_PATH];  //������ļ�����
	char m_szName[20],m_szIp[20];
};
#endif//__SYSTEMMONITOR_H__