// MessageListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "MessageListDlg.h"
#include "afxdialogex.h"


// CMessageListDlg �Ի���

IMPLEMENT_DYNAMIC(CMessageListDlg, CDialog)

CMessageListDlg::CMessageListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageListDlg::IDD, pParent)
{

}

CMessageListDlg::~CMessageListDlg()
{
}

void CMessageListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMessageListDlg, CDialog)
END_MESSAGE_MAP()


// CMessageListDlg ��Ϣ�������
