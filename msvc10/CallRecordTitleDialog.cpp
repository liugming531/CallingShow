// CallRecordTitleDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "CallRecordTitleDialog.h"
#include "afxdialogex.h"


// CallRecordTitleDialog 对话框

IMPLEMENT_DYNAMIC(CallRecordTitleDialog, CDialog)

CallRecordTitleDialog::CallRecordTitleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CallRecordTitleDialog::IDD, pParent)
{

}

CallRecordTitleDialog::~CallRecordTitleDialog()
{
}

void CallRecordTitleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CallRecordTitleDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()

//EASYSIZE(id,l,t,r,b,o)
BEGIN_EASYSIZE_MAP(CallRecordTitleDialog)
	EASYSIZE(IDC_EDIT1, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_EDIT2, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_EDIT3, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_EDIT4, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_EDIT5, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)

	EASYSIZE(IDC_STATIC_T, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_EDIT6, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_EDIT7, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
	EASYSIZE(IDC_EDIT8, ES_BORDER, ES_BORDER, ES_KEEPSIZE, ES_KEEPSIZE, 0)
END_EASYSIZE_MAP

// CallRecordTitleDialog 消息处理程序
BOOL CallRecordTitleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	INIT_EASYSIZE;
	return TRUE;
}

void CallRecordTitleDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	UPDATE_EASYSIZE;
}