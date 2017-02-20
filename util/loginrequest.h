#ifndef __LOGIN_REQUEST_H__
#define __LOGIN_REQUEST_H__

#include "httprequest.h"

class LoginRequest:public HttpRequest
{
public:
	LoginRequest();
	LoginRequest(const char *account,const char *password);
	~LoginRequest(){}

	void  SetAccount(const char *account);
	void  SetPassword(const char *password);

	void parseXml();
	//std::string GetToken();
	std::string GetSessionID();

	int DoLogin();
protected:
	virtual int InitRequest();
	virtual void  ProcessResponse(const char *data,size_t length);
private:
	char m_account[32];
	char m_password[32];
	std::string m_sessionid;
	//std::string m_token;
};

#endif