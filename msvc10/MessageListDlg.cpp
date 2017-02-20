// MessageListDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "MessageListDlg.h"
#include "afxdialogex.h"


// CMessageListDlg 对话框

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


// CMessageListDlg 消息处理程序
