#ifndef __DB_H__
#define __DB_H__
#include <list>
#include <string>
using std::string;
using std::list;

typedef  void*  DBHANDLE;

typedef struct local_contact_info{
	char name[32];
	//char birth[32];
	char phone[32];
	char company[64];
	char group[32];
	//char number[32];
	char department[32];
	//0: 女  1:男
	int sex;
	//char job[32];
	char city[16];
	char address[256];
}local_contact_info;


DBHANDLE  db_open();

void db_close(DBHANDLE  db);

//添加联系人
int add_contact(DBHANDLE db,local_contact_info * c);
//删除联系人
int delete_contact(DBHANDLE db,const char *phone);

int get_contacts(DBHANDLE db,list<local_contact_info> & contacts);

int add_contact_group(DBHANDLE db,const char *group);

int delete_contact_group(DBHANDLE db,const char *group);

int get_contact_groups(DBHANDLE db,list<string> & groups);

#endif