#include "ScreenDisplay.h"


ScreenDisplay::ScreenDisplay(void)
{
	m_hClientDC = NULL;
}

ScreenDisplay::~ScreenDisplay(void)
{
}

bool ScreenDisplay::Initialize( HWND hDisplayWin ,int WinWidth,int WinHeight,int ServerWidth,int ServerHeight)
{
	RECT rcClient;
	GetWindowRect(hDisplayWin,&rcClient);
	int DisplayWidth = rcClient.right - rcClient.left;
	int DisplayHeight = rcClient.bottom - rcClient.top;
	m_ServerWidth   = ServerWidth;
	m_ServerHeight  = ServerHeight; 
	if (!SetDevice(hDisplayWin))
	{
		return false;
	}
	if (!SetSize(DisplayWidth,DisplayHeight))
	{
		return false;
	}
	
 
	m_DisplayWidth  = WinWidth;
	m_DisplayHeight = WinHeight;
	return true;	
}

bool ScreenDisplay::SetDevice( HWND hDisplayWin )
{
	if (NULL == hDisplayWin)
	{
		return false;
	}
	m_hClientWnd = hDisplayWin;
	m_hClientDC = GetDC(hDisplayWin); //����ʾ���ڵ�HDC
	m_hMemDC = CreateCompatibleDC(m_hClientDC);
	m_FrameBuffer.Create(m_ServerWidth,m_ServerHeight,24,CXIMAGE_FORMAT_JPG);

	return true;
}

void ScreenDisplay::Display()
{
	
	m_FrameBuffer.Stretch(m_hMemDC,m_WinWidth/2 - m_DisplayWidth/2,m_WinHeight/2	- m_DisplayHeight/2,m_DisplayWidth,m_DisplayHeight);
    BitBlt(m_hClientDC,0,0,m_WinWidth,m_WinHeight,m_hMemDC,0,0,SRCCOPY);
}

void ScreenDisplay::RecvImageMsg( ByteArrayMsg* pMsg )
{
	ImageMsg* pImageMsg = static_cast<ImageMsg*>(pMsg);
	CxImage   msgImage;
	RECT	  rcDisplay = pImageMsg->GetImageRect();

	size_t size2 = pImageMsg->GetImageSize();
	msgImage.Decode((BYTE*)(pImageMsg->GetImageBufferPtr()),pImageMsg->GetImageSize(),CXIMAGE_FORMAT_JPG);
	//msgImage.Stretch(m_hClientDC,ScaleRect(rcDisplay));
	//�ܹ������MixFrom��ʽ��ͼ�񱣴��CxImage֮��ͼ��ֿ����µߵ�
	m_FrameBuffer.MixFrom(msgImage,rcDisplay.left,m_ServerHeight - rcDisplay.bottom );

	delete pImageMsg;
}

bool ScreenDisplay::SetSize( int width,int height )
{
	if (width <= 0 || height <= 0)
	{
		return false;
	}
	//����ʾ������С�ı䣬ˢ�±���
	if (m_WinWidth != width ||m_WinHeight != height)
	{
		m_WinWidth  = width;
		m_WinHeight = height;
		m_hBitmap = CreateCompatibleBitmap(m_hClientDC,m_WinWidth,m_WinHeight);
		m_hOldBmp = SelectObject(m_hMemDC,m_hBitmap);
	}
	return true;
}

int ScreenDisplay::GetDisplayWidth()
{
	return m_DisplayWidth;
}

int ScreenDisplay::GetDisplayHeight()
{
	return m_DisplayHeight;
}

CxImage ScreenDisplay::GetDisplayImage()
{
	return m_FrameBuffer;
}

RECT ScreenDisplay::ScaleRect( RECT srcRect )
{
	RECT	DisplayRect;
	//��ʾ��������ʾ��Ļ��������Ϊ���ĵ����ţ�������㱾�����Ͻ���ʼ��
	int		leftBegin	= m_WinWidth/2 - m_DisplayWidth/2;
	int		topBegin	= m_WinHeight/2	- m_DisplayHeight/2;
	//���㴫��ľ����ڱ�����ʾ�����е�ʵ�ʾ���λ��
	DisplayRect.left	= leftBegin		+ (srcRect.left		* m_DisplayWidth)/m_ServerWidth;
	DisplayRect.right	= leftBegin		+ (srcRect.right	* m_DisplayWidth)/m_ServerWidth;
	DisplayRect.top 	= topBegin		+ (srcRect.top		* m_DisplayHeight)/m_ServerHeight;
	DisplayRect.bottom 	= topBegin		+ (srcRect.bottom	* m_DisplayHeight)/m_ServerHeight;

	return DisplayRect;
}

void ScreenDisplay::SetServerSize( int ServerWidth,int ServerHeight )
{
	m_ServerHeight	= ServerHeight;
	m_ServerWidth	= ServerWidth;
	m_FrameBuffer.Create(m_ServerWidth,m_ServerHeight,24,CXIMAGE_FORMAT_JPG);
}

int ScreenDisplay::GetSeverWidth()
{
	return m_ServerWidth;
}

int ScreenDisplay::GetServerHeight()
{
	return m_ServerHeight;
}

bool ScreenDisplay::ScaleUp()
{
	m_DisplayWidth *= 1.1;
	m_DisplayHeight *= 1.1;
	if(m_DisplayWidth >= m_ServerWidth * 2.0/*m_WinWidth*/)
	{
		m_DisplayWidth = m_ServerWidth * 2.0;
		m_DisplayHeight = m_ServerHeight * 2.0;
		ReflashDC();
		return false;
	}
	else
	{
		ReflashDC();
		return true;
	}
}

bool ScreenDisplay::ScaleDown()
{
	m_DisplayWidth /= 1.25;
	m_DisplayHeight /= 1.25;
	if(m_DisplayWidth <= 480)
	{
		m_DisplayWidth = 480;
		m_DisplayHeight = 360;
		ReflashDC();
		return false;
	}
	else
	{
		ReflashDC();
		return true;
	}
	
}

bool ScreenDisplay::ReflashDC()
{
	//ˢ�±���
	m_hBitmap = CreateCompatibleBitmap(m_hClientDC,m_WinWidth,m_WinHeight);
	m_hOldBmp = SelectObject(m_hMemDC,m_hBitmap);
	//BitBlt(m_hClientDC,0,0,m_WinWidth,m_WinHeight,m_hMemDC,0,0,SRCCOPY);
	DeleteObject(m_hOldBmp);
	return true;
}

int ScreenDisplay::GetWinWidth()
{
	return m_WinWidth;
}

int ScreenDisplay::GetWinHeigth()
{
	return m_WinHeight;
}

void ScreenDisplay::Scale2LocalSize()
{
	m_DisplayWidth = m_WinWidth;
	m_DisplayHeight = m_WinHeight;
	ReflashDC();
}
