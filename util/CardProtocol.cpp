#include "stdafx.h"
#include "cardprotocol.h"
#include <winsock2.h>

//static  unsigned short sflag = 0;

static char  getchecksum(const char *data,int len)
{
	WORD  sum = 0;
	int i=0;
	while(i<len)
	{
		sum += data[i];
		i++;
	}
	return  LOBYTE(sum);
	
}

int get_sender_packet(FramePacket *pkt, char *outBuffer,int outSize)
{
	char buf[1024];
	memset(buf,0,1024);
	//开始标识符
	//buf[0] = 0x7E;
	char *p = buf;
	//SN
	memcpy(p,pkt->SN,16);
	p += 16;
	//code-16
	const char *t = pkt->passwd;
	for(int i=0;i<16;i++)
	{
		*p++ = pkt->SN[i]^(*t);
		if(*t != '\0')
			t++;
		else
			t = pkt->passwd;
	}
	//memcpy(p,pkt->passwd,4);
	//p += 4;
	//软件命令标识
	memcpy(p,pkt->owner,2);
	p += 2;
	//控制码
	*p++ = pkt->type;
	*p++ = pkt->command;
	//*p++ = pkt->cp;
	//数据码
	//*(int*)p = htonl(pkt->datasize);
	*p++ = (char)(pkt->datasize&0xFF);
	//p += 4;
	if(pkt->datasize > 0)
	{
		memcpy(p,pkt->buffer,pkt->datasize);
		p += pkt->datasize;
	}
	//checksum
	*p++ = getchecksum(buf,p-buf);
	//结束标识符
	//*p = 0x7E;
	char *keep = outBuffer;
	*outBuffer++ = 0x7E;
	for(char* pos = buf;pos!= p;pos++)
	{
		if(*pos ==0x7E)
		{
			*outBuffer++ = 0x7F;
			*outBuffer++ = 0x01;
		}
		else if(*pos==0x7F)
		{
			*outBuffer++ = 0x7F;
			*outBuffer++ = 0x02;
		}
		else
			*outBuffer++ = *pos;
	}
	*outBuffer = 0x7E;
	return  (outBuffer-keep+1);
}


int parse_to_packet(const char *buf,int buf_size,FramePacket *packet)
{
	int ret = ERR_SUCCESS;
	char *data =  (char*)malloc(buf_size);
	memset(data,0,buf_size);
	do {
		if(buf_size < MIN_SIZE_FRAME_PKT)
		{
			ret =  ERR_NOT_PROTOCOL_DATA;
			break;
		}

		if(buf[0] != 0x7E || buf[buf_size-1] != 0x7E)
		{
			ret = ERR_NOT_PROTOCOL_DATA;
			break;
		}
		
		int len = 0,i=1;
		for( ;i<buf_size-1;i++)
		{
			if(buf[i] == 0x7E)
				break;
			if(buf[i] == 0x7F)
			{
				if(buf[i+1] == 0x01)
				{
					data[len++] = 0x7E;
					i++;
				}
				else if(buf[i+1] == 0x02)
				{
					data[len++] = 0x7F;
					i++;
				}
				else
					break;
			}
			else
				data[len++] = buf[i];

		}

		if(i<buf_size-1)
		{
			ret = ERR_DATA_TRANSLATE;
			break;
		}

		if(data[len-1] != getchecksum(data,len-1))
		{
			ret =  ERR_ERROR_CHECKSUM;
			break;
		}
		
		const char *p = data;//buf+1;
		//reciver code
		//SN
		memcpy(packet->SN,p,16);
		p += 16;
		//check password
		//memcpy(packet->passwd,p,16);
		p += 16;
		//flag 
		memcpy(packet->owner,p,2);
		p += 2;
		//control code 
		packet->type = *p++;
		packet->command = *p++;
		//packet->cp = *p++;
		
		//data information
		packet->datasize = *p++;

		ASSERT(packet->datasize<MAX_DATA_SIZE);
		memcpy(packet->buffer,p,packet->datasize);

	}while(false);
	
	free(data);
	data = NULL;
	return ret;
}

int parse_to_netinfo(const char *buf,int buf_size,NetInfo *i)
{
	if(buf_size != 0x89)
		return ERR_NOT_PROTOCOL_DATA;
	const unsigned char *p = (unsigned char*)buf;

	memcpy(i->mac,p,6);
	p += 6;
	//ip 
	sprintf_s(i->ip,32,"%d.%d.%d.%d",*p,*(p+1),*(p+2),*(p+3));
	p += 4;
	//mask
	sprintf_s(i->mask,32,"%d.%d.%d.%d",*p,*(p+1),*(p+2),*(p+3));
	p += 4;
	//gate
	sprintf_s(i->gate,32,"%d.%d.%d.%d",*p,*(p+1),*(p+2),*(p+3));
	p += 4;
	//unkown 
	p += 9;
	//tcp port
	i->tcp_port = ntohs(*(unsigned short*)p);
	p += 2;
	//udp port;
	i->udp_port = ntohs(*(unsigned short*)p);
	p += 2;
	//server port
	i->serv_port = ntohs(*(unsigned short*)p);
	p += 2;
	//server ip
	sprintf_s(i->servaddr,32,"%d.%d.%d.%d",*p,*(p+1),*(p+2),*(p+3));

	return ERR_SUCCESS;
}

void fill_to_search_pkt(FramePacket *pkt)
{
	memset(pkt->SN,' ',16);
	memset(pkt->passwd,0xFF,4);
	//
	memset(pkt->owner,0,4);
	//
	pkt->type = 0x01;
	pkt->command = 0xFE;
	pkt->cp = 0;

	pkt->datasize = 2;

	memset(pkt->buffer,0xFF,2);
}

void gettimebcdcode(char *bcdOut,int out_size)
{
	SYSTEMTIME  now;
	GetLocalTime(&now);

	unsigned char t = now.wSecond%100;
	*bcdOut++ = ((t/10)<<4 | (t%10)&0x0F );

	t = now.wMinute % 100;
	*bcdOut++ = ((t/10)<<4 | (t%10)&0x0F );

	t = now.wHour % 100;
	*bcdOut++ = ((t/10)<<4 | (t%10)&0x0F );

	t = now.wDay % 100;
	*bcdOut++ = ((t/10)<<4 | (t%10)&0x0F );

	t = now.wMonth % 100;
	*bcdOut++ = ((t/10)<<4 | (t%10)&0x0F );

	t = now.wYear % 100;
	*bcdOut = ((t/10)<<4 | (t%10)&0x0F );

}

void  packet_activation_init(FramePacket *out)
{
	out->type = 0x19;
	out->command = 0x33;
	out->datasize = 6;
	
	gettimebcdcode(out->buffer,120);
}

void packet_callin_init(const char *number,int numlen,char flag,const char *stt,const char *edt,FramePacket *out)
{
	out->type = 0x19;
	out->command = 0x32;
	out->datasize = 0x2B;
	memset(out->buffer,' ',30);
	memcpy(out->buffer,number,numlen);

	out->buffer[30] = flag;

	//gettimebcdcode(&out->buffer[31],64);
	memcpy(&out->buffer[31],stt,6);
	memcpy(&out->buffer[37],edt,6);

	//memset(&out->buffer[37],0,7);

}

void packet_callout_init(const char *number,int numlen,char flag,const char *stt,const char *edt,FramePacket *out)
{
	out->type = 0x19;
	out->command = 0x31;
	out->datasize = 0x2B;
	memset(out->buffer,' ',30);
	memcpy(out->buffer,number,numlen);

	out->buffer[30] = flag;

	//gettimebcdcode(&out->buffer[31],64);

	//memset(&out->buffer[37],0,7);
	memcpy(&out->buffer[31],stt,6);
	memcpy(&out->buffer[37],edt,6);
}