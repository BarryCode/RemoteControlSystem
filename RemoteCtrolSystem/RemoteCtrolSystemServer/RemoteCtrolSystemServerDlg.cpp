// RemoteCtrolSystemServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteCtrolSystemServer.h"
#include "RemoteCtrolSystemServerDlg.h"
#include "WndClassList.h"
#include "IniFile.h"
#include "Config.h"

#define WM_SHOWTASK (WM_USER + 101)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CRemoteCtrolSystemServerDlg �Ի���


CRemoteCtrolSystemServerDlg::CRemoteCtrolSystemServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemoteCtrolSystemServerDlg::IDD, pParent),m_bIsServerStarted(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != NO_ERROR)
	{
		MessageBox(_T("Error at WSAStartup()\n"));
	}
}

void CRemoteCtrolSystemServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
	DDX_Control(pDX, IDC_BTN_STARTSERVER, m_btnStartServer);
}

BEGIN_MESSAGE_MAP(CRemoteCtrolSystemServerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CRemoteCtrolSystemServerDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BTN_OK, &CRemoteCtrolSystemServerDlg::OnBnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_APPLY, &CRemoteCtrolSystemServerDlg::OnBnClickedBtnApply)
	ON_MESSAGE(WM_SHOWTASK,OnShowTask)
	ON_BN_CLICKED(IDC_BTN_STARTSERVER, &CRemoteCtrolSystemServerDlg::OnBnClickedBtnStartserver)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CRemoteCtrolSystemServerDlg ��Ϣ�������

BOOL CRemoteCtrolSystemServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	TCITEM item;
	item.mask = TCIF_TEXT;
	item.pszText = L"����";
	m_tabCtrl.InsertItem(0,&item);
	item.pszText = L"����";
	m_tabCtrl.InsertItem(1,&item);
	item.pszText = L"�˺Ź���";
	m_tabCtrl.InsertItem(2,&item);
	item.pszText = L"����";
	m_tabCtrl.InsertItem(3,&item);

	//����ѡ������ݵĲ��ֵĴ�С
	CRect rc;
	m_tabCtrl.GetClientRect(&rc);
	rc.top+=30;
	rc.bottom-=8;
	rc.left+=8;
	rc.right -=8;

	//�����ĸ�ѡ��
	m_tsdServer.Create(IDD_TAB_SERVER,&m_tabCtrl);
	m_dlgConnection.Create(IDD_TAB_CONNECTION,&m_tabCtrl);
	m_dlgAcount.Create(IDD_TAB_ACCOUNT,&m_tabCtrl);
	m_dlgAbout.Create(IDD_TAB_ABOUT,&m_tabCtrl);

	m_tsdServer.MoveWindow(&rc);
	m_dlgConnection.MoveWindow(&rc);
	m_dlgAcount.MoveWindow(&rc);
	m_dlgAbout.MoveWindow(&rc);

	m_tsdServer.ShowWindow(SW_SHOW);
	m_dlgAcount.ShowWindow(SW_HIDE);
	m_dlgConnection.ShowWindow(SW_HIDE);
	m_dlgAbout.ShowWindow(SW_HIDE);

	WndClassList::m_connectDlg = &m_dlgConnection;
	//m_tsdServer.SetWindowPos(NULL,10,30,440,240,SWP_SHOWWINDOW);
	//m_tsdServer.ShowWindow(SW_SHOW);
	UpdateWindowControl();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRemoteCtrolSystemServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		/*CAboutDlg dlgAbout;
		dlgAbout.DoModal();*/
	} else if(nID == SC_MINIMIZE)
	{
		CIniFile fileOp(_T("RemoteConfig.ini"));
		if (fileOp.GetProfileInt(_T("sets"),_T("showTask")) == 1)
		{
			AddToTray();
		}
		else
		{
			CDialog::OnSysCommand(nID,lParam);
		}
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRemoteCtrolSystemServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRemoteCtrolSystemServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//ѡ��л�����
void CRemoteCtrolSystemServerDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	switch(m_tabCtrl.GetCurSel())
	{
	case 0:
		{
			m_tsdServer.ShowWindow(SW_SHOW);
			m_dlgConnection.ShowWindow(SW_HIDE);
			m_dlgAcount.ShowWindow(SW_HIDE);
			m_dlgAbout.ShowWindow(SW_HIDE);
			break;
		}
	case 1:
		{
			m_tsdServer.ShowWindow(SW_HIDE);
			m_dlgConnection.ShowWindow(SW_SHOW);
			m_dlgAcount.ShowWindow(SW_HIDE);
			m_dlgAbout.ShowWindow(SW_HIDE);
			break;
		}
	case 2:
		{
			m_tsdServer.ShowWindow(SW_HIDE);
			m_dlgConnection.ShowWindow(SW_HIDE);
			m_dlgAcount.ShowWindow(SW_SHOW);
			m_dlgAbout.ShowWindow(SW_HIDE);
			break;
		}
	case 3:
		m_tsdServer.ShowWindow(SW_HIDE);
		m_dlgConnection.ShowWindow(SW_HIDE);
		m_dlgAcount.ShowWindow(SW_HIDE);
		m_dlgAbout.ShowWindow(SW_SHOW);
		{
			break;
		}
	default:
		break;
	}
	*pResult = 0;
}

void CRemoteCtrolSystemServerDlg::OnBnClickedBtnOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// �����ﱣ��������Ϣ
	m_tsdServer.UpdateConfig();
}

void CRemoteCtrolSystemServerDlg::SetAutoRun(BOOL bAutoRun)
{
	HKEY hKey;
	//ע���·��
	CString strRegPath = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
	TCHAR* lpszAppKeyName = _T("RemoteControlServer");
	//��ȡ�����ļ������ļ���
	TCHAR m_szAppPath[MAX_PATH];
	DWORD cch = GetModuleFileName(NULL,m_szAppPath,MAX_PATH);
	ASSERT(cch!=0);

	//��ע���
	if (ERROR_SUCCESS ==RegOpenKeyEx(HKEY_LOCAL_MACHINE,strRegPath,0,KEY_ALL_ACCESS,&hKey))
	{
		if (bAutoRun) //����������ӻ�ɾ��ע�����
		{
			RegSetValueEx(hKey,lpszAppKeyName,0,REG_SZ,(const unsigned char *)m_szAppPath,sizeof(m_szAppPath));
		}
		else
		{
			RegDeleteValue(hKey,lpszAppKeyName);
		}
	}
	RegCloseKey(hKey);
	

}

void CRemoteCtrolSystemServerDlg::OnBnClickedBtnApply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_tsdServer.UpdateConfig();
	this->UpdateWindowControl();
}

LRESULT CRemoteCtrolSystemServerDlg::OnShowTask( WPARAM wParam, LPARAM lParam )
{
	if(wParam != IDR_MAINFRAME)
		return 1;
	switch(lParam)
	{
	case WM_RBUTTONUP:                                        // �Ҽ�����ʱ�����˵�
		{

			LPPOINT lpoint = new tagPOINT;
			::GetCursorPos(lpoint);                    // �õ����λ��
			CMenu menu;
			menu.CreatePopupMenu();                    // ����һ������ʽ�˵�
			menu.AppendMenu(MF_STRING, WM_DESTROY, _T("�ر�"));
			menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x ,lpoint->y, this);
			HMENU hmenu = menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
		}
		break;
	case WM_LBUTTONDBLCLK:                                 // ˫������Ĵ���
		{
			this->ShowWindow(SW_SHOWNORMAL);         // ��ʾ������
			DeleteFromTray();
		}
		break;
	}
	return 0;
}

void CRemoteCtrolSystemServerDlg::AddToTray()
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK;
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	lstrcpy(nid.szTip,_T("�����Զ�̿��ơ��������"));
	Shell_NotifyIcon(NIM_ADD,&nid);
	ShowWindow(SW_HIDE);
}

void CRemoteCtrolSystemServerDlg::DeleteFromTray()
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));		
	Shell_NotifyIcon(NIM_DELETE,&nid);
}

void CRemoteCtrolSystemServerDlg::OnBnClickedBtnStartserver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��������������������ش���	
	if (m_bIsServerStarted)
	{
		m_threadServer.Stop();  //ֹͣTCP����
		WndClassList::m_connectDlg->LoginOutAllUser();
		MessageBox(_T("������ֹͣ"));
		((CButton*)GetDlgItem(IDC_BTN_STARTSERVER))->SetWindowText(_T("��������"));
		m_bIsServerStarted = FALSE;
	}
	else
	{
		Config config;
		int serverPort =config.GetConnectPort();
		m_threadServer.Start(servicFactory,serverPort);
		WndClassList::m_watcher = new SystemMonitor;
		MessageBox(_T("���������ɹ�"));
		((CButton*)GetDlgItem(IDC_BTN_STARTSERVER))->SetWindowText(_T("ֹͣ����"));
		m_bIsServerStarted = TRUE;
	}
	
}

void CRemoteCtrolSystemServerDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//AfxMessageBox(_T("aaaaaaaaaaa"));
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CRemoteCtrolSystemServerDlg::UpdateWindowControl()
{
	Config config;
	if (config.GetIsAllowControl())
	{
		((CButton* )GetDlgItem(IDC_BTN_STARTSERVER))->EnableWindow(TRUE);
	}
	else
	{
        ((CButton* )GetDlgItem(IDC_BTN_STARTSERVER))->EnableWindow(FALSE);
	}

	//�ж��Ƿ�����������
	if (config.GetIsAutoRun())
	{
		SetAutoRun(TRUE);
	}
	else
	{
		SetAutoRun(FALSE);
	}

	if (config.GetIsEncryptFile())
	{
	
		
		OFSTRUCT ofn;
		if(OpenFile("user.crypt",&ofn,OF_EXIST)==HFILE_ERROR)
		{
			//��������
			AES aes;
			char* key = "RemoteCtrolSystem";
			aes.set_key((u1byte*)key,256);
			aes.encrypt(_T("user"));
		}
		if(OpenFile("user.plain",&ofn,OF_EXIST)!=HFILE_ERROR)
		{
			//������
			OpenFile("user.plain",&ofn,OF_DELETE);
			//DeleteFile(_T("user.plain"));
		}
	
	}
	else  //�����ļ���ʾ���������ļ�
	{

		OFSTRUCT ofn;
		if(OpenFile("user.plain",&ofn,OF_EXIST)==HFILE_ERROR) //�����ֹر�ʧ�ܣ�˵���ļ�������
		{
			//��������
			AES aes;
			char* key = "RemoteCtrolSystem";
			aes.set_key((u1byte*)key,256);
			aes.decrypt(_T("user"));
		}
		if(OpenFile("user.crypt",&ofn,OF_EXIST)!=HFILE_ERROR)
		{
			//������
			OpenFile("user.crypt",&ofn,OF_DELETE);
			//DeleteFile(_T("user.crypt"));
		}

	}

}
