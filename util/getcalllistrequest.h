#ifndef __CALL_LIST_REQUEST_H__
#define __CALL_LIST_REQUEST_H__
#include "httprequest.h"
#include <list>

struct  CallInfo{
	char number[32];
	//1：来电已接通 0：来电未接通 -1：去电挂机
	int listen_status;
	//1:主叫 0:被叫
	int call_type;
	//0: 通话未结束  1:通话已结束 
	int call_done;
	//挂机短信下发 1：已发 0：待发 -1：不需要发 -2：非手机号不发
	int call_msg_status;
	//开始时间
	char start[32];
	//结束时间
	char end[32];
};

class GetCalllistRequest:public HttpRequest
{
public:
	int DoRequest();
protected:
	virtual int InitRequest();
	virtual void  ProcessResponse(const char *data,size_t length);
private:
	std::list<CallInfo> call_info_list;
};
#endif