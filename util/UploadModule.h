#pragma once

#include <queue>

using namespace std;

class Task {
public:
	Task():m_count_can_do(1){}
	virtual int DoTask()=0;
	
	int  CanTestCount(){ return m_count_can_do;}

	void  SetTestCount(int count){m_count_can_do = count;}
protected:
	int  m_count_can_do;
};

class CUploadModule
{
private:
	CUploadModule(void);

	static CUploadModule * obj;
public:
	~CUploadModule(void);

	static CUploadModule *  Instance();

	//void  StartModule();

	int  AddTask(Task * task);
private:
	
	void  Initialize();

	void  UnInitialize();

	Task * PopPacket();

	static UINT  WorkThreadFun(LPVOID lp);

	static UINT  WorkTimerFun(LPVOID lp);

	queue<Task*>   sWorkQueue;

	CRITICAL_SECTION  sMutex;

	HANDLE  hThreadSignal[2];

	enum{
		SIG_TASK = 0,
		SIG_EXIT,
		SIG_ALL
	};

	//void DoUpload(const char *data,int length);
};
