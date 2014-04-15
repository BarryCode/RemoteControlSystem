/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   OperationNotes.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:   
**Create date:  2013/05/03   9:04
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
#ifndef __OPERATIONNOTES_H__
#define __OPERATIONNOTES_H__

#include <vector>

struct Notes{
	CString name;
	CString action;
	CString path;
	CString time;	
};

class OperationNotes
{
public:
	OperationNotes(void);
	~OperationNotes(void);

	std::vector<Notes> GetOperationNotes();

	/**
	 * @Brief GetNotesByName ��ȡĳһ�û������в�����¼
	 * @Parameter CString name  �û��˻���
	 * @Returns std::vector<Notes>
	 * @Remark  
	 **/
	std::vector<Notes> GetNotesByName(CString name);

	//************************************
	// Method:    GetNotesByType
	// Parameter: int type 1:��ʾֻ��ȡӦ�ó���򿪹رյļ�¼��2:��ʾֻ��ȡ�ļ�������¼��0:��ʾȫ����ȡ
	// Returns:   std::vector<Notes>
	//************************************
	std::vector<Notes> GetNotesByType(int type);

	/**
	 * @Brief GetNotesByNameAndType ��ȡ�û���һ�ֲ������͵����м�¼
	 * @Parameter CString name �û���
	 * @Parameter int type �������ͣ�1:��ʾֻ��ȡӦ�ó���򿪹رյļ�¼��2:��ʾֻ��ȡ�ļ�������¼��0:��ʾȫ����ȡ
	 * @Returns std::vector<Notes> ������¼�����
	 * @Remark  
	 **/
	std::vector<Notes> GetNotesByNameAndType(CString name,int type);
	/**
	 * @Brief ClearLogFile ���������¼�ļ������м�¼
	 * @Returns void
	 * @Remark  
	 **/
	void ClearLogFile();

private:
	CStdioFile m_file;
	CString m_strFilePath;
	std::vector<Notes> m_vtNotes;

	void Init();
};
#endif//__OPERATIONNOTES_H__