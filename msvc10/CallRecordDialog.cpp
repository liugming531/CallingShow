// CallRecordDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "CallRecordDialog.h"
#include "afxdialogex.h"


// CCallRecordDialog 对话框

IMPLEMENT_DYNAMIC(CCallRecordDialog, CDialog)

CCallRecordDialog::CCallRecordDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCallRecordDialog::IDD, pParent)
{

}

CCallRecordDialog::~CCallRecordDialog()
{
}

void CCallRecordDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCallRecordDialog, CDialog)
END_MESSAGE_MAP()


// CCallRecordDialog 消息处理程序
