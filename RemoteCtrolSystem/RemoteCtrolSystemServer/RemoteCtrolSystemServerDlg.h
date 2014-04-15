// RemoteCtrolSystemServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "TabServerDlg.h"
#include "TabAccountDlg.h"
#include "TabConnectionDlg.h"

#include "DealConnection.h"
#include "TabAboutDlg.h"
#include "WndClassList.h"
#include "AES.h"
#include "afxwin.h"

#include "../SocketIPv4/TCPThreadedServer.h"
// CRemoteCtrolSystemServerDlg �Ի���
class CRemoteCtrolSystemServerDlg : public CDialog
{
// ����
public:
	CRemoteCtrolSystemServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_REMOTECTROLSYSTEMSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabCtrl;
	TabServerDlg m_tsdServer;
	TabConnectionDlg m_dlgConnection;
	TabAccountDlg m_dlgAcount;
	TabAboutDlg m_dlgAbout;
	
	//CAboutDlg m_dlgAbout;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnOk();

	//************************************
	// Method:    SetAutoRun ���ÿ���������
	// Parameter: BOOL bAutoRun  true��ʾ����������false��ʾ����������
	// Returns:   void
	//************************************
	void SetAutoRun(BOOL bAutoRun);

	afx_msg void OnBnClickedBtnApply();
	LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);

	/**
	 * @Brief AddToTray �������ͼ��
	 * @Returns void
	 * @Remark  
	 **/
	void AddToTray();

	/**
	 * @Brief DeleteFromTray  ɾ������ͼ��
	 * @Returns void
	 * @Remark  
	 **/
	void DeleteFromTray();

	//************************************
	// Method:    UpdateWindowControl  ���������ļ�������ϵͳ����Ϊ�����翪������������Զ�����ӵ�
	// Returns:   void
	//************************************
	void UpdateWindowControl();
	afx_msg void OnBnClickedBtnStartserver();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	TCPThreadedServer m_threadServer;  //ʹ�ö��̵߳�TCP������
	TCPServiceFactoryTemplate<DealConnection> servicFactory;  //���ڴ���һ��TCP���Ӷ���Ĺ���
	CButton m_btnStartServer;

private:
	BOOL m_bIsServerStarted;
	SystemMonitor watcher;  //ϵͳ����������������Ӧ�ó���������Ͷ��ļ�ϵͳ�Ĳ���
};
