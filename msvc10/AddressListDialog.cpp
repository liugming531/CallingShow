// AddressListDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "AddressListDialog.h"
#include "afxdialogex.h"


// CAddressListDialog �Ի���

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


// CAddressListDialog ��Ϣ�������
BOOL CAddressListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_list_info.InsertColumn(0, L"���", LVCFMT_CENTER, 60);
	m_list_info.InsertColumn(1, L"����", LVCFMT_CENTER, 120);
	m_list_info.InsertColumn(2, L"�ձ�", LVCFMT_CENTER, 80);
	m_list_info.InsertColumn(3, L"�ֻ�����", LVCFMT_CENTER, 120);
	m_list_info.InsertColumn(4, L"������", LVCFMT_CENTER, 120);
	m_list_info.InsertColumn(5, L"���ڳ���", LVCFMT_CENTER, 120);
	//m_list_info.InsertColumn(5, L"����", LVCFMT_CENTER, 120);

	return TRUE;
}