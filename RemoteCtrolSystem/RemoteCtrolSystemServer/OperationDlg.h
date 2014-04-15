#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "OperationNotes.h"

// COperationDlg �Ի���

class COperationDlg : public CDialog
{
	DECLARE_DYNAMIC(COperationDlg)

public:
	COperationDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COperationDlg();

// �Ի�������
	enum { IDD = IDD_OPERATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	/**
	 * @Brief SetNameAndType  ����Ҫ��ѯ�ļ�¼���û����ͼ�¼����
	 * @Parameter CString name  �û���
	 * @Parameter int type ��¼����
	 * @Returns void
	 * @Remark  
	 **/
	void SetNameAndType(CString name, int type);

private:
	CString m_strName;
	int m_iType;
	OperationNotes m_operation;

	/**
	 * @Brief UpdateList  ���²ټ�¼�б�
	 * @Returns void
	 * @Remark  
	 **/
	void UpdateList();
public:
	CComboBox m_cbNames;
	CComboBox m_cbTypes;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnClearlog();
	afx_msg void OnCbnSelchangeCbUser();
	afx_msg void OnCbnSelchangeCbType();
	afx_msg void OnBnClickedBtnFlash();
};
