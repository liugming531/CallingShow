#include "StdAfx.h"
#include "UploadModule.h"
#include "CardProtocol.h"

CUploadModule * CUploadModule::obj = NULL;

CUploadModule::CUploadModule(void)
{
	Initialize();
}

CUploadModule::~CUploadModule(void)
{
	UnInitialize();
}

CUploadModule * CUploadModule::Instance()
{
	if(!obj)
	{
		obj = new CUploadModule();
	}

	return obj;
}

void CUploadModule::Initialize()
{
	InitializeCriticalSection(&sMutex);


	hThreadSignal[0] = CreateSemaphore(NULL,0,LONG_MAX,NULL);
	hThreadSignal[1] = CreateEvent(NULL,FALSE,FALSE,NULL);

	ASSERT(hThreadSignal[0]!=NULL);
	ASSERT(hThreadSignal[1]!=NULL);

	AfxBeginThread(WorkThreadFun,this);
}

void CUploadModule::UnInitialize()
{
	DeleteCriticalSection(&sMutex);

	CloseHandle(hThreadSignal[0]);
	CloseHandle(hThreadSignal[1]);
} 

UINT CUploadModule::WorkThreadFun(LPVOID lp)
{
	CUploadModule * m = (CUploadModule*)lp;
	//char *buf = (char*)malloc(4096);
	//ASSERT(buf!=NULL);

	DWORD dwRet;
	BOOL  done = TRUE;
	while(done)
	{
		dwRet = WaitForMultipleObjects(SIG_ALL,m->hThreadSignal,FALSE,INFINITE);
		switch(dwRet - WAIT_OBJECT_0)
		{
		case SIG_TASK:
			{
				Task * task = m->PopPacket();
				if(task)
				{
					if(task->DoTask() != 0 && task->CanTestCount() > 0)
					{
						Sleep(5000);
						m->AddTask(task);
					}
					else
						delete task;
				}
			}
			
			break;
		case SIG_EXIT:
			done = FALSE;
			break;
		default:
			return 1;
		}
	}
	return 0;
}

UINT CUploadModule::WorkTimerFun(LPVOID lp)
{
	return 0;
}

int CUploadModule::AddTask(Task *task)
{
	if(task==NULL) return 0;
	//memcpy(p,pkt,sizeof(FramePacket));

	EnterCriticalSection(&sMutex);
	sWorkQueue.push(task);

	ReleaseSemaphore(hThreadSignal[SIG_TASK],1,NULL);
	LeaveCriticalSection(&sMutex);
	return 1;
}

Task * CUploadModule::PopPacket()
{
	Task * p = NULL;
	EnterCriticalSection(&sMutex);
	if(sWorkQueue.size() > 0)
	{
		p = sWorkQueue.front();
		sWorkQueue.pop();
	}
	LeaveCriticalSection(&sMutex);
	return p;

}

//void CUploadModule::DoUpload(const char *data,int length)
//{
//	if(length <= 0) return;
//	
//	//SOcket
//
//}