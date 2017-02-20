#ifndef __GETMESSAGELIST_REQUEST_H_
#define __GETMESSAGELIST_REQUEST_H_

#include "httprequest.h"
#include <list>

class GetMessageListRequest: public HttpRequest
{
public:
	int DoRequest();
protected:
	virtual int  InitRequest();
	virtual void ProcessResponse(const char *data,size_t length);
private:
	std::list<std::string>  msg_list;
};

#endif