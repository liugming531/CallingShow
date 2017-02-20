#include "sendmsgrequest.h"

static char * request_xml =
"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>"
"<request>"
    "<reqHeader>"
        "<token>%s</token>"
        "<appid>netviom</appid>"
    "</reqHeader>"
    "<reqBodyer>"
        "<content>%s</content>"
        "<numberlist>%s</numberlist>"
            //"<number>15602210731</number></numberlist>"
    "</reqBodyer>"
"</request>";


int SendMessageRequest::SendMsgRequest(const char *msg,vector<std::string> numbers)
{
	//return Send
	m_str_msg = msg;
	m_vectNumbers = numbers;
	this->SendRequest("http://58.249.48.74:8080/services/imsall/v1/sendsms.api");
	return 0;
}

int SendMessageRequest::InitRequest()
{
	if(httpdata){
		std::string str_numbers;
		for(int i=0;i<m_vectNumbers.size();i++)
		{
			str_numbers += "<number>";
			str_numbers += m_vectNumbers[i];
			str_numbers += "</number>";
		}

		char xml_buffer[4096];
		int len = sprintf_s(xml_buffer,sizeof(xml_buffer),request_xml,m_str_token,m_str_msg,str_numbers.c_str());
		evbuffer_add(httpdata,xml_buffer,len);
	}
	return 0;
}