// ServiceHistoryDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "ServiceHistoryDialog.h"
#include "afxdialogex.h"
#include "ServiceRecordAddDialog.h"


// CServiceHistoryDialog 对话框

IMPLEMENT_DYNAMIC(CServiceHistoryDialog, CDialog)

CServiceHistoryDialog::CServiceHistoryDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CServiceHistoryDialog::IDD, pParent)
{

}

CServiceHistoryDialog::~CServiceHistoryDialog()
{
}

void CServiceHistoryDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_service_record);
}


BEGIN_MESSAGE_MAP(CServiceHistoryDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SERVICE_RECORD_ADD, &CServiceHistoryDialog::OnBnClickedButtonServiceRecordAdd)
END_MESSAGE_MAP()


// CServiceHistoryDialog 消息处理程序
BOOL CServiceHistoryDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_list_service_record.InsertColumn(0,L"序号",LVCFMT_CENTER,60);
	m_list_service_record.InsertColumn(1,L"客户姓名",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(2,L"电话号码",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(3,L"商品价格",LVCFMT_CENTER,80);
	m_list_service_record.InsertColumn(4,L"商品名称",LVCFMT_CENTER,100);
	m_list_service_record.InsertColumn(5,L"销售员",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(6,L"购买日期",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(7,L"购买数量",LVCFMT_CENTER,80);
	m_list_service_record.InsertColumn(8,L"备注",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(9,L"",LVCFMT_CENTER,60);
	m_list_service_record.InsertColumn(10,L"",LVCFMT_CENTER,60);
	return TRUE;
}

void CServiceHistoryDialog::OnBnClickedButtonServiceRecordAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CServiceRecordAddDialog dlg;
	dlg.DoModal();
}
