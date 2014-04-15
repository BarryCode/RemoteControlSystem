#include "StdAfx.h"
#include "DealConnection.h"
#include "IpRuleFile.h"
#include "SendImageThread.h"
#include "MouseKeybdEvent.h"
#include "TabConnectionDlg.h"
#include "UserFile.h"
#include "WndClassList.h"

#include "../Message/SetupMsg.h"
#include "../Message/ByteArrayMsg.h"
#include "../Message/UserMsg.h"
#include "../Message/KeyboardMsg.h"
#include "../Message/MouseMsg.h"

#include <queue>
#include <atlconv.h>


DealConnection::~DealConnection(void)
{
}

void DealConnection::Run()
{
	USES_CONVERSION;
	//TODO::������е����ͻ������ӵ���Ϣ����

	//��ȡ���ӵĿͻ���ip��ַ����Ϣ
	TCPSocketAddress clientAddress =  this->connection.getConnectedAddress();
	string address = clientAddress.GetIPString(0);
	CString strAddress(address.c_str());
	CIpRuleFile rule;
	
	//���ضԿͻ���ip��ַ��֤�Ľ��
	if (rule.GetPowerByIp(strAddress) == 0)
	{
		SetupMsg* ipPower = new SetupMsg();
		//����0��ʾ��ֹ����
		ipPower->PacketMsg(RCS_SETUP_MSG_PERMISSION,RCS_PERMISSION_IP,0);
		connection.send(*ipPower);
		delete ipPower;
		return ;
	}
	else
	{
		SetupMsg* ipPower = new SetupMsg;
		//����1��ʾ��������
		ipPower->PacketMsg(RCS_SETUP_MSG_PERMISSION,RCS_PERMISSION_IP,1);
		//_trace(L"send ip correct\n");
		connection.send(*ipPower);
		delete ipPower;
	}

	//���տͻ��˵��û��˺���Ϣ
	ConnectionData data;
	ByteArrayMsg *receive = new ByteArrayMsg();
	connection.receive(*receive);
	char username[20],userpwd [20];
	if(receive->GetType() ==RCS_MSG_USER )
	{
	//}
	//switch(receive->GetType())
	//{
	//case RCS_MSG_USER:
		((UserMsg*)receive)->GetUsername(username);
		((UserMsg*)receive)->GetPassword(userpwd);
		CUserFile userfile;
		SetupMsg* acount = new SetupMsg();
		int power;
		if (WndClassList::m_connectDlg->IsUserLogined(A2T(username)))
		{
			//����2��ʾ�û��Ѿ���¼
			acount->PacketMsg(RCS_SETUP_MSG_PERMISSION,RCS_PERMISSION_CONTROL,2);
			connection.send(*acount);
			return ;
		}		
		if ( (power =userfile.GetUserPower(A2T(username),A2T(userpwd)))== -1)
		{
			//-1��ʾ�û����������
			acount->PacketMsg(RCS_SETUP_MSG_PERMISSION,RCS_PERMISSION_CONTROL,-1);
			connection.send(*acount);
			return ;
		}
		else
		{
			//������˺�Ȩ�޷��͹�ȥ
			acount->PacketMsg(RCS_SETUP_MSG_PERMISSION,RCS_PERMISSION_CONTROL,power);
			//_trace(L"send account infomation\n");
			connection.send(*acount);
			data.status = power;
			//���м��Ȩ�ޣ�����������¼
			if (power == 1)
			{
				//WndClassList::m_watcher = new SystemMonitor;
				WndClassList::m_watcher->SetName(username);
				WndClassList::m_watcher->SetIp(address.c_str());
				WndClassList::m_watcher->SetFilePath("monitor.log");
				WndClassList::m_watcher->Start();
			}
		}
		
	}
	else
	{
		//_trace(L"δ�����û���֤\n");
		return ;
	}

	//���·�������ӹ������ı��
	data.username = username;
	data.ip = strAddress;
	data.connection = &connection;
	WndClassList::m_connectDlg->AddConnection(data);
	WndClassList::m_connectDlg->UpdateList();

	//������Ļ�ֱ��ʴ�С���ͻ���
	SetupMsg* systemMetrics = new SetupMsg;
	systemMetrics->PacketMsg(RCS_SETUP_MSG_PIXEL,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
	connection.send(*systemMetrics);
	delete systemMetrics;

	//������Ļ���߳�
	SendImageThread sendThread;
	sendThread.SetConnection(&connection);
	sendThread.Start();

	//ѭ�����տͻ��˵����������ꡢ���̡��ı�֡�ʡ��������ֿ����Ϣ
	char *receiveData = new char[4096];
	ByteArrayMsg *msg = new ByteArrayMsg;
	while (connection.IsConnected())
	{
		/*std::queue<ByteArrayMsg*> msgs;
		int bytes = connection.receive(msgs);
		while (!msgs.empty())
		{
			ByteArrayMsg *msg = msgs.front();*/
		int bytes = connection.receive(receiveData,4096);
		if (bytes <=0)  //��������Ϊ0����ʾ���ӳ�������Ѿ��Ͽ�
		{
			connection.disconnect();
			WndClassList::m_connectDlg->DeleteItemByConnection(&connection);
			WndClassList::m_watcher->Stop();
			break;
		}
		int iter = 0;
		while (iter<bytes)
		{
			msg->SetBuffer(receiveData+iter);
			iter+=ByteArrayMsg::GetSize(receiveData+iter,bytes-iter);
			switch(msg->GetType())
			{
			case RCS_MSG_KEYBOARD:  //������Ϣ
				{
					//_trace(L"�յ�������Ϣ\n");
					int stats = ((KeyboardMsg*)msg)->GetKeyStatus();
					int vk = ((KeyboardMsg*)msg)->GetKey();
					if (vk == RCS_KEY_TASKMGR)
					{
						WinExec("taskmgr.exe",SW_SHOW);
						break;
					}
					if (RCS_KEY_DOWN == stats)
					{
						MouseKeybdEvent::KeyDown(vk,FALSE);
					}
					else 
					{
						MouseKeybdEvent::KeyUp(vk,FALSE);
					}
				}
				break;
			case  RCS_MSG_MOUSE:  //�����Ϣ
				{		
					//_trace(L"�յ������Ϣ");
					int xPos =((MouseMsg*)msg)->GetMouseX();
					int yPos = ((MouseMsg*)msg)->GetMouseY();
					//SetCursorPos(xPos,yPos);
					//_trace(L"Position:%d , %d",xPos,yPos);
					int status = ((MouseMsg*)msg)->GetMouseStatus();
					switch(status)
					{
					case RCS_MOUSE_LEFT_DOWN:
						{
							//_trace(L"--->�������\n");
							MouseKeybdEvent::LeftClickDown(xPos,yPos);
							///mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_ABSOLUTE,xPos,yPos,0,0);
						}
						break;
					case  RCS_MOUSE_LEFT_UP:
						{
							//_trace(L"--->�������\n");
							MouseKeybdEvent::LeftClickUp(xPos,yPos);
						}
						break;
					case RCS_MOUSE_RIGHT_DOWN:
						{
							//_trace(L"--->�Ҽ�����\n");
							MouseKeybdEvent::RightClickDown(xPos,yPos);
							
						}
						break;
					case  RCS_MOUSE_RIGHT_UP:
						{
							//_trace(L"--->�Ҽ�����\n");
							MouseKeybdEvent::RightClickUp(xPos,yPos);
						}
						break;
					case RCS_MOUSE_RIGHT_DBLCLK:
						{
							//_trace(L"--->�Ҽ�˫��\n");
							MouseKeybdEvent::RightDbClick(xPos,yPos);
						}
						break;
					case  RCS_MOUSE_LEFT_DBLCLK:
						{
							//_trace(L"--->���˫��\n");
							MouseKeybdEvent::LeftDbClick(xPos,yPos);
						}
						break;
					case  RCS_MOUSE_MINDLE_DOWN:
						{
							//_trace(L"--->���ְ���\n");
						}
						break;
					case  RCS_MOUSE_MINDLE_UP:
						{
							//_trace(L"--->���ֵ���\n");
						}
						break;
					case RCS_MOUSE_MINDLE_DBLCLK:
						{
							//_trace(L"--->����˫��\n");
						}
						break;
					case 0:
						{
							//_trace(L"--->����ƶ�\n");
							SetCursorPos(xPos,yPos);
						}
					case RCS_MOUSE_WHEEL:
						{
							//_trace(L"--->������\n");
							int wheels = ((MouseMsg*)msg)->GetMouseStatus();
							//MouseKeybdEvent::MouseWheel(wheels);
						}
					default:
						break;
					}
				}
				break;
			case RCS_MSG_SETUP: //������Ϣ
				{			
					//_trace(L"�յ�������Ϣ");
					int type = ((SetupMsg*)msg)->GetStatusType();
					switch(type)
					{
					case RCS_SETUP_MSG_IMAGE_QUALITY:
						{						
							//_trace(L"--->ͼ������\n");
							int quality = ((SetupMsg*)msg)->GetValue1();
							sendThread.SetImageQuality(quality);
						}
						break;
					case RCS_SETUP_MSG_TILE:
						{						
							//_trace(L"--->�ֿ���Ϣ\n");
							int xbox = ((SetupMsg*)msg)->GetValue1();
							int ybox = ((SetupMsg*)msg)->GetValue2();
							sendThread.SetTileNumber(xbox,ybox);
						}
						break;
					case RCS_SETUP_MSG_FRAME:
						{
							//_trace(L"--->֡��\n");
							int frame = ((SetupMsg*)msg)->GetValue1();
							sendThread.SetFrame(frame);
						}
						
						break;
					}
				}
				break;
			case RCS_MSG_USER:
				//_trace(L"�յ��û���Ϣ\n");
				break;
			default:
				break;
			}		
		}		
		
	}
	sendThread.WaitForEnd();
	Sleep(2000);
	//_trace(L"DealConnectionThread is end\n");
}