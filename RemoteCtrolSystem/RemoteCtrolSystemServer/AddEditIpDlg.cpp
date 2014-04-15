// AddEditIpDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteCtrolSystemServer.h"
#include "AddEditIpDlg.h"
#include "IpRuleFile.h"

#include <strsafe.h>


// CAddEditIpDlg �Ի���

IMPLEMENT_DYNAMIC(CAddEditIpDlg, CDialog)

CAddEditIpDlg::CAddEditIpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddEditIpDlg::IDD, pParent)
	, m_stats(0)
{

	lstrcpy(m_rule.start,_T(""));
	lstrcpy(m_rule.end,_T(""));	
	m_rule.power = 0;
	m_stats = ADD;
}

CAddEditIpDlg::~CAddEditIpDlg()
{
}

void CAddEditIpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IP_START, m_ipStart);
	DDX_Control(pDX, IDC_IP_END, m_ipEnd);
}


BEGIN_MESSAGE_MAP(CAddEditIpDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CAddEditIpDlg::OnBnClickedBtnOk)
END_MESSAGE_MAP()


// CAddEditIpDlg ��Ϣ�������



BOOL CAddEditIpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	/*((CButton *)GetDlgItem(IDC_RD_REJECT))->SetCheck(TRUE);
	SetDlgItemText(IDC_ET_NAME,m_user.name);
	SetDlgItemText(IDC_ET_PWD,m_user.pwd);*/

	m_ipStart.SetWindowText(m_rule.start);
	m_ipEnd.SetWindowText(m_rule.end);
	if (m_rule.power == 0)  //�����ʾ��ֹ
	{
		((CButton *)GetDlgItem(IDC_RD_REJECT))->SetCheck(TRUE);
	}
	else if (m_rule.power == 1)  //�����ʾ����
	{
		((CButton *)GetDlgItem(IDC_RD_ALLOW))->SetCheck(TRUE);
	}

	if (m_stats == EDIT)  //�����洦�ڱ༭״̬
	{
		m_ipStart.EnableWindow(FALSE);
		m_ipEnd.EnableWindow (FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CAddEditIpDlg::OnBnClickedBtnOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������	
	BYTE f0,f1,f2,f3;
	m_ipStart.GetAddress(f0,f1,f2,f3);
	//CString ipAddrFirst ;
	//ipAddrFirst.Format(_T("%d.%d.%d.%d"),f0,f1,f2,f3);
	//MessageBox(ipAddrFirst);

	StringCbPrintf(m_rule.start,16*sizeof(TCHAR),_T("%d.%d.%d.%d"),f0,f1,f2,f3);
	m_ipEnd.GetAddress(f0,f1,f2,f3);
	if(f0 ==0 && f1 ==0 && f2 ==0 &&f3 ==0) //����ֹIP�ؼ�����Ϊ�գ���ʾֻ��Ծ���ĳһIP��ַ
	{
		lstrcpy(m_rule.end,m_rule.start);
	}
	else
	{
		StringCbPrintf(m_rule.end,16*sizeof(TCHAR),_T("%d.%d.%d.%d"),f0,f1,f2,f3);
	}
	
	CIpRuleFile ipFile;
	if(ipFile.CompareIpAddress(m_rule.start,m_rule.end)>0)
	{
		MessageBox(_T("��ֹIP��ַ������С����ʼIP��ַ��"));
		return ;
	}
	if (BST_CHECKED==((CButton *)GetDlgItem(IDC_RD_REJECT))->GetCheck())
	{
		m_rule.power = 0;
		TRACE("�Ǿܾ�Ȩ����\n");
	}
	else
	{
		m_rule.power = 1;
		TRACE("����Զ�̿���Ŷ\n");
	}
	
	
	if (m_stats == ADD)  //��Ϊ���״̬
	{
		ipFile.Add(m_rule);
	}
	else  //��Ϊ�༭״̬
	{
		ipFile.Update(m_rule);
	}
	CDialog::OnOK();
}

void CAddEditIpDlg::SetStats( int stats )
{
	this->m_stats = stats;
}

void CAddEditIpDlg::SetRule(IpRule rule )
{
	m_rule = rule;
}

