#include "StdAfx.h"
#include "UploadTask.h"
#include <winsock2.h>

//static char *SERVER_ADDR = "58.249.48.74";
//static unsigned short  SERVER_PORT = 10028;

CUploadTask::CUploadTask(int protocol):m_protocol(protocol)
{

}

CUploadTask::~CUploadTask(void)
{
}


int  CUploadTask::DoTask()
{
	m_count_can_do--;
	int err = 0;
	TRACE("UploadTask Working\n");
	char buf[1024]={0};
	int length = get_sender_packet(&m_pkt,buf,1024);
	if(length > 0)
	{
		TRACE("tosend = %d\n",length);
		if(m_protocol)
			err = UploadByUDP(buf,length);
		else
			err = UploadByTCP(buf,length);

		TRACE("DoTask =%d\n",err);
	}

	/*SOCKET  sock;
	if(m_protocol)
	{
		sock =  socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	}
	else
	{
		sock = socket(AF_INET,SOCK_STREAM,0);
	}*/

	//if(sock == INVALID_SOCKET) return ;

	return err;
}

void CUploadTask::SetPacket(const char *sn, const char *passwd, CUploadTask::TASK_TYPE type)
{
	memcpy(m_pkt.SN,sn,16);

	memcpy(m_pkt.passwd,passwd,8);

}

int CUploadTask::UploadByTCP(const char *data, int len)
{
	TRACE("upload by tcp\n");
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == INVALID_SOCKET)
		return WSAGetLastError();
	
	sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = m_uport;
	servaddr.sin_addr.s_addr = m_uaddr;

	int err = connect(sock,(sockaddr*)&servaddr,sizeof(servaddr));
	if(err == SOCKET_ERROR) 
	{
		closesocket(sock);
		return WSAGetLastError();
	}
	
	int bytesSent = send(sock,data,len,0);

	if(bytesSent != len)
	{
		//char buf[1024];
		//int bytesRecv = recv(sock,buf,1024,0);
		return WSAGetLastError();
		
	}
	shutdown(sock,SD_BOTH);
	closesocket(sock);
	return 0;
}

int CUploadTask::UploadByUDP(const char *data, int len)
{
	TRACE("upload by udp\n");
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sock == INVALID_SOCKET)
		return WSAGetLastError();
	
	sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = m_uport;
	servaddr.sin_addr.s_addr = m_uaddr;
	
	int err = 0;
	int bytesSent = sendto(sock,data,len,0,(sockaddr*)&servaddr,sizeof(servaddr));
	
	if(bytesSent == len)
	{
		fd_set  readset;
		FD_ZERO(&readset);
		FD_SET(sock,&readset);
		timeval   tv ={10,0};
		
		err = select(0,&readset,NULL,NULL,&tv);
		if(err <= 0){
			closesocket(sock);
			return -1;
		}
		
		err = 0;
		char buf[1024];
		int bytesRecv = recvfrom(sock,buf,1024,0,NULL,NULL);

		if(bytesRecv > 0)
		{
			
			TRACE("recv %d bytes\n",bytesRecv);
			FramePacket pkt;
			memset(&pkt,0,sizeof(pkt));
			if(parse_to_packet(buf,bytesRecv,&pkt) != ERR_SUCCESS)
			{
				TRACE("parse errror");
			}
		}
		else
			err = WSAGetLastError();
	}
	else if(bytesSent  == SOCKET_ERROR)
	{
		err =  WSAGetLastError();
	}
	
	closesocket(sock);
	return err;
}