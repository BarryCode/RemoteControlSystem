#include "KeyboardMsg.h"
#include <wchar.h>

KeyboardMsg::KeyboardMsg(void)
{
	m_buffer	= new char[9];
	m_size		= 9;
}

KeyboardMsg::~KeyboardMsg(void)
{
}

int KeyboardMsg::GetKey()
{
	if (m_buffer == NULL)
	{
		return 0;
	}
	char*	pKey = m_buffer + 1;
	int		key;
	memcpy(&key,pKey,sizeof(key));
	return key;
}

int KeyboardMsg::GetKeyStatus()
{
	if (m_buffer == NULL)
	{
		return 0;
	}
	char*	pStatus = m_buffer + 5;
	int		status;
	memcpy(&status,pStatus,sizeof(status));
	return status;
}

bool KeyboardMsg::PacketMsg( int key,int status )
{
	__int8 type = RCS_MSG_KEYBOARD;
	size_t newSize = sizeof(type) + sizeof(key) + sizeof(status);


	//������Ϣ���ݽṹ��ο�ͷ�ļ��е�ע��
	//������Ϣ���ݽṹ������Ҫ��������ݿ�����һ���ֽ�����m_buffer��
	if (m_size < newSize)
	{
		if (m_buffer != NULL)
		{
			delete m_buffer;
		}

		m_buffer = new char[newSize];
		m_size = newSize;
	}
	char* pCur = m_buffer;
	memcpy(pCur,&type,sizeof(type));
	pCur += sizeof(type);

	memcpy(pCur,&key,sizeof(key));
	pCur += sizeof(key);

	memcpy(pCur,&status,sizeof(status));
	pCur = NULL;

	return true;
}
