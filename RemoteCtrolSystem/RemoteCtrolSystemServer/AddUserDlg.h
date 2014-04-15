#pragma once
#include "afxwin.h"
#include "userfile.h"


// CAddUserDlg �Ի���

class CAddUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddUserDlg)

public:
	CAddUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddUserDlg();

// �Ի�������
	enum {ADD,EDIT};
	enum { IDD = IDD_ADD_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnOk();
	CEdit m_editName;
	afx_msg void OnBnClickedBtnCancel();

	/**
	 * @Brief SetUserData �����û����ݣ���Ҫ���ڱ༭״̬ʱ���������ݵ�����
	 * @Parameter UserData user  �û�����
	 * @Returns void 
	 * @Remark  
	 **/
	void SetUserData(UserData user);

	/**
	 * @Brief SetStats  ���ý���������״̬
	 * @Parameter int stats ADD��ʾ���״̬��EDIT��ʾ�༭״̬
	 * @Returns void
	 * @Remark  ����������Ӻͱ༭ʹ�õ���ͬһ������
	 **/
	void SetStats(int stats);
private:
	
	UserData m_user;  //�û�����
	int m_stats; //״̬


};
