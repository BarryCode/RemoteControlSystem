// ChangeAdminPwd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChangeAdminPwd.h"
#include "Config.h"


// CChangeAdminPwd �Ի���

IMPLEMENT_DYNAMIC(CChangeAdminPwd, CDialog)

CChangeAdminPwd::CChangeAdminPwd(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeAdminPwd::IDD, pParent)
	, m_strNewPwd(_T(""))
	, m_strSurePwd(_T(""))
{

}

CChangeAdminPwd::~CChangeAdminPwd()
{
}

void CChangeAdminPwd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ED_NEWPWD, m_strNewPwd);
	DDX_Text(pDX, IDC_ED_NEWPWD2, m_strSurePwd);
}


BEGIN_MESSAGE_MAP(CChangeAdminPwd, CDialog)
	ON_BN_CLICKED(IDC_BTN_NEWPWDOK, &CChangeAdminPwd::OnBnClickedBtnNewpwdok)
	ON_BN_CLICKED(IDC_BTN_NEWPWDCANCEL, &CChangeAdminPwd::OnBnClickedBtnNewpwdcancel)
END_MESSAGE_MAP()


// CChangeAdminPwd ��Ϣ�������

void CChangeAdminPwd::OnBnClickedBtnNewpwdok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	Config config;
	if (m_strNewPwd==m_strSurePwd)
	{
		config.SetAdminLoginPwd(m_strSurePwd);  //��������д�������ļ���
		//iniFile.SetProfileString(_T("admin"),_T("adminPwd"),m_strNewPwd);
		OnOK();
	}
	else
	{
		AfxMessageBox(_T("�����������벻һ�£����֤�����ύ��"));
	}	
}

void CChangeAdminPwd::OnBnClickedBtnNewpwdcancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
