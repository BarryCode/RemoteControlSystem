#pragma once
#include "resource.h"
#include "afxwin.h"

// CEnterDlg �Ի���

class CEnterDlg : public CDialog
{
	DECLARE_DYNAMIC(CEnterDlg)

public:
	CEnterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEnterDlg();

// �Ի�������
	enum { IDD = IDD_ENTERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOk();
	CEdit m_enterPwd;  
	afx_msg void OnBnClickedBtnCancel();
};
