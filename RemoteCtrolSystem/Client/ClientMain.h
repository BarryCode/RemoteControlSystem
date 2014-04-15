#pragma once

#include "LoginDialog.h"
#include "AddIpDlg.h"
#include "ServerListDlg.h"
#include "SetupDlg.h"
#include "DisplayDlg.h"
#include "..\\ClientConfig\HostListConfig.h"
#include "..\\Graphic\ScreenDisplay.h"
#include "..\\Graphic\ScreenShot.h"
#include "..\SocketIPv4\TCPClient.h"
#include "../Thread/LocalMutex.h"
#include "../Thread/AutoLock.h"
#include <queue>
#include <vector>
#include "afxwin.h"
// CClientMain �Ի���

class CClientMain : public CDialog
{
	DECLARE_DYNAMIC(CClientMain)

public:
	CClientMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CClientMain();


// �Ի�������
	enum { IDD = IDD_CIENT_MAIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	CToolBar		m_MainToolBar;
	CAddIpDlg		m_dlgAddIP;
	CLoginDialog	m_cmbLogin;
	CServerListDlg	m_dlgServerList;
	CSetupDlg		m_dlgSetup;
	CDisplayDlg		m_dlgDisplay;
	CStatic			m_pctDisplay;
	bool			m_IsFullScreen;
	ScreenDisplay	m_ScreenDisplayer;
	int				m_Frame;
	UINT_PTR		m_nTimer;
	HostListConfig	m_HostListConfig;
	TCPClient		m_tcpClien;
	BOOL			m_AltCheck;
	BOOL			m_WinCheck;
	BOOL			m_CtrlCheck;
	BOOL			m_bTcpConect;
	BOOL			m_bCtrlPermission;
	//TcpClient*		m_pTcpClient;
	std::vector<Host>			m_vtHostList;
	std::queue<ByteArrayMsg*>	m_SendQueue;
	std::queue<ByteArrayMsg*>	m_RecvQueue;
	//����ʹ��
	ScreenShot		m_ScreenShooter;
	LocalMutex m_mLocaMutex;
	
	
	DECLARE_MESSAGE_MAP()
	/**
	   @brief:��Ļ��ͼ����ʵ�ʵ��õĺ���
	   @Return:void
	*/
	void			OnScreenShot();
	afx_msg int		OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void	OnMove(int x, int y);
	afx_msg void	OnSize(UINT nType, int cx, int cy);
	//
	/**
	   @brief:��������ť��Ϣ������Զ���б�
	   @Return:void
	*/
	afx_msg void	OnBtnServerList();
	/**
	   @brief:��������ť��Ϣ���������ô���
	   @Return:void
	*/
	afx_msg void	OnBtnSetup();
	/**
	   @brief:��������ť��Ϣ����Ļ��ͼ����
	   @Return:void
	*/
	afx_msg void	OnBtnScreenShot();
	/**
	   @brief:��������ť��Ϣ��ȫ����ʾ
	   @Return:void
	*/
	afx_msg void	OnBtnFullScreen();
	/**
	   @brief:��������ť��Ϣ�����¹������ϵ�alt��
	   @Return:void
	*/
	afx_msg void	OnBtnAlt();
	/**
	   @brief:��������ť��Ϣ�����¹������ϵ�Ctrl��
	   @Return:void
	*/
	afx_msg void	OnBtnCtrl();
   /**
	   @brief:��������ť��Ϣ�����¹������ϵ�winkey��
	   @Return:void
	*/
	afx_msg void	OnBtnWin();
	/**
	   @brief:��������ť��Ϣ������ʾ��С��Ϊ���طֱ��ʴ�С
	   @Return:void
	*/
	afx_msg void	OnBtnScaleLocalSize();
	/**
	   @brief:��������ť��Ϣ���Ŵ���ʾ��С
	   @Return:void
	*/
	afx_msg void	OnBtnScaleUp();
	/**
	   @brief:��������ť��Ϣ����С��ʾ��С
	   @Return:void
	*/
	afx_msg void	OnBtnScaleDown();
	/**
	   @brief:��������ť��Ϣ����Զ���������ʹ������������Ϣ
	   @Return:void
	*/
	afx_msg void	OnBtnTackMgr();
	/**
	   @brief:��������ť��Ϣ�����ڽ�������ʾ�Ķ�ʱ���ص�����
	   @Parameter:UINT_PTR nIDEvent
	   @Return:void
	*/
	afx_msg void	OnTimer(UINT_PTR nIDEvent);
	afx_msg LRESULT OnAddIpMessage(WPARAM wParam, LPARAM lParam);
public:
	/**
	   @brief:��ʼ��Tcp���ӣ��������1��ʾ�п���Ȩ�ޣ�0��ʾ�ۿ�Ȩ�ޣ�С��0�����޷����ӡ�
	   @Parameter:Host host
	   @Parameter:UserMsg * userMsg
	   @Return:int
	*/
	int InitTcpClien(Host host,UserMsg* userMsg);
		/**
	   @brief:����ÿ����ʾ��֡��
	   @Parameter:int frame
	   @Return:bool
	*/
	bool SetFrame(int frame);
	/**
	   @brief:����ͼ������
	   @Parameter:int quality
	   @Return:bool
	*/
	bool SetImageQuality(int quality);
	/**
	   @brief:���������Ϣ
	   @Parameter:int x
	   @Parameter:int y
	   @Parameter:int MouseStatus
	   @Return:void
	*/
	void SendMouseMsg(int x,int y,int MouseStatus);
	/**
	   @brief:���ͼ�����Ϣ
	   @Parameter:int key
	   @Parameter:int status
	   @Return:void
	*/
	void SendKeyboardMsg(int key,int status);
	/**
	   @brief:���÷ֿ�������ᷢ�͸ı�ֿ���Ϣ�������
	   @Parameter:int Horz
	   @Parameter:int Vert
	   @Return:void
	*/
	void SetTileNumber(int Horz,int Vert);
	/**
	   @brief:����ȫ��ģʽ
	   @Return:bool
	*/
	bool EndFullScreen();
	/**
	   @brief:����ȫ��ģʽ
	   @Return:void
	*/
	void FullScreen();
	/**
	   @brief:���ص�ǰ�Ƿ���ȫ��ģʽ
	   @Return:bool
	*/
	bool IsFullScreen();
	/**
	   @brief:������յ���Ϣ
	   @Return:void
	*/
	void DealMessage();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual void OnOK();
public:
	afx_msg void OnDestroy();
};
