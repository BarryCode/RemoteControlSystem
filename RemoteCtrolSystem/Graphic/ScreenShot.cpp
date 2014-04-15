#include "ScreenShot.h"
#include <Windowsx.h>
#include <stdio.h>
#include <stdlib.h>

ScreenShot::ScreenShot(void)
{

	m_pOldScreenBits = NULL;
	m_pScreenBits = NULL;
	m_pImageTileArray = NULL;
	m_pOldImageTileArray = NULL;
	m_pTileRectArray = NULL;
	m_nScreenWidth = 0;
	m_nScreenHeight = 0;
	m_ImageQuallity = 60;
	m_nTileNumX = 4;
	m_nTileNumY = 4;

}

ScreenShot::~ScreenShot(void)
{
	if (NULL != m_pTileRectArray)
	{
		delete []m_pTileRectArray;
		m_pTileRectArray = NULL;
	}
	if (NULL != m_pImageTileArray)
	{
		delete []m_pImageTileArray;
		m_pImageTileArray = NULL;
	}
	if(NULL != m_pOldImageTileArray)
	{
		delete []m_pOldImageTileArray;
		m_pOldImageTileArray = NULL;
	}
	if (NULL != m_pScreenBits)
	{
		delete m_pScreenBits;
		m_pScreenBits = NULL;
	}
	if (NULL != m_pOldScreenBits)
	{
		delete m_pOldScreenBits;
		m_pOldScreenBits = NULL;
	}
}

bool ScreenShot::Init(int nHorizontalTile,int nVericalTile)
{

	//Ϊ������Ļͼ��Ļ������ռ�
	GetClientRect(GetDesktopWindow(),&m_nScreenRect);
	m_nScreenHeight = m_nScreenRect.bottom - m_nScreenRect.top;
	m_nScreenWidth  = m_nScreenRect.right - m_nScreenRect.left;
	m_pScreenBits = new char[m_nScreenHeight*m_nScreenWidth*3];
	m_pOldScreenBits = new char[m_nScreenHeight*m_nScreenWidth*3];
	memset(m_pOldScreenBits,0,sizeof(BYTE)*m_nScreenHeight*m_nScreenWidth*3);

	SetTileNumber(nHorizontalTile,nVericalTile);
	//��ʼ���ֿ�ͼ���б�
	m_pImageTileArray = new ImageTile[nHorizontalTile*nVericalTile];
	m_pOldImageTileArray = new ImageTile[nHorizontalTile*nVericalTile];
	m_pTileRectArray = new RECT[nHorizontalTile*nVericalTile];

	#ifdef _TEST_ENCODE_TIME_
	m_Timer.InitTimer();
	#endif
	return TRUE;
}
bool ScreenShot::SetTileNumber(int horizontal,int verical)
{
	if (horizontal <= 0 || verical <= 0)
	{
		return false;
	}
	m_nTileNumX = horizontal;
	m_nTileNumY = verical;

	return true;
}
bool  ScreenShot::ShotScreenImage(std::queue<ByteArrayMsg*>* pMsgQueue)
{

	GetClientRect(GetDesktopWindow(),&m_nScreenRect);
	int nScreenHeight = m_nScreenRect.bottom - m_nScreenRect.top;
	int nScreenWidth  = m_nScreenRect.right - m_nScreenRect.left;
	//����Ļ�ֱ��ʸı䣬���·���ռ�
	if (nScreenHeight != m_nScreenHeight || nScreenWidth != m_nScreenWidth)
	{
		delete m_pScreenBits;
		delete m_pOldScreenBits;
		m_nScreenHeight		= nScreenHeight;
		m_nScreenWidth		= nScreenWidth;
		m_pScreenBits		= new char[m_nScreenHeight*m_nScreenWidth*3];
		m_pOldScreenBits	= new char[m_nScreenHeight*m_nScreenWidth*3];
		memset(m_pOldScreenBits,0,sizeof(BYTE)*m_nScreenHeight*m_nScreenWidth*3);
		m_IsPixelChange		= true;
	}
	else
	{
		m_IsPixelChange = false;
	}
	
	HDC hScreenDC = GetDC(GetDesktopWindow()); //��ȡ��Ļ��HDC
	HDC hMemDC = CreateCompatibleDC(hScreenDC);
	HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC,m_nScreenWidth,m_nScreenHeight);
	HGDIOBJ hOldBmp = SelectObject(hMemDC,hBitmap);
	BitBlt(hMemDC,0,0,m_nScreenWidth,m_nScreenHeight,hScreenDC,0,0,SRCCOPY);

	SelectObject(hMemDC,hOldBmp);
	DeleteObject(hMemDC);
	ReleaseDC(GetDesktopWindow(),hScreenDC);

	if (m_ScreenImage.CreateFromHBITMAP(hBitmap))
	{
		Partition();
		CompareImg(pMsgQueue);
		DeleteBitmap(hBitmap);
	}
	return TRUE;
}


BOOL  ScreenShot::Partition()
{
	RECT tileRect;
	int width = m_nScreenWidth/m_nTileNumX;
	int height = m_nScreenHeight/m_nTileNumY;

	for (int yIdx = 0;yIdx < m_nTileNumY;++yIdx)
	{
		for (int xIdx = 0;xIdx<m_nTileNumX;++xIdx)
		{
			//��������Ҫ��ȡ�ķֿ�ľ��Σ���Ҫ�ǵ��ֿ�Ŀ������ܱ��ֱ�������֮ʱ����ֱ��ˮƽ�����ϵ����һ�к��еķֿ鶼Ҫ��ȫ���ص�
			int nImageID  = yIdx*m_nTileNumX + xIdx;
			tileRect.left = xIdx*(m_nScreenWidth/m_nTileNumX);	
			tileRect.right = (xIdx != m_nTileNumX-1)?(tileRect.left+width):m_nScreenWidth;
			tileRect.top = yIdx*(m_nScreenHeight/m_nTileNumY);
			tileRect.bottom = (yIdx != m_nTileNumY-1)?(tileRect.top+height):m_nScreenHeight;

			//��ȡtileRectָ����������ķֿ飬���ڽ�ȡ����BMPͼ���������ݴ����½ǿ�ʼ����������ҪSetImageTileReverse��ͼ���ڴ�ֱ�����Ϸ�ת
			m_pImageTileArray[nImageID].SetImageTileReverse((char*)m_ScreenImage.GetBits(),m_nScreenRect,tileRect);
			memcpy(m_pTileRectArray+nImageID,&tileRect,sizeof(tileRect));
		}
	}
	return TRUE;
}
WORD ScreenShot::CompareImg(std::queue<ByteArrayMsg*>* pMsgQueue)
{
	ImageTile	preImgPart;
	char*		oldTileBits;
	char*		curTileBits;
	RECT		tileRect;
	int			width = m_nScreenWidth/m_nTileNumX;
	int			height = m_nScreenHeight/m_nTileNumY;
	//�����ֿ�ͼ��
	long count = 0;
	float time = 0;
#ifdef _TEST_ENCODE_TIME_
	m_Timer.GetElapsedSecond();
#endif
   long maxsize = 0;
	for (int yIdx = 0;yIdx < m_nTileNumY;++yIdx)
	{
		for (int xIdx = 0;xIdx<m_nTileNumX;++xIdx)
		{
			int nImageID  = yIdx*m_nTileNumX + xIdx;

			tileRect = m_pTileRectArray[yIdx*m_nTileNumX + xIdx];
			
				int tileWidth = tileRect.right -tileRect.left;
				int tileHeight = tileRect.bottom - tileRect.top;
				int bufSize = tileWidth*tileHeight*3;

				//��ȡ��Ҫ�Ƚϵ�����ͼ��ֿ��bufferָ��
				curTileBits = m_pImageTileArray[yIdx*m_nTileNumX + xIdx].GetBitsPtr();
				oldTileBits = m_pOldImageTileArray[yIdx*m_nTileNumX + xIdx].GetBitsPtr();
		
				int IsQual = 1 ;
				if (oldTileBits != NULL)
				{
					IsQual = memcmp(curTileBits,oldTileBits,bufSize);
				}
				if (0 != IsQual)
				{
					//�����һ������ͼ��
					ImageMsg* pImageMsg = new ImageMsg;
					CxImage encoder;
					//����JPEGѹ��
					if (encoder.CreateFromArray((BYTE*)curTileBits,
						m_pTileRectArray[yIdx*m_nTileNumX + xIdx].right - m_pTileRectArray[yIdx*m_nTileNumX + xIdx].left,
						m_pTileRectArray[yIdx*m_nTileNumX + xIdx].bottom - m_pTileRectArray[yIdx*m_nTileNumX + xIdx].top,
						24,
						(m_pTileRectArray[yIdx*m_nTileNumX + xIdx].right - m_pTileRectArray[yIdx*m_nTileNumX + xIdx].left)*3,
						true))
					{
						BYTE* buffer = 0;
						long   size;
						encoder.SetJpegQuality(m_ImageQuallity);
						encoder.Encode(buffer,size,CXIMAGE_FORMAT_JPG);
						//���ͼ����Ϣ��������Ϣ������Ϣ���У������Ϣ����֮ʱ�ǿ������ݣ����Դ����֮����Ҫ�ͷŴ�������tuxiangbuffer
						pImageMsg->PacketMsg(m_pTileRectArray[yIdx*m_nTileNumX + xIdx],size,(char*)buffer);
						count += size;
						if (maxsize < size)
						{
							maxsize = size;
						}
						pMsgQueue->push(pImageMsg);
						encoder.FreeMemory(buffer);
					}
				}	
				//����ǰ����֡ͼ��ֿ黺��
				SwapImageTile(m_pImageTileArray[yIdx*m_nTileNumX + xIdx],m_pOldImageTileArray[yIdx*m_nTileNumX + xIdx]);	
		}
	}
	count;
	//memcpy(m_pOldScreenBits,m_ScreenImage.GetBits(),m_nScreenWidth*m_nScreenHeight*3);
#ifdef _TEST_ENCODE_TIME_
	time = m_Timer.GetElapsedSecond();
#endif
	return 1;
}

bool ScreenShot::SetQuality( int quality )
{
	if (quality<0 || quality >100)
	{
		return false;
	}
	m_ImageQuallity = quality;
	return true;
}

int ScreenShot::GetScreenWidth()
{
	return m_nScreenWidth;
}

int ScreenShot::GetScreenHeight()
{
	return m_nScreenWidth;
}

bool ScreenShot::IsPixelChange()
{
	return m_IsPixelChange;
}
