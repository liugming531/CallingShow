// RecordToolbarDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "RecordToolbarDlg.h"
#include "afxdialogex.h"


// CRecordToolbarDlg 对话框

IMPLEMENT_DYNAMIC(CRecordToolbarDlg, CDialog)

CRecordToolbarDlg::CRecordToolbarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecordToolbarDlg::IDD, pParent)
{

}

CRecordToolbarDlg::~CRecordToolbarDlg()
{
}

void CRecordToolbarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRecordToolbarDlg, CDialog)
END_MESSAGE_MAP()


// CRecordToolbarDlg 消息处理程序
