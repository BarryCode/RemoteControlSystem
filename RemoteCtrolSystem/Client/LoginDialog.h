#pragma once
#include "afxwin.h"
#include "AddIpDlg.h"
#include "..\ClientConfig\HostListConfig.h"
#include "..\Message\UserMsg.h"
#include <vector>

// CLoginDialog �Ի���

class CLoginDialog : public CDialog
{
	DECLARE_DYNAMIC(CLoginDialog)

public:
	CLoginDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDialog();

	void	Init(HostListConfig* pHostListConfig,Host* pHost);
	/**
	   @brief:�����û���
	   @Return:CString
	*/
	CString GetUserName();
	/**
	   @brief:��������
	   @Return:CString
	*/
	CString	GetPassword();

// �Ի�������
	enum { IDD = IDD_LOGIN_DIALOG };

	CAddIpDlg	m_dlgAddIP;
	CComboBox	m_cmbServerList;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CEdit		m_tbPassword;
	CEdit		m_tbUserName;
	CString		m_szUserName; 
	CString		m_szPassword; 
	
	/**
	   @brief:��¼��ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonLogin();
	/**
	   @brief:ѡ��Զ�����������б�ʱ
	   @Return:void
	*/
	afx_msg void OnCbnSelchangeServerCombo();
	/**
	   @brief:�˳���ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonExit();
protected:
	virtual void OnOK();
	Host*						m_pHost;
	HostListConfig*				m_HostListConfig;
	std::vector<Host>			m_vtHostList;
public:
	virtual BOOL OnInitDialog();
};
