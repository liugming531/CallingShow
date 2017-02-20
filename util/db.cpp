#include "db.h"
#include "sqlite3\sqlite3.h"

#ifndef NULL
#define NULL 0
#endif

static int init_table(sqlite3 *db);

DBHANDLE db_open()
{
	sqlite3 * db = NULL;
	int ret = sqlite3_open(".\\cs.db",&db);

	if(ret) 
		return  NULL;

	return db;
}

void db_close(DBHANDLE  db)
{
	if(db)
	{
		sqlite3_close((sqlite3*)db);
	}
}

int init_table(sqlite3 *db)
{
	//char *sql = "create table(
	return 1;
}

int add_contact(DBHANDLE db,local_contact_info * c)
{
	//char sql[512];
	//sprintf_s(sql,sizeof(sql),"insert into contact(name,phone,sex,birth,company,city,address) values(\
	//					  '%s','%s','%s','%s','%s','%s','%s')",c->name,c->phone,c->sex,c->birth,c->company,c->city,c->address);

	char sql[] = "insert into Contact(Name,Phone,Sex,GroupName,City,Company,Department) values(?,?,?,?,?,?,?)";
	sqlite3_stmt *pStmt;
	const char *tail = NULL;
	if (SQLITE_OK != sqlite3_prepare_v2((sqlite3*)db, sql, -1, &pStmt, &tail))
		return -1;
	sqlite3_bind_text(pStmt, 1, c->name, strlen(c->name),NULL);
	sqlite3_bind_text(pStmt, 2, c->phone, strlen(c->phone), NULL);
	sqlite3_bind_int(pStmt, 3, c->sex);
	sqlite3_bind_text(pStmt, 4, c->group, strlen(c->group), NULL);
	if (c->city[0] != 0)
		sqlite3_bind_text(pStmt, 5, c->city, strlen(c->city), NULL);
	else
		sqlite3_bind_null(pStmt, 5);
	if (c->company[0]!=0)
		sqlite3_bind_text(pStmt, 6, c->company, strlen(c->company), NULL);
	else
		sqlite3_bind_null(pStmt, 6);
	if (c->department[0] != 0)
		sqlite3_bind_text(pStmt, 7, c->department, strlen(c->department), NULL);
	else
		sqlite3_bind_null(pStmt, 7);

	int r = sqlite3_step(pStmt);
	//const char * errmsg = sqlite3_errmsg((sqlite3*)db);
	sqlite3_finalize(pStmt);
	return (r==SQLITE_DONE?SQLITE_OK:r);
}

int delete_contact(DBHANDLE db,const char *phone)
{
	return 0;
}

int get_contacts(DBHANDLE db,list<local_contact_info> & contacts)
{
	char sql[] = "select Name,Phone,Sex,City,Company,Department,Adress,GroupName from Contact";
	sqlite3_stmt *pStmt;
	const char *pTail = NULL;
	int ret = sqlite3_prepare_v2((sqlite3*)db, sql, strlen(sql), &pStmt, &pTail);
	if (ret != SQLITE_OK) return -1;
	do{
		ret = sqlite3_step(pStmt);
		if (ret == SQLITE_ROW)
		{
			local_contact_info    info;
			memset(&info, 0, sizeof(info));

			memcpy(info.name, sqlite3_column_text(pStmt, 0), sqlite3_column_bytes(pStmt, 0));
			memcpy(info.phone, sqlite3_column_text(pStmt, 1), sqlite3_column_bytes(pStmt, 1));
			info.sex = sqlite3_column_int(pStmt, 2);
			memcpy(info.city, sqlite3_column_text(pStmt, 3), sqlite3_column_bytes(pStmt, 3));
			memcpy(info.company, sqlite3_column_text(pStmt, 4), sqlite3_column_bytes(pStmt, 4));
			memcpy(info.department, sqlite3_column_text(pStmt, 5), sqlite3_column_bytes(pStmt, 5));
			memcpy(info.address, sqlite3_column_text(pStmt, 6), sqlite3_column_bytes(pStmt, 6));
			memcpy(info.group, sqlite3_column_text(pStmt, 7), sqlite3_column_bytes(pStmt, 7));

			contacts.push_back(info);
		}
		else
			break;
	} while (1);
	sqlite3_finalize(pStmt);
	return (int)contacts.size();
}

int add_contact_group(DBHANDLE db,const char *group)
{
	char sql[] = "insert into AddressGroup(Name) values(?)";
	sqlite3_stmt *pStmt;
	const char *pTail = NULL;
	if (SQLITE_OK != sqlite3_prepare_v2((sqlite3*)db, sql, -1, &pStmt, &pTail))
		return -1;
	if (SQLITE_OK != sqlite3_bind_text(pStmt, 1, group, strlen(group), NULL))
	{
		sqlite3_finalize(pStmt);
		return -1;
	}
	int result = sqlite3_step(pStmt);
	sqlite3_finalize(pStmt);;
	//if (result == SQLITE_DONE)
	return (result==SQLITE_DONE?SQLITE_OK:result);
}

int delete_contact_group(DBHANDLE db,const char *group)
{
	char sql[] = "delete from AddressGroup where Name=?";
	sqlite3_stmt *pStmt;
	const char *pTail = NULL;
	if (SQLITE_OK != sqlite3_prepare_v2((sqlite3*)db, sql, -1, &pStmt, &pTail))
		return -1;
	if (SQLITE_OK != sqlite3_bind_text(pStmt, 1, group, strlen(group), NULL))
	{
		sqlite3_finalize(pStmt);
		return -1;
	}
	int result = sqlite3_step(pStmt);
	sqlite3_finalize(pStmt);;
	//if (result == SQLITE_DONE)
	return (result == SQLITE_DONE ? SQLITE_OK : result);
}

int get_contact_groups(DBHANDLE db,list<string> & groups)
{
	char sql[] = "select Name from AdressGroup";
	sqlite3_stmt  *pStmt;
	const char* pTail = NULL;
	int ret = sqlite3_prepare_v2((sqlite3*)db, sql, strlen(sql), &pStmt, &pTail);
	if (ret != SQLITE_OK) return -1;
	do{
		ret = sqlite3_step(pStmt);
		
		if (ret == SQLITE_ROW)
		{
			char buf[256] = { 0 };
			memcpy(buf,sqlite3_column_text(pStmt, 0),sqlite3_column_bytes(pStmt,0));

			groups.push_back(buf);
		}
		else
			break;
	} while (1);

	sqlite3_finalize(pStmt);
	return  (int)groups.size();
}