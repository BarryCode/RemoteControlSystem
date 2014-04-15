/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   TabServerDlg.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:   
**Create date:  2013/05/03   9:20
**Version:
**Description: 
**
**
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**-------------------------------------------------------------------------
**Modified by:
**Modified date:
**Version:
**Description:
**
**************************************************************************/
#ifndef __TABSERVERDLG_H__
#define __TABSERVERDLG_H__

#include "afxcmn.h"
#include "afxwin.h"


// TabServerDlg �Ի���

class TabServerDlg : public CDialog
{
	DECLARE_DYNAMIC(TabServerDlg)

public:
	TabServerDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabServerDlg();

// �Ի�������
	enum { IDD = IDD_TAB_SERVER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd2();
	afx_msg void OnBnClickedBtnAddip();
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void UpdateConfig(void);
	void InitStats(void);
	afx_msg void OnBnClickedCbPwdproted();
	CButton m_cbPwdProtect;
	int m_iConnectPort;
	afx_msg void OnBnClickedBtnChange();
	void UpdateIpList(void);
	afx_msg void OnBnClickedBtnDeleteip();
	afx_msg void OnBnClickedBtnEditip();
	afx_msg void OnBnClickedBtnMoveupip();
	afx_msg void OnBnClickedBtnMovedownip();
	afx_msg void OnBnClickedBtnTestrule();
	CIPAddressCtrl m_testIp;
};
#endif//__TABSERVERDLG_H__