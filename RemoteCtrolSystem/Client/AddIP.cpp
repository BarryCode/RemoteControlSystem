// AddIP.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Client.h"
#include "AddIP.h"


// CAddIP �Ի���

IMPLEMENT_DYNAMIC(CAddIP, CDialog)

CAddIP::CAddIP(CWnd* pParent /*=NULL*/)
	: CDialog(CAddIP::IDD, pParent)
{

}

CAddIP::~CAddIP()
{
}

void CAddIP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddIP, CDialog)
	ON_BN_CLICKED(IDOK, &CAddIP::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddIP ��Ϣ�������

void CAddIP::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
