#pragma once
#include "resource.h"
#include "..\ClientConfig\HostListConfig.h"
#include "afxwin.h"
#include "afxcmn.h"

// CAddIpDlg �Ի���

class CAddIpDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddIpDlg)

public:
	CAddIpDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddIpDlg();

	/**
	   @brief:������������Ϣ��HostListConfigָ�봫��AddIpDlg
	   @Parameter:HostListConfig * hostListConfig
	   @Return:void
	*/
	void SetHostList(HostListConfig* hostListConfig);
	/**
	   @brief:���ص�ǰ��ӵ��µ�������Ϣ��������
	   @Return:CString
	*/
	CString GetAddName();
// �Ի�������
	enum { IDD = IDD_ADD_IP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	HostListConfig* m_HostListConfig;
	CString m_szHostName;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	
private:
	CIPAddressCtrl	m_HostIP;
	CEdit m_tbHostName;
	CEdit m_tbPort;
};  
