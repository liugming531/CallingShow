// MessageFailDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "MessageFailDialog.h"
#include "afxdialogex.h"


// CMessageFailDialog �Ի���

IMPLEMENT_DYNAMIC(CMessageFailDialog, CDialog)

CMessageFailDialog::CMessageFailDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageFailDialog::IDD, pParent)
{

}

CMessageFailDialog::~CMessageFailDialog()
{
}

void CMessageFailDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMessageFailDialog, CDialog)
END_MESSAGE_MAP()


// CMessageFailDialog ��Ϣ�������
