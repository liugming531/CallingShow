// CallRecordContentDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "CallRecordContentDialog.h"
#include "afxdialogex.h"


// CallRecordContentDialog 对话框

IMPLEMENT_DYNAMIC(CallRecordContentDialog, CDialog)

CallRecordContentDialog::CallRecordContentDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CallRecordContentDialog::IDD, pParent)
{

}

CallRecordContentDialog::~CallRecordContentDialog()
{
}

void CallRecordContentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_record);
}


BEGIN_MESSAGE_MAP(CallRecordContentDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()

BEGIN_EASYSIZE_MAP(CallRecordContentDialog)
	EASYSIZE(IDC_LIST1,ES_BORDER,ES_BORDER,ES_BORDER,ES_BORDER,0)
END_EASYSIZE_MAP

// CallRecordContentDialog 消息处理程序

BOOL CallRecordContentDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitUI();
	INIT_EASYSIZE;
	return TRUE;
}

void CallRecordContentDialog::OnSize(UINT nType,int cx,int cy)
{
	CDialog::OnSize(nType,cx,cy);
	/*if(m_list_record.GetSafeHwnd())
	{
		CRect  rect;
		m_list_record.GetWindowRect(&rect);
		ScreenToClient(rect);
		m_list_record.MoveWindow(0,rect.top,cx,cy - rect.top);
	}*/
	UPDATE_EASYSIZE;
}

void CallRecordContentDialog::InitUI()
{
	m_list_record.InsertColumn(0,L"序号",LVCFMT_CENTER,50);
	m_list_record.InsertColumn(1,L"通话号码",LVCFMT_CENTER,120);
	m_list_record.InsertColumn(2,L"客户姓名",LVCFMT_CENTER,120);
	m_list_record.InsertColumn(3,L"通话时间",LVCFMT_CENTER,120);
	m_list_record.InsertColumn(4,L"设备ID",LVCFMT_CENTER,150);
	m_list_record.InsertColumn(5,L"本机号码",LVCFMT_CENTER,120);
	m_list_record.InsertColumn(6,L"通话状态",LVCFMT_CENTER,100);
	m_list_record.InsertColumn(7,L"通话时长",LVCFMT_CENTER,100);
	m_list_record.InsertColumn(8,L"通话类型",LVCFMT_CENTER,80);
	m_list_record.InsertColumn(9,L"挂机短信",LVCFMT_CENTER,80);
	m_list_record.InsertColumn(0,L"操作",LVCFMT_CENTER,80);
}