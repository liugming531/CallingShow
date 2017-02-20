// AddressListDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "AddressListDialog.h"
#include "afxdialogex.h"


// CAddressListDialog 对话框

IMPLEMENT_DYNAMIC(CAddressListDialog, CDialog)

CAddressListDialog::CAddressListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddressListDialog::IDD, pParent)
{

}

CAddressListDialog::~CAddressListDialog()
{
}

void CAddressListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ADDRESSLIST_INFO, m_list_info);
}


BEGIN_MESSAGE_MAP(CAddressListDialog, CDialog)
END_MESSAGE_MAP()


// CAddressListDialog 消息处理程序
BOOL CAddressListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_list_info.InsertColumn(0, L"序号", LVCFMT_CENTER, 60);
	m_list_info.InsertColumn(1, L"姓名", LVCFMT_CENTER, 120);
	m_list_info.InsertColumn(2, L"姓别", LVCFMT_CENTER, 80);
	m_list_info.InsertColumn(3, L"手机号码", LVCFMT_CENTER, 120);
	m_list_info.InsertColumn(4, L"所属组", LVCFMT_CENTER, 120);
	m_list_info.InsertColumn(5, L"所在城市", LVCFMT_CENTER, 120);
	//m_list_info.InsertColumn(5, L"生日", LVCFMT_CENTER, 120);

	return TRUE;
}