#pragma once


// CAddIP �Ի���

class CAddIP : public CDialog
{
	DECLARE_DYNAMIC(CAddIP)

public:
	CAddIP(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddIP();

// �Ի�������
	enum { IDD = IDD_ADD_IP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
