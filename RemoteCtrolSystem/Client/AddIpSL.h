#pragma once


// CAddIpSL �Ի���

class CAddIpSL : public CDialog
{
	DECLARE_DYNAMIC(CAddIpSL)

public:
	CAddIpSL(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddIpSL();

// �Ի�������
	enum { IDD = IDD_ADD_IP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
