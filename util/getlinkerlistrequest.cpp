#include "getlinkerlistrequest.h"
#include "tinyxml.h"

static const char * xml_request_format =
"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>"
"<request>"
    "<reqHeader>"
        "<token>%s</token>"
        "<appid>netviom</appid>"
    "</reqHeader>"
    "<reqBodyer>"
        "<pageNumber>1</pageNumber>"
        "<pageSize>500</pageSize>"
        "<type>%d</type>"
    "</reqBodyer>"
"</request>";


static const char * response_xml =
"<?xml version = \"1.0\" encoding = \"UTF-8\" standalone = \"yes\" ? >"
"<response>"
"<rspHeader>"
"<status>200</status>"
"<message>success</message>"
"</rspHeader>"
"<rspBodyer>"
"<allPage>16</allPage>"
"<linkerlist>"
"<linker contactsType = \"102\" post = \"master\" department = \"market part\" company = \"huizhou company\" seqid = \"503\" sex = \"1\" name = \"zhuang\" number = \"18665280753\" groupid = \"146\" />"
"<linker contactsType = \"102\" post = \"manager\" department = \"teacher center\" company = \"huizhou company\" seqid = \"504\" sex = \"1\" name = \"luoen\" number = \"18665280321\" groupid = \"146\" />"
"</linkerlist>"
"<allCount>770</allCount>"
"</rspBodyer>"
"</response>";

int GetLinkerListRequest::InitRequest()
{
	if(httpdata)
	{
		char xml_buffer[2048];
		sprintf_s(xml_buffer,2048,xml_request_format,m_str_token.c_str(),linker_type+100);
		evbuffer_add(httpdata,xml_buffer,strlen(xml_buffer));
		return 1;
	}
	return 0;
}

int GetLinkerListRequest::DoRequest()
{
	return SendRequest("http://58.249.48.74:8080/services/imsall/v1/linkerlist.api");
}

void GetLinkerListRequest::test()
{
	ProcessResponse(response_xml, strlen(response_xml));
}

void GetLinkerListRequest::ProcessResponse(const char *data,size_t length)
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

	TiXmlNode *node = body->FirstChild("allPage");
	if(!node) return;
	//node = node->NextSibling();
	//if(!node) return;
	node = body->FirstChild("linkerlist");
	if(!node) return;
	node = node->FirstChild("linker");
	while(node)
	{
		TiXmlAttribute * attribute = node->ToElement()->FirstAttribute();
		Linker  linker;
		memset(&linker,0,sizeof(linker));
		while(attribute)
		{
			const char *att_name = attribute->Name();
			if(strcmp(att_name,"name")==0)
			{
				strcpy(linker.name,attribute->Value());
			}
			else if(strcmp(att_name,"number")==0)
			{
				strcpy(linker.number,attribute->Value());
			}
			else if(strcmp(att_name,"sex")==0)
			{
				linker.sex = attribute->IntValue();
			}
			else if(strcmp(att_name,"groupid")==0)
			{
				linker.groupid = attribute->IntValue();
			}
			else if(strcmp(att_name,"company")==0)
			{
				strcpy(linker.company,attribute->Value());
			}
			else if(strcmp(att_name,"department")==0)
			{
				strcpy(linker.department,attribute->Value());
			}
			else if(strcmp(att_name,"post")==0)
			{
				strcpy(linker.post,attribute->Value());
			}

			attribute = attribute->Next();
		}

		linkers.push_back(linker);

		node = node->NextSibling();
	}
}