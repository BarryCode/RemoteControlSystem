/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   FileSystemWatcher.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:   κط
**Create date:  2013/05/03   8:32
**Version:
**Description:  ��ĳһ���ļ��н��м�ص��̣߳�������ظ��ļ����µ����ļ�������
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
#ifndef __FILESYSTEMWATCHER_H__
#define __FILESYSTEMWATCHER_H__

#include "../Thread/Thread.h"

class FileSystemWatcher : public Thread
{
public:
	enum ACTION{ADDED=1, REMOVED=2, MODIFIED=3, RENAMED=4 };
	FileSystemWatcher(char name[20],char ip[20],char path[20] , char dir[MAX_PATH]);
	~FileSystemWatcher(void);	

protected:
	void Run(); //�̺߳���
	
private:
	/**
	 * @Brief GetTime ��ȡ��ǰʱ��
	 * @Parameter char time[] ����ʱ����ַ�����
	 * @Returns void
	 * @Remark  ָ���ļ����в�����ʱ��
	 **/
	void GetTime( char time[]); 

	/**
	 * @Brief DealFunc �����������ļ��е�·�����д���ת���ɾ���·��
	 * @Parameter DWORD action ��������
	 * @Parameter char * name1 �ļ����ļ��е����·��
	 * @Parameter char * name2 �ļ����ļ������·����������������Ҫ�������
	 * @Returns void
	 * @Remark  
	 **/
	void DealFunc(DWORD action,char *name1,char* name2);

	/**
	 * @Brief WriteToLog �ѱ��ζ��ļ���صĽ��д����־�ļ�
	 * @Parameter int action ���ļ������Ķ������д������޸ġ�ɾ��������������
	 * @Parameter char file1[MAX_PATH] ���������ļ����ļ���
	 * @Parameter char file2[MAX_PATH] �������漰���µ��ļ����ļ���
	 * @Returns void
	 * @Remark  
	 **/
	void WriteToLog(int action,char file1[MAX_PATH],char file2[MAX_PATH] );

	char WatchedDir[MAX_PATH];//���ӵ��ļ���
	char m_szName[20],m_szIp[20],m_szPath[MAX_PATH];
	HANDLE hDir;  
};
#endif//__FILESYSTEMWATCHER_H__
