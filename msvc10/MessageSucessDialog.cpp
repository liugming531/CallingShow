// MessageSucessDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "MessageSucessDialog.h"
#include "afxdialogex.h"


// CMessageSucessDialog �Ի���

IMPLEMENT_DYNAMIC(CMessageSucessDialog, CDialog)

CMessageSucessDialog::CMessageSucessDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageSucessDialog::IDD, pParent)
{

}

CMessageSucessDialog::~CMessageSucessDialog()
{
}

void CMessageSucessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMessageSucessDialog, CDialog)
END_MESSAGE_MAP()


// CMessageSucessDialog ��Ϣ�������
