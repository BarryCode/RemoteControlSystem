/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:ImageMsg.h
**Latest modified Data:2013-4-1  15:59:04
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-1  15:59:04
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
#ifndef __IMAGEMSG_H__
#define __IMAGEMSG_H__
#include "bytearraymsg.h"
#include <windows.h>
/*ImageMsg��ͼ����Ϣ���࣬����m_buffer������Ϣ��ʵ������
  �������з�ʽ���£�
  ����		������			�ֽ���
  __int8	MsgType         (1bits)
  RECT		Rect            (16bits)
  size_t	imageSize       (4bits)
  char*		Imagebuffer     (imageSize bits) 
*/
class ImageMsg :
	public ByteArrayMsg
{
public:
	ImageMsg(void);
	~ImageMsg(void);

	/**
	   @brief:���ش洢ͼ���buffer�Ĵ�С����������Ϣbuffer��С��ȥǰ��������Ϣ�Ĵ�С
	   @Return:size_t
	*/
	size_t GetImageSize();
	/**
	   @brief:����ͼ���ľ�������
	   @Return:RECT
	*/
	RECT  GetImageRect();
	/**
	   @brief:����ͼ�����ݵ�buffer��ָ��
	   @Parameter:char * ImageBuffer
	   @Return:bool
	*/
	bool  GetImageBuffer(char* ImageBuffer);
	char* GetImageBufferPtr();
	/**
	   @brief:���ͼ����Ϣ
	   @Parameter:__int8 type
	   @Parameter:RECT rect
	   @Parameter:size_t ImageSize
	   @Parameter:char * buffer
	   @Return:bool
	*/
	bool  PacketMsg(RECT rect,size_t ImageSize,char* buffer);
};

#endif


