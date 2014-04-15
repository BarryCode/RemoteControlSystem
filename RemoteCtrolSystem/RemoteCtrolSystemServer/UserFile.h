/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   CUserFile.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:    κط
**Create date:  2013/03/27   14:59
**Version:
**Description:  ���ļ��������࣬��Ҫʵ���û��˻�������ɾ���ġ��鼸�����ܣ�Ҫ��
**   �û�����Ψһ�����ļ��Ĳ���ʹ��CFile�����
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
#ifndef __CUserFile_H__
#define __CUserFile_H__

#include <vector>

//������ʾ�û����ݵĽṹ��
struct UserData 
{
	int power;  //-1��ʾ��Ч�û���0��ʾ�ۿ�Ȩ�ޡ�1��ʾ�����û�
	TCHAR name[20];
	TCHAR pwd[20];	
};

class CUserFile
{
public:
	CUserFile(void);
	~CUserFile(void);

	/**
	 * @Brief Add ���һ���û����ݵ��ļ���
	 * @Parameter UserData & user �û�����
	 * @Returns BOOL
	 * @Remark  
	 **/
	BOOL Add(UserData &user);

	/**
	 * @Brief Delete ���ļ���ɾ��һ���û�����
	 * @Parameter UserData & user Ҫɾ�����û�����
	 * @Returns BOOL
	 * @Remark  ��ʵ����ֻ�������û�������������Ч�ġ�
	 **/
	BOOL Delete( UserData &user);

	/**1
	 * @Brief Update �����û�����
	 * @Parameter UserData & user  �û�����
	 * @Returns BOOL
	 * @Remark  �����û������������ݣ�ֻ�ܸ���Ȩ��
	 **/
	BOOL Update( UserData &user);

	/**
	 * @Brief GetUserPower ��ȡ�û�Ȩ��
	 * @Parameter const TCHAR * name  �û���
	 * @Parameter const TCHAR * pwd ����
	 * @Returns int Ȩ��ֵ
	 * @Remark  
	 **/
	int GetUserPower(const TCHAR* name,const TCHAR* pwd);

	/**
	 * @Brief GetAllUsers ��ȡ�����û�����
	 * @Returns std::vector<UserData>  �����û�����
	 * @Remark  
	 **/
	std::vector<UserData> GetAllUsers();

private:
	CString m_pszFilePath;  //�ļ�����·��
	CFile m_file;  //�ļ�����
	std::vector<UserData> m_DataInFile; //��Ӧ���ļ��е���������

private:
	void GetDataFromFile(); //���ļ������������
	void SetDataToFile();  //�����ļ�
	BOOL InitFile(void);  //��ʼ���ļ�
};

#endif//__CUserFile_H__
