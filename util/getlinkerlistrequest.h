#ifndef  __GET_LINKER_LIST_REQUEST_H__
#define __GET_LINKER_LIST_REQUEST_H__
#include "httprequest.h"
#include <list>
struct Linker{
	char name[64];
	char number[32];
	//0-woman 1:man 
	int sex;
	int groupid;
	char company[256];
	char department[128];
	char post[32];
};


class  GetLinkerListRequest: public HttpRequest
{
public:
	GetLinkerListRequest() :linker_type(0){}
	//type = 0;1;2
	void SetType(int type){linker_type=type;}

	void GetLinkerList(std::list<Linker> &  linkerlist);
	int  DoRequest();

	void test();
protected:
	virtual int  InitRequest();
	virtual void ProcessResponse(const char *data,size_t length);
private:
	int linker_type;
	std::list<Linker>  linkers;
};

#endif