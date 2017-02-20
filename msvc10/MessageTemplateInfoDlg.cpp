// MessageTemplateInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "MessageTemplateInfoDlg.h"
#include "afxdialogex.h"


// CMessageTemplateInfoDlg 对话框

IMPLEMENT_DYNAMIC(CMessageTemplateInfoDlg, CDialog)

CMessageTemplateInfoDlg::CMessageTemplateInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageTemplateInfoDlg::IDD, pParent)
{

}

CMessageTemplateInfoDlg::~CMessageTemplateInfoDlg()
{
}

void CMessageTemplateInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMessageTemplateInfoDlg, CDialog)
END_MESSAGE_MAP()


// CMessageTemplateInfoDlg 消息处理程序
