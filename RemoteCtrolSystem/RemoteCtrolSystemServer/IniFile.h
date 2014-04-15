/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   IniFile.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:  κط
**Create date:  2013/04/07   9:47
**Version:  1.0
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
#ifndef __INIFILE_H__
#define __INIFILE_H__

class CIniFile
{
public:
	CIniFile(void);
	CIniFile(LPCTSTR szFileName);
	virtual ~CIniFile(void);

public:
	/**
	 * @Brief SetFileName  ���������ļ����ڵ�·��
	 * @Parameter LPCTSTR szFileName ·��
	 * @Returns void
	 * @Remark  
	 **/
	void SetFileName(LPCTSTR szFileName);
	LPCTSTR GetFileName();

public:

	//************************************
	// Method:    SetProfileInt ������͵�����ֵ
	// Parameter: LPCTSTR lpszSectionName  ����
	// Parameter: LPCTSTR lpszKeyName �ؼ�����
	// Parameter: int nKeyValue  ֵ
	// Returns:   BOOL  �Ƿ�ɹ�
	//************************************
	BOOL SetProfileInt(LPCTSTR lpszSectionName,LPCTSTR lpszKeyName,int nKeyValue);

	//************************************
	// Method:    SetProfileString
	// Parameter: LPCTSTR lpszSectionName
	// Parameter: LPCTSTR lpszKeyName
	// Parameter: LPCTSTR lpszKeyVal
	// Returns:   BOOL
	//************************************
	BOOL SetProfileString(LPCTSTR lpszSectionName,LPCTSTR lpszKeyName,LPCTSTR lpszKeyVal);
	
	/**
	 * @Brief GetProfileSectionNames ��ȡini�����ļ��е����ж���
	 * @Parameter CStringArray & strArray  �������еĶ���
	 * @Returns DWORD
	 * @Remark  
	 **/
	DWORD GetProfileSectionNames(CStringArray& strArray);

	/**
	 * @Brief GetProfileInt  ��ȡ�����ļ��е�һ��int�͵���
	 * @Parameter LPCTSTR lpszSectionName  ָ���Ķ���
	 * @Parameter LPCTSTR lpszKeyName  ָ���Ĺؼ�����
	 * @Returns int  �������͵���������ļ���û�У��򷵻�0
	 * @Remark  
	 **/
	int GetProfileInt(LPCTSTR lpszSectionName,LPCTSTR lpszKeyName);

	/**
	 * @Brief GetProfileString ��ȡ�����ļ��е�һ��string�͵���
	 * @Parameter LPCTSTR lpszSectionName  ָ���Ķ���
	 * @Parameter LPCTSTR lpszKeyName ָ���Ĺؼ�����
	 * @Parameter CString & szKeyValue  ����string����
	 * @Returns DWORD 
	 * @Remark  
	 **/
	DWORD GetProfileString(LPCTSTR lpszSectionName,LPCTSTR lpszKeyName ,CString& szKeyValue);

	/**
	 * @Brief DeleteSection  ɾ��ָ���Ķ�
	 * @Parameter LPCTSTR lpszSectionName  Ҫɾ���Ķ���
	 * @Returns BOOL  �����Ƿ�ɾ���ɹ�
	 * @Remark  
	 **/
	BOOL DeleteSection(LPCTSTR lpszSectionName);

	/**
	 * @Brief DeleteKey ɾ��ָ������
	 * @Parameter LPCTSTR lpszSectionName  ָ���Ķ���
	 * @Parameter LPCTSTR lpszKeyName ָ������ļ�ֵ
	 * @Returns BOOL
	 * @Remark  
	 **/
	BOOL DeleteKey(LPCTSTR lpszSectionName,LPCTSTR lpszKeyName);

private:
	CString m_szFileName;  // .//Config.ini,������ļ������ڣ���exe��һ����ͼWriteʱ���������ļ�
	UINT m_unMaxSection;  //���֧�ֵ�section����256��
	UINT m_unSetionNameMaxSize; //section���Ƴ��ȣ�������Ϊ32��Null-terminated)

	void Init();
};

#endif//__INIFILE_H__