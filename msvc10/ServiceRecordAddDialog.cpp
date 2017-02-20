// ServiceRecordAddDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "ServiceRecordAddDialog.h"
#include "afxdialogex.h"


// CServiceRecordAddDialog 对话框

IMPLEMENT_DYNAMIC(CServiceRecordAddDialog, CDialog)

CServiceRecordAddDialog::CServiceRecordAddDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CServiceRecordAddDialog::IDD, pParent)
{

}

CServiceRecordAddDialog::~CServiceRecordAddDialog()
{
}

void CServiceRecordAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CServiceRecordAddDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CServiceRecordAddDialog::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CServiceRecordAddDialog::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// CServiceRecordAddDialog 消息处理程序


void CServiceRecordAddDialog::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}


void CServiceRecordAddDialog::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}
