// Client.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CClientApp:
// �йش����ʵ�֣������ Client.cpp
//

class CClientApp : public CWinApp
{
public:
	CClientApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
protected:
	CPoint m_oldMousePos;
	DWORD  m_lastTime;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

extern CClientApp theApp;