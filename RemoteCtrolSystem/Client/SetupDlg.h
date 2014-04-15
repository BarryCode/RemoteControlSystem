#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSetupDlg �Ի���
class CClientMain;

class CSetupDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetupDlg)

public:
	CSetupDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetupDlg();


	/**
	   @brief:����ͼ�����������ص���һ����ʾ�ٷֱȵ�1~100������
	   @Return:int
	*/
	int		GetImageQuality();
	/**
	   @brief:����֡��
	   @Return:int
	*/
	int		GetFrame();
	/**
	   @brief:����֡�ʣ�ͬʱ����֡��ͬ�����ô��ڵĸ����ؼ�
	   @Parameter:int Frame
	   @Return:bool
	*/
	/**
	   @brief:�ж��Ƿ��д��ڴ�
	   @Return:BOOL
	*/
	BOOL	IsExit();
		/**
	   @brief:����ͼ��������ͬʱ����ͼ������ͬ�����ô��ڵĸ����ؼ�
	   @Parameter:int ImageQuality
	   @Return:bool
	*/
	/**
	   @brief:���غ���ֿ���
	   @Return:int
	*/
	int		GetHorzTile();
	/**
	   @brief:��������ֿ���
	   @Return:int
	*/
	int		GetVertTile();
	/**
	   @brief:����ͼ������
	   @Parameter:int ImageQuality
	   @Return:bool
	*/
	bool	SetImageQuality(int ImageQuality);
	/**
	   @brief:����֡��
	   @Parameter:int Frame
	   @Return:bool
	*/
	bool	SetFrame(int Frame);
	/**
	   @brief:���ô�ֱ�ֿ����
	   @Parameter:int nVertTile
	   @Return:bool
	*/
	bool	SetVertTile(int nVertTile);
	/**
	   @brief:����ˮƽ�ֿ����
	   @Parameter:int nHorzTile
	   @Return:bool
	*/
	bool	SetHorzTile(int nHorzTile);
// �Ի�������
	enum { IDD = IDD_DIALOG_SETUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
protected:
	
	VOID		 SetExit(BOOL	IsExist);
private:
	virtual BOOL OnInitDialog();
	/**
	   @brief:ȷ����ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonSetupOk();
	/**
	   @brief:Ӧ�ð�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonSetupApply();
	/**
	   @brief:ȡ����ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonSetupCancel();
	/**
	   @brief:ͼ���������ٰ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonImgSub();
	/**
	   @brief:ͼ���������Ӱ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonImgAdd();
	/**
	   @brief:֡�ʼ��ٰ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonFrameSub();
	/**
	   @brief:֡�����Ӱ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonFrameAdd();
	/**
	   @brief:��ֱ�ֿ�������ٰ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedVertTileDown();
	/**
	   @brief:��ֱ�ֿ�������Ӱ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonVertTileUp();
	/**
	   @brief:ˮƽ�ֿ�������ٰ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonHorzTileDown();
	/**
	   @brief:ˮƽ�ֿ�������Ӱ�ť
	   @Return:void
	*/
	afx_msg void OnBnClickedButtonHorzTileUp();
	/**
	   @brief:֡�ʵ���������
	   @Parameter:NMHDR * pNMHDR
	   @Parameter:LRESULT * pResult
	   @Return:void
	*/
	afx_msg void OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	/**
	   @brief:ͼ����������������
	   @Parameter:NMHDR * pNMHDR
	   @Parameter:LRESULT * pResult
	   @Return:void
	*/
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);

	/**
	   @brief:ͼ�����������༭��
	   @Return:void
	*/
	afx_msg void OnEnChangeEditImageQuality();
	/**
	   @brief:֡�ʵ����༭��
	   @Return:void
	*/
	afx_msg void OnEnChangeEditFrame();
	/**
	   @brief:��ֱ�ֿ������
	   @Parameter:NMHDR * pNMHDR
	   @Parameter:LRESULT * pResult
	   @Return:void
	*/
	afx_msg void OnNMReleasedcaptureSliderVertTile(NMHDR *pNMHDR, LRESULT *pResult);
	/**
	   @brief:ˮƽ�ֿ������
	   @Parameter:NMHDR * pNMHDR
	   @Parameter:LRESULT * pResult
	   @Return:void
	*/
	afx_msg void OnNMReleasedcaptureSliderHorzTile(NMHDR *pNMHDR, LRESULT *pResult);
	/**
	   @brief:��ֱ�ֿ�༭��
	   @Return:void
	*/
	afx_msg void OnEnChangeEditVertTile();
	/**
	   @brief:ˮƽ�ֿ�༭��
	   @Return:void
	*/
	afx_msg void OnEnChangeEditHoczTile();
	afx_msg void OnStnClickedStaticFrame();
	afx_msg int	 OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();	
	afx_msg void OnStnClickedStaticImageQuality();
	
	BOOL		m_bIsExist;
	int			m_nImageQuality;
	int			m_nFrame;
	int			m_nVertTile;
	int			m_nHorzTile;
	CSliderCtrl m_sldImageQuality;
	CSliderCtrl m_sldFrame;
	CSliderCtrl m_sldVertTile;
	CSliderCtrl m_sldHorzTile;
	CEdit m_tbImageQuality;
	CEdit m_tbFrame;
	CEdit m_tbVertTile;
	CEdit m_tbHorzTile;
};
