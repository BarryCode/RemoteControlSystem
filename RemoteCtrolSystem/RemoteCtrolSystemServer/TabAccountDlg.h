/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   TabAccountDlg.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:   
**Create date:  2013/05/03   9:19
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
#ifndef __TABACCOUNTDLG_H__
#define __TABACCOUNTDLG_H__

#include "afxcmn.h"


// TabAccountDlg �Ի���

class TabAccountDlg : public CDialog
{
	DECLARE_DYNAMIC(TabAccountDlg)

public:
	TabAccountDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabAccountDlg();

// �Ի�������
	enum { IDD = IDD_TAB_ACCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdduser();
	CListCtrl m_listUsers;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnAdd();
	void UpdateListData(void);
	afx_msg void OnBnClickedBtnEdit();
	afx_msg void OnBnClickedBtnDelete();

};
#endif//__TABACCOUNTDLG_H__