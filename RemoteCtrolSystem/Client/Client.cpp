// Client.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "ClientMain.h"
#include "ServerListDlg.h"
#include "..\Message\KeyboardMsg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientApp

BEGIN_MESSAGE_MAP(CClientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CClientApp ����

CClientApp::CClientApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
	m_lastTime = GetTickCount();
}


// Ψһ��һ�� CClientApp ����

CClientApp theApp;


// CClientApp ��ʼ��

BOOL CClientApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));


	CClientMain dlg;
	m_pMainWnd = &dlg;

	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}


	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

//BOOL CClientApp::PreTranslateMessage(MSG* pMsg)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//
//	return CWinApp::PreTranslateMessage(pMsg);
//}

BOOL CClientApp::OnIdle(LONG lCount)
{
	// TODO: �ڴ����ר�ô����/����û���


	return CWinApp::OnIdle(lCount);
}

BOOL CClientApp::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	//static float sLastTime = GetTickCount(); 

	if(WM_MOUSEMOVE == pMsg->message)
	{
		DWORD  curTime = GetTickCount();
		if (curTime - m_lastTime > 1000/24)
		{
			CPoint mousePoint;
			GetCursorPos(&mousePoint);
			if (m_oldMousePos != mousePoint)
			{		
				((CClientMain*)m_pMainWnd)->SendMouseMsg(mousePoint.x,mousePoint.y,0);
			}
			m_oldMousePos = mousePoint;
			m_lastTime = curTime;
		}		
	}
	if(pMsg->message >= WM_LBUTTONDOWN && pMsg->message <= WM_MBUTTONDBLCLK )
	{
		CPoint mousePoint;
		GetCursorPos(&mousePoint);
		((CClientMain*)m_pMainWnd)->SendMouseMsg(mousePoint.x,mousePoint.y,pMsg->message);
	}

	if (WM_MOUSEWHEEL == pMsg->message)
	{
		CPoint mousePoint;
		GetCursorPos(&mousePoint);
		((CClientMain*)m_pMainWnd)->SendMouseMsg(mousePoint.x,mousePoint.y,(short)HIWORD(pMsg->wParam));
	}

	if (WM_KEYDOWN==pMsg->message||WM_SYSKEYDOWN == pMsg->message)
	{
		if( GetKeyState(VK_CONTROL) < 0 && 
			GetKeyState(VK_SHIFT) < 0 &&
			GetKeyState(VK_RETURN) < 0)
		{
			if (((CClientMain*)m_pMainWnd)->IsFullScreen())
			{
				((CClientMain*)m_pMainWnd)->EndFullScreen();
			}
			else
			{
				((CClientMain*)m_pMainWnd)->FullScreen();
			}

			return true;
		}
	
		((CClientMain*)m_pMainWnd)->SendKeyboardMsg(pMsg->wParam,RCS_KEY_DOWN);
		if (((CClientMain*)m_pMainWnd)->IsFullScreen())
		{
			return TRUE;
		}
	}
	if (WM_KEYUP==pMsg->message||WM_SYSKEYUP == pMsg->message)
	{
		((CClientMain*)m_pMainWnd)->SendKeyboardMsg(pMsg->wParam,RCS_KEY_UP);
		if (((CClientMain*)m_pMainWnd)->IsFullScreen())
		{
			return TRUE;
		}
	}

	//float  fCurTime = GetTickCount(); 
	//if (fCurTime - sLastTime > 100)
	//{
	//	((CClientMain*)m_pMainWnd)->DealMessage();
	//}
	return CWinApp::PreTranslateMessage(pMsg);
}
