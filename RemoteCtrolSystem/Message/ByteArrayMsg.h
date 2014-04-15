/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:ByteArrayMsg.h
**Latest modified Data:2013-4-1  14:27:19
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-1  14:27:19
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
#ifndef __BYTEARRAYMSG_H__
#define __BYTEARRAYMSG_H__

#ifndef NULL
#define NULL 0
#endif

#include "MessageData.h"
class ByteArrayMsg 
		:public MessageData
{
public:
	ByteArrayMsg(void);
	~ByteArrayMsg(void);

	/**
	   @brief:������Ϣ��������Ϣ����
	   @Return:unsigned __int8
	*/
	/**
	   @brief:������Ϣ����
	   @Return:unsigned __int8
	*/
	virtual unsigned __int8 GetType() ;
	/**
	   @brief:��ȡbuffer������Ϣ������bufferָ��ָ����ڴ���У�l
	              en��ʾbufferָ����ڴ��Ĵ�С�����lenС����Ϣ�Ĵ�С��
				  �������һ���µĿռ�
	   @Parameter:void * buffer
	   @Parameter:size_t len
	   @Return:size_t
	*/
	virtual size_t GetBuffer(void* buffer,size_t len);
	/**
	   @brief:��bufferָ����ڴ��е���Ϣ������ByteArrayMsg�У�
	              ʹ�ô˺���ʱҪȷ�������bufferָ����ָ��Ļ������Ѿ���ȫ����������һ����Ϣ���ݣ�
				  ���buffer�е�һ����Ϣ���ݲ�������ָ�뽫��Խ��
	   @Parameter:void * buffer
	   @Parameter:size_t len
	   @Return:size_t
	*/
	virtual size_t SetBuffer(const void* buffer);
	/**
	   @brief:����ByteArrayMsg��buffer��ָ�룬����ʹ�ã�
	              ��ByteArrayMsg������֮ʱ�����ָ��ָ��Ŀռ佫�ᱻ�ͷ�
	   @Return:char*
	*/
	virtual char* GetBufferPtr();
	/**
	   @brief:����ByteArrayMsg��buffer��С���ֽ���
	   @Return:size_t
	*/
	virtual size_t GetSize();
	/**
	   @brief:���㻺�����е�ǰbuffer�Ĵ�С����ȷ��pBufferָ�����һ����Ϣ����ĵ�һ���ֽڡ�
	          ������Ϣ��ͼ����Ϣ����nSocketBufferSizeС��21�ֽ�ʱ����ǰ�������޷�������ʾ�ļ�ͷ���᷵��0
	   @Parameter:void * pBuffer
	   @Parameter:int nSocketBufferSize//��ʾpBufferָ����ڴ�鵽��βλ�õĴ�С
	   @Return:size_t
	*/
	static  size_t GetSize(void* pBuffer,int nSocketBufferSize);
protected:
	char*	m_buffer;
	size_t	m_size;
};

#endif

