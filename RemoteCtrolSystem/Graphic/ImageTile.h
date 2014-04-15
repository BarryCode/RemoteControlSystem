/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:ImageTile.h
**Latest modified Data:2013-4-3  14:01:22
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-3  14:01:22
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
#ifndef __IMAGETILE_H__
#define __IMAGETILE_H__
#include <Windows.h>
class ImageTile
{
public:
	ImageTile(void);
	~ImageTile(void);
    /**
       @brief:��������ͼ��ֿ����ݣ�����������ύ��ͼ��ֿ����ڴ��ͼ�����ݵ�ָ�룬�Լ�ͼ��ֿ�ľ���λ������
       @Parameter:ImageTile & tile1
       @Parameter:ImageTile & tile2
       @Return:friend void
    */
    friend void SwapImageTile(ImageTile& tile1,ImageTile& tile2);
	/**
	   @brief:ͼ��ֿ麯��������bmp����ͼ��ķָע��bmpͼ������з�ʽ�����½ǿ�ʼ�����µߵ���
	   @Parameter:char * pScreenImage
	   @Parameter:RECT screenRect
	   @Parameter:RECT tileRect
	   @Return:bool
	*/
	bool	SetImageTileReverse(char* pScreenImage,RECT screenRect,RECT tileRect);
	/**
	   @brief:ͼ��ֿ麯���������Դ����ͼ�����ݰ�������ʽ���У����ϵ��£������ң�
	   @Parameter:char * pScreenImage
	   @Parameter:RECT screenRect
	   @Parameter:RECT tileRect
	   @Return:bool
	*/
	bool	SetImageTile(char* pScreenImage,RECT screenRect,RECT tileRect);
	/**
	   @brief:��ȡͼ������buffer��ָ��
	   @Parameter:char * dstBuff
	   @Return:bool
	*/
	bool	ImageBits(char* dstBuff) const;
	/**
	   @brief:����bufferָ��
	   @Return:char*
	*/
	char*	GetBitsPtr();
	/**
	   @brief:����ͼ��ֿ�ľ���
	   @Return:RECT
	*/
	RECT	Rect();
private:
	RECT	m_Rect;
	char*	m_pImageBits;
};

#endif

