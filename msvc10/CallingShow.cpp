
// CallingShow.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "CallingShow.h"
#include "CallingShowDlg.h"
#include "LoginDialog.h"
#include "getlinkerlistrequest.h"


#pragma comment(lib,"dskinliteu.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCallingShowApp

BEGIN_MESSAGE_MAP(CCallingShowApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCallingShowApp ����

CCallingShowApp::CCallingShowApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCallingShowApp ����

CCallingShowApp theApp;


// CCallingShowApp ��ʼ��

BOOL CCallingShowApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2),&wsa);

	if (dsInitKeys("netviom.com", "1BE83CEA9C00CBC8314E661A"))
		dsLoadSkin(_T("skin.db"), LOAD_FROM_DB);
	else
	{
		AfxMessageBox(L"Load Skin file failed");
		return FALSE;
	}

	CLoginDialog  logindlg;
	if(IDOK != logindlg.DoModal())
	{
		return FALSE;
	}

	CCallingShowDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	WSACleanup();

	dsExitSkin();
	return FALSE;
}

