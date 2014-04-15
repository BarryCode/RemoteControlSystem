/**************************************************************************
**             Guangzhou ZHIYUAN electronics Co.,LTD
**             
**
**                   http://www.embedtools.com  
**-------------File Info---------------------------------------------------
**File Name:   MouseKeybdEvent.h
**Latest modified Data:
**Latest Version:
**Description:  
**
**-------------------------------------------------------------------------
**Create by:   κط
**Create date:  2013/05/03   8:44
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
#ifndef __MOUSEKEYBDEVENT_H__
#define __MOUSEKEYBDEVENT_H__

#include <Windows.h>

class MouseKeybdEvent
{
public:
	MouseKeybdEvent(void);
	~MouseKeybdEvent(void);

public:
	//ģ����̵�һ�ΰ�����bExtendedָ���Ƿ�ʹ����չ��ʽ
	static void GenerateKey(int vk, BOOL bExtended);

	//ģ�����������
	static void LeftClick(const int x,const int y);

	//ģ������Ҽ����
	static void RightClick(const int x,const int y);

	//ģ��������˫��
	static void LeftDbClick(const int x,const int y);

	//ģ������Ҽ�˫��
	static void RightDbClick(const int x,const int y);

	//ģ������������
	static void LeftClickUp(const int x,const int y);

	//ģ������������
	static void LeftClickDown(const int x,const int y);
	
	//ģ������Ҽ�����
	static void RightClickUp(const int x,const int y);

	//ģ������Ҽ�����
	static void RightClickDown(const int x,const int y);

	//ģ���������ƶ�
	static void MouseWheel(const int mouseData);

	//ģ����̰�������
	static void KeyUp(int vk ,BOOL bExtended);

	//ģ����̰�������
	static void KeyDown(int vk,BOOL bExtended);
};
#endif//__MOUSEKEYBDEVENT_H__