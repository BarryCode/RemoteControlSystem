#include "StdAfx.h"
#include "IniFile.h"

CIniFile::CIniFile(void)
{
	Init();
}

CIniFile::CIniFile( LPCTSTR szFileName )
{
	// (1) ����·���������·���Ƿ����     
	// (2) ��"./"��ͷ������������·���Ƿ����     
	// (3) ��"../"��ͷ�����漰���·���Ľ���
	

	//���·��
	m_szFileName.Format(_T(".//%s"),szFileName);
	Init();
}

 CIniFile::~CIniFile(void)
{
}

void CIniFile::Init()
{

	m_unMaxSection  = 512;
	m_unSetionNameMaxSize = 33; //32λUID��
}

void CIniFile::SetFileName( LPCTSTR szFileName )
{
	m_szFileName.Format(_T(".//%s"),szFileName);
}

BOOL CIniFile::SetProfileInt( LPCTSTR lpszSectionName,LPCTSTR lpszKeyName,int nKeyValue )
{
	CString szKeyValue;
	szKeyValue.Format(_T("%d"),nKeyValue);

	return::WritePrivateProfileString(lpszSectionName,lpszKeyName,szKeyValue,m_szFileName);
}

DWORD CIniFile::GetProfileSectionNames( CStringArray& strArray )
{
	int nAllSectionNameMaxSize = m_unSetionNameMaxSize*m_unMaxSection + 1;
	TCHAR *pszSectionNames = new TCHAR[nAllSectionNameMaxSize];
	DWORD dwCopied = 0;

	dwCopied = ::GetPrivateProfileSectionNames(pszSectionNames,nAllSectionNameMaxSize,m_szFileName);
	
	strArray.RemoveAll();
	TCHAR *pSection = pszSectionNames;
	do 
	{
		CString szSection(pSection);
		if(szSection.GetLength()<1)
		{
			delete[] pszSectionNames;
			return dwCopied;
		}
		strArray.Add(szSection);

		pSection = pSection + szSection.GetLength() + 1;  //next section name
	} while (pSection && pSection<pszSectionNames+ nAllSectionNameMaxSize);

	delete[] pszSectionNames;
	return dwCopied;
}

//ע�⣺��������û���ҵ��򷵻�0
int CIniFile::GetProfileInt( LPCTSTR lpszSectionName,LPCTSTR lpszKeyName )
{
	int nKeyValue = ::GetPrivateProfileInt(lpszSectionName,lpszKeyName,0,m_szFileName);
	return nKeyValue;
}

DWORD CIniFile::GetProfileString( LPCTSTR lpszSectionName,LPCTSTR lpszKeyName ,CString& szKeyValue)
{
	DWORD dwCopied = 0;
	dwCopied = ::GetPrivateProfileString(lpszSectionName,lpszKeyName,_T(""),szKeyValue.GetBuffer(MAX_PATH),MAX_PATH,m_szFileName);
	szKeyValue.ReleaseBuffer();
	return dwCopied;
}

BOOL CIniFile::SetProfileString( LPCTSTR lpszSectionName,LPCTSTR lpszKeyName,LPCTSTR lpszKeyVal )
{
	return ::WritePrivateProfileString(lpszSectionName,lpszKeyName,lpszKeyVal,m_szFileName);
}

BOOL CIniFile::DeleteSection( LPCTSTR lpszSectionName )
{
	return ::WritePrivateProfileSection(lpszSectionName,NULL,m_szFileName);
}

BOOL CIniFile::DeleteKey( LPCTSTR lpszSectionName,LPCTSTR lpszKeyName )
{
	return ::WritePrivateProfileString(lpszSectionName,lpszKeyName,NULL,m_szFileName);
}

LPCTSTR CIniFile::GetFileName()
{
	return m_szFileName;
}


