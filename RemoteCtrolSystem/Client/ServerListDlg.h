#pragma once
#include "afxwin.h"
#include "..\ClientConfig\HostListConfig.h"
#include <vector>

#define SL_HIDE 0
#define SL_UNDOCK 1
#define SL_DOCK_WINDOW 2
#define SL_DOCK_SCREEN 3
// CServerListDlg �Ի���

class CServerListDlg : public CDialog
{
	DECLARE_DYNAMIC(CServerListDlg)

public:
	CServerListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CServerListDlg();

	/**
	   @brief:����Զ���б��״̬��0���أ�1��ͣ����2ͣ�����ڱ�Եͣ����3ͣ����Ļ��Ե
	   @Return:int
	*/
	int GetStatus();
	/**
	   @brief:����Զ���б�״̬��0���أ�1��ͣ����2ͣ�����ڱ�Եͣ����3ͣ����Ļ��Ե
	   @Parameter:int status
	   @Return:bool
	*/
	bool SetStatus(int status);
	bool Init(HostListConfig* hostListConfig);
	/**
	   @brief:��������������Ϣ��HostListConfig����Զ���б���
	   @Parameter:HostListConfig * hostListConfig
	   @Return:void
	*/
	void SetHostList(HostListConfig* hostListConfig);
	/**
	   @brief:��Զ���б�ͣ���������Ҳ�
	   @Return:void
	*/
	void DockWindow();
// �Ի�������
	enum { IDD = IDD_DIALOG_SERVER_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
//	virtual BOOL OnInitDialog();
	CToolBar	m_toolbar;
	//CListBox	m_lstServer;
	int			m_Status;//serverList��״̬����ʾ/����/ͣ����Ļ��Ե
	std::vector<Host> m_vtHostList;
	HostListConfig* m_HostListConfig;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);	
	afx_msg void OnExitSizeMove();
	afx_msg void OnBtnDelete();
	virtual BOOL OnInitDialog();
	CListBox m_lstServer;
};
