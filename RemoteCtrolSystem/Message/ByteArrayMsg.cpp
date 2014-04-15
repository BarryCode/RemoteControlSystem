#include "ByteArrayMsg.h"
#include <wchar.h>
#include <Windows.h>

ByteArrayMsg::ByteArrayMsg(void)
{
	m_buffer = NULL;
	m_buffer = new char[41];
	m_size = 41;
}

ByteArrayMsg::~ByteArrayMsg(void)
{
	if (NULL != m_buffer)
	{
		delete []m_buffer;
	}
	m_size = 0;
}

unsigned __int8 ByteArrayMsg::GetType()
{
	if(NULL != m_buffer)
	{
		unsigned __int8* pMsgType = (unsigned __int8* )m_buffer;
		return pMsgType[0];
	}
	return 0;
}

size_t ByteArrayMsg::GetBuffer( void* buffer,size_t len )
{
	if (0 == m_size)
	{
		return 0;
	}
	//����buffer
	if (m_size > len)
	{
		int newSize = m_size;
		if (len >0)
		{
			delete []buffer;
		}	
		buffer = new char[newSize];
		memcpy(buffer,m_buffer,newSize);
		return newSize;
	} 
	else
	{
		memcpy(buffer,m_buffer,m_size);
		return m_size;
	}
}

size_t ByteArrayMsg::SetBuffer(const void* buffer)
{
	size_t len = 0;
	size_t* ImageSizePtr = NULL;
	//�ж���Ϣ�����ͣ�������Ϣ���ͷ�����Ӧ��С
	if(NULL != buffer)  
	{
		unsigned __int8* pMsgType = (unsigned __int8* )buffer;
		switch(*pMsgType)
		{
		case RCS_MSG_IMAGE:	
			ImageSizePtr = (size_t*)((char*)buffer + sizeof(unsigned __int8) + sizeof(RECT));
			len = sizeof(unsigned __int8) + sizeof(RECT) + sizeof(size_t) +*ImageSizePtr;
			//m_size = len;
			break;
		case RCS_MSG_MOUSE:	
			len = 13;
			//m_size = len;
			break;
		case RCS_MSG_KEYBOARD:
			len = 9;
			//m_size = len;
			break;
		case RCS_MSG_USER:
			len = 41;
			//m_size = len;
			break;
		case RCS_MSG_SETUP:
			len = 13;
			//m_size = len;
			break;
		default:
			break;
		}
	}
	//������Ϣ���ݴ�С����ռ䣬��������Ϣ����
	if (len != m_size || m_buffer == NULL)
	{
		delete []m_buffer;
		m_buffer = new char[len];
		memcpy(m_buffer,buffer,len);
		m_size = len;
		return len;
	}
	else
	{
		memcpy(m_buffer,buffer,len);
		m_size = len;
		return len;
	}
}

char* ByteArrayMsg::GetBufferPtr()
{
	return m_buffer;
}

size_t ByteArrayMsg::GetSize()
{
	return m_size;
}

size_t ByteArrayMsg::GetSize( void* buffer,int nSocketBufferSize )
{
	size_t len = 0;
	size_t* ImageSizePtr = NULL;
	if(NULL != buffer)  
	{
		unsigned __int8* pMsgType = (unsigned __int8* )buffer;
		//������Ϣ���ͷ�����Ӧ����Ϣ��С������ͼ����Ϣ֮�⣬
		//������Ϣ�Ĵ�С���ǹ̶������Կ���ֱ�ӷ��ظ�����ֵ
		switch(*pMsgType)
		{
		case RCS_MSG_IMAGE:	
			//����ͼ����ϢʱҪ��֤��ǰ����Ļ�����ָ��ָ���
			//�ڴ滹���㹻�Ŀռ�õ�ͼ����Ϣ�ļ�ͷ�е�ͼ���С�����ݲ���
			//ͼ����Ϣͼ���С��4�ֽڱ�ʾ��������Ϣ������ο�ͼ����Ϣͷ�ļ��еĶ���
			if (nSocketBufferSize > 21)
			{
				ImageSizePtr = (size_t*)((char*)buffer + sizeof(unsigned __int8) + sizeof(RECT));
				len = sizeof(unsigned __int8) + sizeof(RECT) + sizeof(size_t) + *ImageSizePtr;
			}
			break;
		case RCS_MSG_MOUSE:	
			len = 13;
			break;
		case RCS_MSG_KEYBOARD:
			len = 9;
			break;
		case RCS_MSG_USER:
			len = 41;
			break;
		case RCS_MSG_SETUP:
			len = 13;
			break;
		default:
			break;
		}
	}

	return len;
}
