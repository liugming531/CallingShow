#ifndef __CALL_LIST_REQUEST_H__
#define __CALL_LIST_REQUEST_H__
#include "httprequest.h"
#include <list>

struct  CallInfo{
	char number[32];
	//1�������ѽ�ͨ 0������δ��ͨ -1��ȥ��һ�
	int listen_status;
	//1:���� 0:����
	int call_type;
	//0: ͨ��δ����  1:ͨ���ѽ��� 
	int call_done;
	//�һ������·� 1���ѷ� 0������ -1������Ҫ�� -2�����ֻ��Ų���
	int call_msg_status;
	//��ʼʱ��
	char start[32];
	//����ʱ��
	char end[32];
};

class GetCalllistRequest:public HttpRequest
{
public:
	int DoRequest();
protected:
	virtual int InitRequest();
	virtual void  ProcessResponse(const char *data,size_t length);
private:
	std::list<CallInfo> call_info_list;
};
#endif