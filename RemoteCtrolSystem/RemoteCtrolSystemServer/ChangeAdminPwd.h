#pragma once

#include "Resource.h"
// CChangeAdminPwd �Ի���

class CChangeAdminPwd : public CDialog
{
	DECLARE_DYNAMIC(CChangeAdminPwd)

public:
	CChangeAdminPwd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeAdminPwd();

// �Ի�������
	enum { IDD = IDD_CHANGE_PWD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnNewpwdok();
	CString m_strNewPwd;  //�ɵ�����
	CString m_strSurePwd;  //������
	afx_msg void OnBnClickedBtnNewpwdcancel();
};
