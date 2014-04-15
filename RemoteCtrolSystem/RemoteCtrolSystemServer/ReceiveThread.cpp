#include "StdAfx.h"
#include "ReceiveThread.h"
#include "../SocketIPv4/trace.h"
#include "../Message/MouseMsg.h"

ReceiveThread::ReceiveThread(void)
{
}

ReceiveThread::~ReceiveThread(void)
{
}

void ReceiveThread::Run()
{
	while (true)
	{
		ByteArrayMsg *msg = new ByteArrayMsg();
		m_pConnection->receive(*msg);
		switch(msg->GetType())
		{
		case RCS_MSG_KEYBOARD:
			_trace(L"�յ�������Ϣ");
			break;
		case  RCS_MSG_MOUSE:
			_trace(L"�յ������Ϣ\n");
			SetCursorPos(((MouseMsg*)msg)->GetMouseX(),((MouseMsg*)msg)->GetMouseY());

			break;
		case RCS_MSG_SETUP:
			_trace(L"�յ�������Ϣ");
			break;
		default:
			break;
		}
	}

}

void ReceiveThread::SetSendQueue( std::queue<ByteArrayMsg*> *m_pSendQueue )
{
	this->m_pSendQueue = m_pSendQueue;
}

void ReceiveThread::SetConnection( TCPConnection *_connection )
{
	m_pConnection = _connection;
}
