// MessageTemplateDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "MessageTemplateDlg.h"
#include "afxdialogex.h"


// CMessageTemplateDlg 对话框

IMPLEMENT_DYNAMIC(CMessageTemplateDlg, CDialog)

CMessageTemplateDlg::CMessageTemplateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageTemplateDlg::IDD, pParent)
{

}

CMessageTemplateDlg::~CMessageTemplateDlg()
{
}

void CMessageTemplateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMessageTemplateDlg, CDialog)
END_MESSAGE_MAP()


// CMessageTemplateDlg 消息处理程序
