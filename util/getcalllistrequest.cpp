#include "getcalllistrequest.h"
#include "tinyxml.h"


static const char * request_xml_format =
"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>"
"<request>"
    "<reqHeader>"
        "<token>%s</token>"
        "<appid>netviom</appid>"
    "</reqHeader>"
    "<reqBodyer>"
        "<time>-2015</time>"
    "</reqBodyer>"
"</request>";


int GetCalllistRequest::InitRequest()
{
	if(httpdata){

		return 1;
	}
	return 0;
}

int  GetCalllistRequest::DoRequest()
{
	return SendRequest("http://58.249.48.74:8080/services/imsall/v1/calllist.api");
}

void  GetCalllistRequest::ProcessResponse(const char *data,size_t length)
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
	TiXmlNode *callNode = body->FirstChild("calllist");
	TiXmlElement *call = callNode->FirstChildElement("call");
	while(call)
	{
		TiXmlAttribute * attribute = call->FirstAttribute();
		CallInfo   ci;
		memset(&ci, 0, sizeof(ci));
		while (attribute)
		{
			const char *name = attribute->Name();
			if (strcmp(name, "number") == 0)
			{
				strcpy(ci.number, attribute->Value());
			}
			else if (strcmp(name, "listenStatus") == 0)
			{
				ci.listen_status = attribute->IntValue();
			}
			else if (strcmp(name, "callType") == 0)
			{
				ci.call_type = attribute->IntValue();
			}
			else if (strcmp(name, "callOver") == 0)
			{
				ci.call_done = attribute->IntValue();
			}
			else if (strcmp(name, "callendStatus") == 0)
			{
				ci.call_msg_status = attribute->IntValue();
			}
			else if (strcmp(name, "startTime") == 0)
			{
				strcpy(ci.start, attribute->Value());
			}
			else if (strcmp(name, "endTime") == 0)
			{
				strcpy(ci.end, attribute->Value());
			}
			attribute = attribute->Next();
		}

	}
}