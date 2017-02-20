#pragma once
#include "uploadmodule.h"
#include "CardProtocol.h"

class CUploadTask :
	public Task
{
public:
	//0 - tcp  1 - udp
	CUploadTask(int protocol=0);
	
	virtual ~CUploadTask(void);

	typedef enum {
		KEEP_ALIVE,
		CALL_IN,
		CALL_OUT
	}TASK_TYPE;

	void AttachPacket(FramePacket  &pkt){ m_pkt = pkt;}

	void SetPacket(const char *sn,const char *passwd,TASK_TYPE type);

	virtual int  DoTask();

	void SetUploadServer(unsigned long uaddr,unsigned short uport)
	{
		m_uaddr=uaddr;
		m_uport=uport;
	}
private:
	unsigned long   m_uaddr;
	unsigned short  m_uport;

	FramePacket   m_pkt;

	int  m_protocol;

	int UploadByTCP(const char *data,int len);

	int UploadByUDP(const char *data,int len);
};
