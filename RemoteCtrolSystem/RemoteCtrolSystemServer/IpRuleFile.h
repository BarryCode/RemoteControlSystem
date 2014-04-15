/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   IpRuleFile.h
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
#ifndef __IPRULEFILE_H__
#define __IPRULEFILE_H__

#include <vector>

//�洢IP����Ľṹ��
struct IpRule 
{
	TCHAR start[16];
	TCHAR end[16];
	int power; //-1��ʾ�ù�����Ч��0��ʾ�ܾ���1��ʾ����
};

class CIpRuleFile
{
public:
	CIpRuleFile(void);
	~CIpRuleFile(void);

public:

	//************************************
	// Method:    Add  ��ӹ���
	// Parameter: IpRule & rule  �������
	// Returns:   BOOL
	//************************************
	BOOL Add(IpRule &rule);

	//************************************
	// Method:    Delete ɾ������
	// Parameter: IpRule & rule Ҫɾ���Ĺ������
	// Returns:   BOOL  ɾ���Ƿ�ɹ���true��ʾ�ɹ�
	//************************************
	BOOL Delete( IpRule &rule);

	//************************************
	// Method:    Update
	// Parameter: IpRule & rule
	// Returns:   BOOL
	//************************************
	BOOL Update( IpRule &rule);

	//************************************
	// Method:    IsRuleExsist
	// Parameter: const IpRule & rule
	// Returns:   BOOL
	//************************************
	BOOL IsRuleExsist(const IpRule &rule);

	/**
	 * @Brief GetAllRules ��ȡ�ļ��е����й���
	 * @Returns std::vector<IpRule>
	 * @Remark  
	 **/
	std::vector<IpRule> GetAllRules();

	/**
	 * @Brief MoveUp �����ƶ�ָ���Ĺ���
	 * @Parameter int index ��������λ�ã���0��ʼ
	 * @Returns BOOL
	 * @Remark  
	 **/
	BOOL MoveUp(int index);

	/**
	 * @Brief moveDown �����ƶ�ָ���Ĺ���
	 * @Parameter int index �������ڵ�λ��
	 * @Returns BOOL
	 * @Remark  
	 **/
	BOOL moveDown(int index);

	/**
	 * @Brief CompareIpAddress  �Ƚ�����ip��ַ�Ĵ�С
	 * @Parameter LPCTSTR address1 ���Ƚϵĵ�ַ1
	 * @Parameter LPCTSTR address2 ���Ƚϵĵ�ַ2
	 * @Returns int ���رȽϽ����-1��ʾС�ڡ�0��ʾ�ȡ�1��ʾ����
	 * @Remark  
	 **/
	int CompareIpAddress(LPCTSTR address1,LPCTSTR address2);

	/**
	 * @Brief GetPowerByIp ��ȡָ��ip��ַ��Ȩ��
	 * @Parameter LPCTSTR address ip��ַ
	 * @Returns int ����Ȩ��
	 * @Remark  
	 **/
	int GetPowerByIp(LPCTSTR address);
private:
	TCHAR* m_pszFilePath;
	CFile m_file;
	std::vector<IpRule> m_DataInFile; //��Ӧ���ļ��е��������顣

	void GetDataFromFile(); //���ļ������������
	void SetDataToFile();  //�����ļ�
	void InitFile();
};
#endif//__IPRULEFILE_H__