#include "httprequest.h"

static char *xml_content = "<?xml version=\"1.0\" encoding =\"UTF-8\" standalone =\"yes\"?>"
"<request>"
"<reqHeader>"
"<token></token>"
"<appid>netviom</appid>"
"</reqHeader>"
"<reqBodyer>"
"<account>8888</account>"
"<password>6d327b9ad75492a835237bbd4d50a2d7</password>"
"<checkcode>888888</checkcode>"
"<token>token</token>"
"<loginType>1</loginType>"
"</reqBodyer>"
"</request>";


HttpRequest::HttpRequest(void) :conn(NULL), req(NULL), httpdata(NULL), m_http_uri(NULL), m_status(-1)
{
	base = event_base_new();
	memset(m_uri,0,sizeof(m_uri));
}


HttpRequest::~HttpRequest(void)
{
	//if(http)
	//	evhttp_free(http);

	//if(httpdata)
	//	evbuffer_free(httpdata);
	event_base_free(base);
}

int HttpRequest::InitRequest()
{
	//evhttp_add_
	//evhttp_request_get_input_buffer(
	return 1;
}

int HttpRequest::SendRequest(const char *url)
{
	m_http_uri = evhttp_uri_parse(url);
	if(m_http_uri==NULL) return -1;
	//http = evhttp_new(base);
	int port = evhttp_uri_get_port(m_http_uri);
	const char *host = evhttp_uri_get_host(m_http_uri);

	conn = evhttp_connection_base_new(base,NULL,host,(port == -1 ? 80 : port));
	if(conn == NULL) return -1;
	req = evhttp_request_new(http_request_cb,this);
	//evhttp_request_set_error_cb(
	if(req == NULL) return  -1;
	const char *path = evhttp_uri_get_path(m_http_uri);
	if(evhttp_make_request(conn,req,EVHTTP_REQ_POST,path ? path : "/") == -1)
		return  -1;

	evkeyvalq * keyval = evhttp_request_get_output_headers(req);
	evhttp_add_header(keyval,"Content-Type", "Application/xml");
	//evhttp_add_header(keyval,"Host",ip);
	evhttp_add_header(keyval,"User-Agent","PC");
	evhttp_add_header(keyval,"Accept","Application/xml");
	httpdata = evhttp_request_get_output_buffer(req);
	//evbuffer_add(req->output_buffer, xml_content, strlen(xml_content));
	httpdata = evhttp_request_get_output_buffer(req);
	InitRequest();
	evhttp_add_header(keyval, "Host", evhttp_uri_get_host(m_http_uri));

	event_base_dispatch(base);
	evhttp_connection_free(conn);
	//evhttp_request_free(req);
	evhttp_uri_free(m_http_uri);

	return  0;
}

void HttpRequest::http_request_cb(evhttp_request *req,void *arg)
{
	if(!req) return ;
	//int code = req->response_code;
	HttpRequest * httpreq = (HttpRequest*)arg;
	evbuffer *buf = evhttp_request_get_input_buffer(req);

	size_t length = evbuffer_get_length(buf);
	if(length > 1)
	{
		char *data = (char*)malloc(length+1);
		evbuffer_remove(buf,data,length+1);
		data[length] = 0;
		httpreq->ProcessResponse(data,length);
		free(data);
	}
	event_base_loopexit(httpreq->base,NULL);
}
