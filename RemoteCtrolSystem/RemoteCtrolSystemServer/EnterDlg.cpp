// EnterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EnterDlg.h"
#include "IniFile.h"
#include "RemoteCtrolSystemServerDlg.h"
#include "RemoteCtrolSystemServer.h"

// CEnterDlg �Ի���

IMPLEMENT_DYNAMIC(CEnterDlg, CDialog)

CEnterDlg::CEnterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterDlg::IDD, pParent)
{

}

CEnterDlg::~CEnterDlg()
{
}

void CEnterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ET_PWD, m_enterPwd);
}


BEGIN_MESSAGE_MAP(CEnterDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CEnterDlg::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CEnterDlg::OnBnClickedBtnCancel)
END_MESSAGE_MAP()


// CEnterDlg ��Ϣ�������

void CEnterDlg::OnBnClickedBtnOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString enterPwd,pwdInFile;
	m_enterPwd.GetWindowText(enterPwd);
	CIniFile conFile(_T("RemoteConfig.ini"));
	conFile.GetProfileString(_T("admin"),_T("adminPwd"),pwdInFile);
	if (enterPwd.Compare(pwdInFile) == 0)
	{
		OnOK();
		CRemoteCtrolSystemServerDlg dlg;
		((CRemoteCtrolSystemServerApp *)AfxGetApp())->m_pMainWnd = &dlg; //��������ϵͳ��������
		dlg.DoModal();
	}
	else
	{
		MessageBox(_T("�������"));
	}
}

void CEnterDlg::OnBnClickedBtnCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
