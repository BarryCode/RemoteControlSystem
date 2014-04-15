// AddUserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteCtrolSystemServer.h"
#include "AddUserDlg.h"

#include "UserFile.h"

// CAddUserDlg �Ի���

IMPLEMENT_DYNAMIC(CAddUserDlg, CDialog)

CAddUserDlg::CAddUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddUserDlg::IDD, pParent)
	, m_stats(0)
{
	lstrcpy(m_user.name,_T(""));
	lstrcpy(m_user.pwd,_T(""));	
	m_user.power = 0;
	m_stats = ADD;
}

CAddUserDlg::~CAddUserDlg()
{
}

void CAddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ET_NAME, m_editName);
}


BEGIN_MESSAGE_MAP(CAddUserDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CAddUserDlg::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CAddUserDlg::OnBnClickedBtnCancel)
END_MESSAGE_MAP()


// CAddUserDlg ��Ϣ�������

BOOL CAddUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	SetDlgItemText(IDC_ET_NAME,m_user.name);
	SetDlgItemText(IDC_ET_PWD,m_user.pwd);
	if (m_user.power == 0)
	{
		((CButton *)GetDlgItem(IDC_RD_VIEW))->SetCheck(TRUE);
	}
	else if (m_user.power == 1)
	{
		((CButton *)GetDlgItem(IDC_RD_CONTROL))->SetCheck(TRUE);
	}
	if (m_stats == EDIT)
	{
		((CButton*)GetDlgItem(IDC_ET_NAME))->EnableWindow(FALSE);
		((CButton*)GetDlgItem(IDC_ET_PWD))->EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CAddUserDlg::OnBnClickedBtnOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	if (BST_CHECKED==((CButton *)GetDlgItem(IDC_RD_VIEW))->GetCheck()) //�ۿ�ѡ���ѡ��
	{
		m_user.power = 0;
		TRACE("�ǹۿ�Ȩ����\n");
	}
	else  //����ѡ���ѡ��
	{
		m_user.power = 1;
		TRACE("�ҿ��Կ���Ŷ\n");
	}
	
	if (GetDlgItemText(IDC_ET_NAME,m_user.name,20))
	{
		TRACE(_T("\n%s"),m_user.name);
	}
	if (GetDlgItemText(IDC_ET_PWD,m_user.pwd,15))
	{
		TRACE(_T("\n%s"),m_user.pwd);
	}

	CUserFile fileOp;
	if (m_stats == ADD)  //���״̬��
	{
		fileOp.Add(m_user);
	}
	else  //�༭״̬��
	{
		fileOp.Update(m_user);
	}
	
	OnOK();
	//user.power =

}

void CAddUserDlg::OnBnClickedBtnCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}

void CAddUserDlg::SetUserData( UserData user )
{
	m_user = user;
}

void CAddUserDlg::SetStats( int stats )
{
	m_stats = stats;
}
