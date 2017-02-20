#include "loginrequest.h"
#include "md5.h"
#include "tinyxml.h"


static char *xml_content = "<?xml version=\"1.0\" encoding =\"UTF-8\" standalone =\"yes\"?>"
"<request>"
"<reqHeader>"
"<token></token>"
"<appid>netviom</appid>"
"</reqHeader>"
"<reqBodyer>"
"<account>%s</account>"
"<password>%s</password>"
"<checkcode>888888</checkcode>"
"<token>token</token>"
"<loginType>1</loginType>"
"</reqBodyer>"
"</request>";


const char * test_xml = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>"
"<response>"
    "<rspHeader>"
        "<status>200</status>"
        "<message>aa</message>"
    "</rspHeader>"
    "<rspBodyer>"
        "<token>WZ87Qkbp5uzQRKIphGOQeWX8NNIxm8bpO04D8XOfCU+Elxt1w7S2kVq/L5EBFjek0EJvvCWCNZQ=</token>"
        "<limit>10080</limit>"
        "<sessionid>079c9ad0-1416-46c6-af2d-d09d33411834</sessionid>"
    "</rspBodyer>"
"</response>";

LoginRequest::LoginRequest()
{
	memset(m_account,0,sizeof(m_account));
	memset(m_password,0,sizeof(m_password));
}

LoginRequest::LoginRequest(const char *account,const char *password)
{
	memset(m_account,0,sizeof(m_account));
	memset(m_password,0,sizeof(m_password));
	SetAccount(account);
	SetPassword(password);
}

void LoginRequest::SetAccount(const char *account)
{
	if(account)
		strcpy_s(m_account,32,account);
	else
		memset(m_account,0,sizeof(m_account));
}

void LoginRequest::SetPassword(const char *password)
{
	if(password)
		strcpy_s(m_password,32,password);
	else
		memset(m_password,0,sizeof(m_password));
}

int LoginRequest::DoLogin()
{
	return SendRequest("http://58.249.48.74:8080/services/imsall/v1/login.api");
}

int LoginRequest::InitRequest()
{
	if(m_account[0] ==0 || m_password[0]==0)
		return 0;
	std::string  md5str = MD5(m_password).hexdigest();
	if(httpdata)
	{
		/*evbuffer_add_printf(httpdata,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>");
		evbuffer_add_printf(httpdata,"<request><reqHeader><token></token><appid>netviom</appid></reqHeader>");
		evbuffer_add_printf(httpdata,"<reqBodyer><account>%s</account>",m_account);
		evbuffer_add_printf(httpdata,"<password>%s</password>",md5str.c_str());
		evbuffer_add_printf(httpdata,"<checkcode></checkcode><token></token>");
		evbuffer_add_printf(httpdata,"<loginType>1</loginType></reqBodyer></request>");*/

		char xml_buffer[2048];
		sprintf_s(xml_buffer,2048,xml_content,m_account,md5str.c_str());
		evbuffer_add(httpdata,xml_buffer,strlen(xml_buffer));
		return 1;
	}
	return 0;
}

void LoginRequest::ProcessResponse(const char *data,size_t length)
{
	TiXmlDocument doc;
	doc.Parse(data);
	if(doc.Error()){
		m_status = -1;
		m_str_msg="parse response xml error";
		return;
	}
	TiXmlNode * root = doc.FirstChild("response");
	TiXmlElement  *header = root->FirstChildElement("rspHeader");
	if(!header) 
		return ;
	TiXmlElement * e_status = header->FirstChildElement("status");
	if(e_status)
		m_status = atoi(e_status->GetText());
	TiXmlElement *e_msg = e_status->NextSiblingElement();
	if(e_msg)
		m_str_msg = e_msg->GetText();
	
	TiXmlNode *body = header->NextSibling();
	if(!body) return;
	TiXmlElement *e_token = body->FirstChildElement("token");
	if(e_token)
		m_str_token = e_token->GetText();
	if(e_token->NextSibling())
	{
		TiXmlElement * e_sessionid = e_token->NextSibling()->NextSiblingElement();
		m_sessionid = e_sessionid->GetText();
	}
	//elment->GetText();
}

void LoginRequest::parseXml()
{
	TiXmlDocument doc;
	doc.Parse(test_xml);
	if(doc.Error()){
		const char * v = doc.Value();
		const char * e = doc.ErrorDesc();
	}
		//return ;
	TiXmlNode * elment = doc.FirstChild("response");
	if(!elment)
		return ;
	TiXmlElement  *e1 = elment->FirstChildElement("rspHeader");
	if(!e1) 
		return ;
	TiXmlElement * e11 = e1->FirstChildElement("status");
	if(e11)
		m_status = atoi(e11->GetText());
	TiXmlElement *e12 = e11->NextSiblingElement();
	if(e12)
		m_str_msg = e12->GetText();

	TiXmlNode * e2 = e1->NextSibling();
	if(!e2)
		return;
	TiXmlElement *e21 = e2->FirstChildElement("token");
	if(e21)
		m_str_token = e21->GetText();
}