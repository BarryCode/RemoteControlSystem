/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com  
**-------------File Info---------------------------------------------------
**File Name:FrameBuffer.h
**Latest modified Data:2013-3-28  16:46:02
**Latest Version:v1.0
**Description:֡�����࣬���ڱ���һ֡����Ļͼ��ͼ����char*��ʽ���棬��������Ļͼ��ľ�������
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-3-28  16:46:02
**Version:v1.0
**Description:����FrameBuffer��
**
**
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**************************************************************************/
#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__
#include <windows.h>
class FrameBuffer
{
public:
	FrameBuffer(void);
	~FrameBuffer(void);

	/**
	   @brief:����֡�����ָ�룬char*��,
	              ע�⣺�޸ķ��ص�char*ָ������ݻ�ı����е�֡����
	   @Return:char*
	*/
	char* getBuffer();
	/**
	   @brief:��һ��char*��������Ϊ֡����.
	              ע�⣺�����������ʹ֡����ָ��ָ��src���ڴ�顣��Ҫ����ָ����ջ�з�����ڴ�飬Ҳ��Ҫ���ⲿ���ٴ���Ķ��ڴ�顣
	   @Parameter:char * src
	   @Return:bool
	*/
	bool  setBuffer(char* src);
	/**
	   @brief:����֡����������Ϊ(x,y)�����ص�ָ�룬���ʧ�ܣ�����NULL
	              ע�⣺�޸ķ��ص�char*ָ������ݻ�ı����е�֡����
	   @Parameter:int x
	   @Parameter:int y
	   @Return:char*
	*/
	char* getBufferPtr(int x,int y);
	/**
	   @brief:���֡������srcRectָ���ľ��ε�ͼ�񣬴���dstָ����ڴ���У���ȷ��dstָ����ڴ���㹻��
	   @Parameter:char * dst
	   @Parameter:RECT srcRect
	   @Return:bool
	*/
	bool  getRectBuffer(char* dst,RECT srcRect);
	/**
	   @brief:��srcָ���ͼ�񻺴濽����֡����ָ����dstRect��λ�ã���ȷ��srcָ���ͼ���dstRect�趨�Ĵ�Сһ��
	   @Parameter:char * src
	   @Parameter:RECT dstRect
	   @Return:bool
	*/
	bool  setRectBuffer(char* src,RECT dstRect);
	/**
	   @brief:���ش���֡�����char����Ĵ�С
	   @Return:int
	*/
	int     getBufferSize();
	/**
	   @brief:����֡�����С
	   @Parameter:RECT newRect
	   @Return:bool
	*/
	bool  resizeBuffer(RECT newRect);
protected:
	char   *m_buffer;
	RECT   m_bufferRect;
};

#endif

