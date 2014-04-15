/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:HostListConfig.h
**Latest modified Data:2013-4-17  11:09:53
**Latest Version:v1.0
**Description:���������ļ��е�Զ���б�������Ϣ
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-17  11:09:53
**Version:v1.0
**Description:���������ļ��е�Զ���б�������Ϣ
**
**
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**************************************************************************/
#ifndef __HOSTLISTCONFIG_H__
#define __HOSTLISTCONFIG_H__
#include "..\tinyxml\tinystr.h"
#include "..\tinyxml\tinyxml.h"
#include <vector>


/************************************************************************/
/*        Զ���б��У���ʾԶ���������֣�ip�Լ����Ӷ˿ڵ����ݽṹ        */
/************************************************************************/
struct  Host
{
	char name[32];
	char ip[16];
	int  port;
};
class HostListConfig
{
public:
	HostListConfig(void);
	~HostListConfig(void);

	/**
	   @brief:��ʼ��HostListConfig
	   @Parameter:char * FilePath
	   @Return:bool
	*/
	bool Init(char* FilePath);
	/**
	   @brief:��ȡ�����ļ��е�������Ϣ������������Ϣ���浽vtHostList��
	   @Parameter:std::vector<Host> & vtHostList
	   @Return:void
	*/
	void ReadHostList(std::vector<Host>& vtHostList);
	/**
	   @brief:���������Ϣ�������ļ���
	   @Parameter:Host host
	   @Return:void
	*/
	void AddHost(Host host);
	/**
	   @brief:�������ļ���ɾ��name������������Ӧ��������Ϣ
	   @Parameter:char * name
	   @Return:void
	*/
	void DeleteHost(char* name);
private:
	TiXmlDocument* m_pDocument;
	TiXmlElement*  m_pRootElement;

};

#endif
