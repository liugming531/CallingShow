#ifndef __SEND_MSG_REQUEST_H__
#define __SEND_MSG_REQUEST_H__

#include "httprequest.h"
#include <vector>

using std::vector;

class SendMessageRequest: public HttpRequest
{
public:
	SendMessageRequest(const char *token):m_str_msg(NULL){ m_str_token = token;}
	int SendMsgRequest(const char * msg,vector<std::string> numbers);
protected:
	virtual int  InitRequest();
	virtual void ProcessResponse(const char *data,size_t length);

private:
	const char * m_str_msg;
	//const char *m_str_token;
	vector<std::string>  m_vectNumbers;
};
#endif