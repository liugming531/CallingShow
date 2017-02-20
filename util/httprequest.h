#ifndef __HTTPREQUEST_H__
#define __HTTPREQUEST_H__ 
//#include "event2\event.h"
//#include "event2\http.h"
//#include "event2\buffer.h"
//#include "event2\bufferevent.h"

#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/http.h>
#include <event2/http_struct.h>
#include <event2/keyvalq_struct.h>
#include <string>

#define HTTP_OK 200
//#define HTTP_BAD_REQUEST 400


class HttpRequest
{
public:
	HttpRequest(void);
	virtual ~HttpRequest(void);

	void SetURI(const char *uri){ strcpy_s(m_uri,sizeof(m_uri),uri);}
	int SendRequest(const char *url);

	std::string GetToken(){ return m_str_token;}
	void SetToken(std::string token){
		m_str_token = token;
	}
	int  GetStatus(){ return m_status;}
	std::string GetErrorMessage(){ return m_str_msg;}
protected:
	virtual int  InitRequest();
	virtual void ProcessResponse(const char *data,size_t length) = 0;
private:
	event_base * base;
	//evhttp  *http;
	evhttp_connection *conn;
	evhttp_request * req;

	static void  http_request_cb(evhttp_request *req,void *arg);
protected:
	evbuffer * httpdata;
	char m_uri[256];
	evhttp_uri*  m_http_uri;

	std::string m_str_token;
	int m_status;
	std::string m_str_msg;
};

#endif