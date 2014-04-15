/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**
**
**                   http://www.electronics.com 
**-------------File Info---------------------------------------------------
**File Name:ScreenShot.h
**Latest modified Data:2013-4-3  13:58:53
**Latest Version:v1.0
**Description:
**
**-------------------------------------------------------------------------
**Create by:XuWunJun
**Create date:2013-4-3  13:58:53
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
#ifndef __SCREENSHOOT_H__
#define __SCREENSHOOT_H__
#include "ImageTile.h"
#include "../CxImage/ximage.h"
#include "../Message/ImageMsg.h"
#include <queue>

//#define _TEST_ENCODE_TIME_
#ifdef _TEST_ENCODE_TIME_
#include"HiResTimer.h"
#endif
class ScreenShot
{
public:
	ScreenShot(void);
	~ScreenShot(void);
	/**
	   @brief:��ʼ����Ļͼ���ȡ�࣬����ˮƽ�ʹ�ֱ�ķֿ���
	   @Parameter:int nHorizontalTile
	   @Parameter:int nVericalTile
	   @Return:bool
	*/
	bool  Init(int nHorizontalTile,int nVericalTile);
	/**
	   @brief:��ȡ��Ļͼ��ѹ���ֿ飬�����ͼ����Ϣ֮��ͼ����Ϣ���뵽��Ϣ������
	   @Parameter:std::queue<ByteArrayMsg * > * pMsgQueueָ��Ҫ�������Ϣ����
	   @Return:bool
	*/
	bool  ShotScreenImage(std::queue<ByteArrayMsg*>* pMsgQueue);//��Ļ��ͼ
	/**
	   @brief:����ͼ��ˮƽ�ʹ�ֱ�ֿ�������ڽ��յ�ͼ��ֿ�����ı�֮����Ե�����������ı�
	   @Parameter:int nHorizontal
	   @Parameter:int nVerical
	   @Return:bool
	*/
	bool  SetTileNumber(int nHorizontal,int nVerical);
	/**
	   @brief:����ͼ��JPEGѹ����������1~100����������ʾѹ���ٷֱ�
	   @Parameter:int quality
	   @Return:bool
	*/
	bool  SetQuality(int quality);
	/**
	   @brief:������Ļ���
	   @Return:int
	*/
	int	  GetScreenWidth();
	/**
	   @brief:������Ļ�߶�
	   @Return:int
	*/
	int	  GetScreenHeight();
	/**
	   @brief:����ͼ��ʱ��ı�
	   @Return:bool
	*/
	bool  IsPixelChange();
private:
	bool		m_IsPixelChange;
	char*		m_pOldScreenBits;
	char*		m_pScreenBits;
	ImageTile*	m_pImageTileArray;
	ImageTile*	m_pOldImageTileArray;
	RECT*		m_pTileRectArray;
	int			m_nTileNumX;
	int			m_nTileNumY;
	int			m_nScreenWidth;
	int			m_nScreenHeight;
	RECT		m_nScreenRect;
	CxImage		m_ScreenImage;
	int			m_ImageQuallity;
	/**
	   @brief:�Ƚ�ǰ����֡ͼ���иı�ķֿ飬�����ı�ķֿ鷢�͸��ͻ���
	   @Parameter:std::queue<ByteArrayMsg * > * pMsgQueue
	   @Return:WORD
	*/
	WORD		CompareImg(std::queue<ByteArrayMsg*>* pMsgQueue);//�ȽϷֿ�ͼ������һ��ͼ��ı䷵��16���Σ����ı����һ��ͼ���ID��Ӧ�Ķ�����λ��1
	/**
	   @brief:����Ļͼ��ֿ�
	   @Return:BOOL
	*/
	BOOL		Partition();  
#ifdef _TEST_ENCODE_TIME_
	HiResTimer	m_Timer;
#endif
	//////////////////////
};

#endif           

