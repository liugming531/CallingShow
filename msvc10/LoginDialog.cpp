// LoginDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "LoginDialog.h"
#include "afxdialogex.h"
#include "loginrequest.h"

// CLoginDialog �Ի���

IMPLEMENT_DYNAMIC(CLoginDialog, CDialog)

CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDialog::IDD, pParent)
{

}

CLoginDialog::~CLoginDialog()
{
}

void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDialog::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CLoginDialog ��Ϣ�������
BOOL CLoginDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	//dsSkinWindow(GetSafeHwnd(), SKIN_TYPE_DIALOG, _T("login_dlg"), FALSE);
	//dsSkinWindow(GetDlgItem(IDC_BUTTON_LOGIN)->GetSafeHwnd(), SKIN_TYPE_BUTTON, _T("button"), FALSE);

	//dsSkinWindow(GetDlgItem(IDC_STATIC_LOGIN_PIC)->GetSafeHwnd(), SKIN_TYPE_STATIC, _T("login_static"), FALSE);

	return FALSE;
}

void CLoginDialog::OnBnClickedButtonLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString szUser,szPassword;
	GetDlgItemText(IDC_EDIT_LOGIN_USERNAME,szUser);
	GetDlgItemText(IDC_EDIT_LOGIN_PASSWD,szPassword);

	if(szUser.IsEmpty() || szPassword.IsEmpty()) 
	{
		AfxMessageBox(L"�û���������Ϊ��");
		return;
	}
	
	/*char username[128], password[128];
	WideCharToMultiByte(CP_ACP, 0, szUser, -1, username, sizeof(username), NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, szPassword, -1, password, sizeof(password), NULL, NULL);
	LoginRequest req(username, password);
	req.DoLogin();
	if (req.GetStatus() == HTTP_OK)
	{
		login_token = req.GetToken();
		OnOK();
	}
	else
	{
		CString msg;
		msg.Format(L"��¼ʧ��(%d)", req.GetStatus());
		AfxMessageBox(msg);
	}*/

	//LoginRequest  req("8888","netviom578");
	//req.parseXml();
	OnOK();
}
