// TabConnectionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabConnectionDlg.h"
#include "RemoteCtrolSystemServer.h"


// TabConnectionDlg �Ի���

IMPLEMENT_DYNAMIC(TabConnectionDlg, CDialog)

TabConnectionDlg::TabConnectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TabConnectionDlg::IDD, pParent)
{

}

TabConnectionDlg::~TabConnectionDlg()
{
}

void TabConnectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONCETION_LIST, m_listConnection);
}


BEGIN_MESSAGE_MAP(TabConnectionDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_BROKEN, &TabConnectionDlg::OnBnClickedBtnBroken)
	ON_BN_CLICKED(IDC_BT_OPERATOR, &TabConnectionDlg::OnBnClickedBtOperator)
END_MESSAGE_MAP()


// TabConnectionDlg ��Ϣ�������

BOOL TabConnectionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_listConnection.SetExtendedStyle(m_listConnection.GetExtendedStyle()| LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	LVCOLUMN lvcol;
	lvcol.mask = LVCF_TEXT | LVCF_FMT | LVCF_SUBITEM | LVCF_WIDTH;
	lvcol.fmt = LVCFMT_CENTER;
	lvcol.pszText = L"��¼��";
	lvcol.iSubItem = 1;  //�������ص��ӱ���������
	lvcol.cx = 120;

	m_listConnection.InsertColumn(0,&lvcol);
	lvcol.pszText = L"IP��ַ";
	m_listConnection.InsertColumn(1,&lvcol);
	lvcol.cx = 70;
	lvcol.pszText = L"Ȩ��";
	m_listConnection.InsertColumn(2,&lvcol);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void TabConnectionDlg::AddConnection( ConnectionData data )
{
	m_ConnectionData.push_back(data);
}

void TabConnectionDlg::UpdateList()
{
	m_listConnection.DeleteAllItems();
	std::vector<ConnectionData>::iterator iter;
	for (iter = m_ConnectionData.begin();iter!=m_ConnectionData.end();iter++)
	{
		int nIndex = m_listConnection.GetItemCount();
		LV_ITEM lvItem;
		lvItem.mask = LVIF_TEXT ; 
		lvItem.iItem = nIndex;     //����
		lvItem.iSubItem = 0;
		lvItem.pszText = _T("");
		//�����һ�в����¼ֵ.
		m_listConnection.InsertItem(&lvItem); 
		m_listConnection.SetItemText(nIndex,0,iter->username);
		//����������
		m_listConnection.SetItemText(nIndex,1,iter->ip);
		if (iter->status == 0)
		{
			m_listConnection.SetItemText(nIndex,2,_T("�ۿ�"));
		}
		else
		{
			m_listConnection.SetItemText(nIndex,2,_T("����"));
		}
	}
}

BOOL TabConnectionDlg::IsUserLogined(CString name)
{
	std::vector<ConnectionData>::iterator iter;
	for (iter = m_ConnectionData.begin();iter!=m_ConnectionData.end();iter++)
	{
		if(iter->username == name)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void TabConnectionDlg::OnBnClickedBtnBroken()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = m_listConnection.GetFirstSelectedItemPosition();
	if (NULL == pos)
	{
		TRACE(_T("No item were selected!\n"));
		AfxMessageBox(_T("��ѡ��Ҫ�Ͽ����ӵ��У�"));
	}
	else
	{

		int nItem = m_listConnection.GetNextSelectedItem(pos);
		m_ConnectionData[nItem].connection->disconnect();
		std::vector<ConnectionData>::iterator iter = m_ConnectionData.begin();
		m_ConnectionData.erase(iter+nItem);
		this->UpdateList();
	}
}

void TabConnectionDlg::DeleteItemByConnection( TCPConnection *connection )
{
	std::vector<ConnectionData>::iterator iter;
	for (iter = m_ConnectionData.begin();iter!=m_ConnectionData.end();iter++)
	{
		if(iter->connection == connection)
		{
			m_ConnectionData.erase(iter);
			this->UpdateList();
			return ;
		}
	}
	
}

void TabConnectionDlg::LoginOutAllUser()
{
	std::vector<ConnectionData>::iterator iter;
	for (iter = m_ConnectionData.begin();iter!=m_ConnectionData.end();iter++)
	{
		iter->connection->disconnect();
	}
	m_ConnectionData.clear();
	this->UpdateList();
}

void TabConnectionDlg::OnBnClickedBtOperator()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	COperationDlg operation;
	POSITION pos = m_listConnection.GetFirstSelectedItemPosition();
	if (NULL == pos)
	{
		/*TRACE(_T("No item were selected!\n"));
		AfxMessageBox(_T("��ѡ��Ҫ�Ͽ����ӵ��У�"));*/
		operation.DoModal();
	}
	else
	{
		int nItem = m_listConnection.GetNextSelectedItem(pos);
		TCHAR szBuff[1024];
		LVITEM lvi;
		lvi.iItem = nItem;
		lvi.iSubItem = 0;
		lvi.mask = LVIF_TEXT;
		lvi.pszText = szBuff;
		lvi.cchTextMax = 1024;
		m_listConnection.GetItem(&lvi);

		TCHAR name[20];
		lstrcpy(name,lvi.pszText);
		operation.SetNameAndType(CString(name),0);
		operation.DoModal();
	}
	
}
