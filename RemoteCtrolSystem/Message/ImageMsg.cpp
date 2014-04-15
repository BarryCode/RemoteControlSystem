#include "ImageMsg.h"
#include <wchar.h>

ImageMsg::ImageMsg(void)
{
}

ImageMsg::~ImageMsg(void)
{
}

size_t ImageMsg::GetImageSize()
{
	size_t* ImageSizePtr = (size_t*)(m_buffer + sizeof(unsigned __int8) + sizeof(RECT));
	return *ImageSizePtr;
}

RECT ImageMsg::GetImageRect()
{
	RECT* ImageRectPtr = (RECT*)(m_buffer + sizeof(unsigned __int8));
	return *ImageRectPtr;
}

bool ImageMsg::GetImageBuffer(char* ImageBuffer)
{
	if (NULL == ImageBuffer)
	{
		return false;
	}
	char* ImagePtr = m_buffer+ sizeof(unsigned __int8) + sizeof(RECT) + sizeof(size_t);
	memcpy(ImageBuffer,ImagePtr,GetImageSize());
	return true;
}

bool ImageMsg::PacketMsg( RECT rect,size_t ImageSize,char* buffer )
{
	__int8 type =	RCS_MSG_IMAGE;
	size_t newSize = sizeof(type) + sizeof(rect) + sizeof(ImageSize) + ImageSize;
	
	//ͼ����Ϣ���ݽṹ��ο�ͷ�ļ��е�ע��
	//������Ϣ���ݽṹ������Ҫ��������ݿ�����һ���ֽ�����m_buffer��
	if (m_size < newSize)
	{
		if (m_buffer != NULL)
		{
			delete []m_buffer;
		}
		
		m_buffer = new char[newSize];
		m_size = newSize;
	}
	char* pCur = m_buffer;
	memcpy(pCur,&type,sizeof(type));
	pCur += sizeof(type);

	memcpy(pCur,&rect,sizeof(rect));
	pCur += sizeof(rect);

	memcpy(pCur,&ImageSize,sizeof(ImageSize));
	pCur += sizeof(ImageSize);

	memcpy(pCur,buffer,ImageSize);
	pCur = NULL;

	return true;
}

char* ImageMsg::GetImageBufferPtr()
{
	
	char* ImagePtr = m_buffer+ sizeof(unsigned __int8) + sizeof(RECT) + sizeof(size_t);
	return ImagePtr;
}
