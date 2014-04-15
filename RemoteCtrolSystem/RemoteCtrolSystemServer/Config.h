#pragma once
#include "IniFile.h"

class Config
{
public:
	Config(void);
	~Config(void);

	//�Ƿ�����Զ�̿����������
	BOOL GetIsAllowControl();
	void SetIsAllowControl(BOOL isAllowControl);

	//�Ƿ񿪻��Զ������������
	BOOL GetIsAutoRun();
	void SetIsAutoRun(BOOL isAutoRun);

	//��С��������
	BOOL GetIsShowInTask();
	void SetIsShowInTask(BOOL isShowInTask);

	//�����ļ�
	BOOL GetIsEncryptFile();
	void SetIsEncryptFile(BOOL isEncryptFile);

	//���Ӷ˿�
	int GetConnectPort();
	void SetConnectPort(int port);

	//��¼����
	CString GetAdminLoginPwd();
	void SetAdminLoginPwd(CString pwd);

	//�Ƿ�ʹ�����뱣���������˲���
	BOOL GetIsUsePwdProtection();
	void SetIsUsePwdProtection(BOOL isUsePwdProtection);


private:
	CIniFile m_DataFile;
};
