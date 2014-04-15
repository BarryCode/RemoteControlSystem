#pragma once
#include "afxcmn.h"
#include "iprulefile.h"


// CAddEditIpDlg �Ի���

class CAddEditIpDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddEditIpDlg)

public:
	CAddEditIpDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddEditIpDlg();

	enum {ADD,EDIT};
// �Ի�������
	enum { IDD = IDD_ACCESS_IP_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:	
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnOk();

	/**
	 * @Brief SetStats ���ñ����������ڵ�״̬
	 * @Parameter int stats ADD��ʾ�����ӹ����״̬��EDIT���ʾΪ�༭�����״̬
	 * @Returns void
	 * @Remark   ��Ϊ����ӹ�����޸Ĺ����ʱ���õ�����ͬһ������
	 **/
	void SetStats(int stats);

	/**
	 * @Brief SetRule ���ñ�����Ĺ������ݣ����ڴ���Ҫ�༭�Ĺ���
	 * @Parameter IpRule rule  ����Ĺ�������
	 * @Returns void
	 * @Remark  
	 **/
	void SetRule(IpRule rule);

	CIPAddressCtrl m_ipStart;  //������ʼip��ַ�ؼ�����
	CIPAddressCtrl m_ipEnd;  //������ֹip��ַ�ؼ�����
private:
	IpRule m_rule;  //���ڱ�ʾ�����ϵĹ�������
	int m_stats;  //���������ڵ�״̬
};
