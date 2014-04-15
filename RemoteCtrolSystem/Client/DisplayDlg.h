#pragma once
#include "afxwin.h"
#include "..\Graphic\ScreenDisplay.h"

// CDisplayDlg �Ի���

class CDisplayDlg : public CDialog
{
	DECLARE_DYNAMIC(CDisplayDlg)

public:
	CDisplayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDisplayDlg();

	HWND GetDisplayHwnd();
	/**
	   @brief:������ʾ��С�����Ͻ�λ�ã����������ı��������Χ
	   @Parameter:int x
	   @Parameter:int y
	   @Parameter:int cx
	   @Parameter:int cy
	   @Return:bool
	*/
	bool SetSize(int x,int y,int cx,int cy);
	/**
	   @brief:������ʾ������ʾ�����С
	   @Parameter:int width
	   @Parameter:int height
	   @Return:bool
	*/
	bool SetScreenSize(int width,int height);
	bool Init(int width,int height);
	/**
	   @brief:ȫ��ģʽ
	   @Return:void
	*/
	void FullScreen();
	/**
	   @brief:����ȫ�������ô���ģʽ
	   @Return:bool
	*/
	bool EndFullScreen();
	/**
	   @brief:���ص�ǰ�Ƿ�Ϊȫ��ģʽ��TRUEΪȫ��ģʽ��falseΪ����ģʽ
	   @Return:bool
	*/
	bool IsFullScreen();
	void SetDisplayer(ScreenDisplay* ScreenDisplayer);
// �Ի�������
	enum { IDD = IDD_DIALOG_DISPLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CStatic m_pctDisplay;
	int		m_left;
	int		m_top;
	int		m_cx;
	int		m_cy;
	int		m_ScreenWidth;
	int		m_ScreenHeight;
	bool	m_IsFullScreen;
	ScreenDisplay*	m_ScreenDisplayer;
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual void OnOK();
};
