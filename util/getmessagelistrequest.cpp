#include "getmessagelistrequest.h"

static char *getmessage_xml = 
"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>"
"<request>"
    "<reqHeader>"
        "<token>WZ87Qkbp5uzQRKIphGOQeWX8NNIxm8bpO04D8XOfCU+Elxt1w7S2kVq/L5EBFjek0EJvvCWCNZQ=</token>"
        "<appid>netviom</appid>"
    "</reqHeader>"
    "<reqBodyer>"
        "<pageNumber>1</pageNumber>"
        "<pageSize>100</pageSize>"
        "<key></key>"
        "<type>1</type>"
    "</reqBodyer>"
"</request>";

int GetMessageListRequest::DoRequest()
{
	return SendRequest("http://58.249.48.74:8080/services/imsall/v1/smsModellist.api");
}

int GetMessageListRequest::InitRequest()
{
	return 1;
}

void GetMessageListRequest::ProcessResponse(const char *data,size_t length)
{

}