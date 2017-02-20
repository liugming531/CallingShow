#ifndef __CARD_PROTOCOL_H__
#define __CARD_PROTOCOL_H__

#define  MIN_SIZE_FRAME_PKT		34
#define  MAX_DATA_SIZE			128 

struct FramePacket{
	char SN[20];//16 bytes
	char passwd[12];//8 bytes
	char owner[4];//2bytes;
	unsigned  char type;
	unsigned  char command;
	unsigned  char cp;
	unsigned  datasize;
	char buffer[MAX_DATA_SIZE];
};

struct NetInfo{
	//char SN[20]; //16 bytes
	//char passwd[6];//4 bytes
	char mac[24];
	char ip[32];
	char mask[32];
	char gate[32];
	unsigned short  tcp_port;
	unsigned short  udp_port;
	unsigned short  serv_port;
	char servaddr[32];
};


#define ERR_SUCCESS	0
#define ERR_NOT_PROTOCOL_DATA  -1
#define ERR_ERROR_CHECKSUM	-2
#define ERR_DATA_TRANSLATE  -3

#define	ERR_UNKOWN	-4

FramePacket  * alloc_packet();

void  free_packet(FramePacket *pkt);

int get_sender_packet(FramePacket *pkt, char *outBuffer,int outSize);

int parse_to_packet(const char *buf,int buf_size,FramePacket *packet);

int parse_to_netinfo(const char *buf,int buf_size,NetInfo *i);

//填充搜索设备包
void fill_to_search_pkt(FramePacket *pkt);

//当前时间转换为bcd码（8421）
void  gettimebcdcode(char *bcdOut,int out_size);

//填充保活信息bao
void  packet_activation_init(FramePacket *out);

//
void packet_callin_init(const char *number,int numlen,char flag,const char *stt,const char *edt,FramePacket *out);
void packet_callout_init(const char *number,int numlen,char flag,const char *stt,const char *edt,FramePacket *out);

#endif