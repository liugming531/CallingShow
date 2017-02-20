// LocalAdressAddDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "LocalAdressAddDialog.h"
#include "afxdialogex.h"


// CLocalAdressAddDialog 对话框

IMPLEMENT_DYNAMIC(CLocalAdressAddDialog, CDialog)

CLocalAdressAddDialog::CLocalAdressAddDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLocalAdressAddDialog::IDD, pParent)
{

}

CLocalAdressAddDialog::~CLocalAdressAddDialog()
{
}

void CLocalAdressAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_combobox_group);
	DDX_Control(pDX, IDC_COMBO1, m_combobox_sex);
}


BEGIN_MESSAGE_MAP(CLocalAdressAddDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LOCALADDRESS_CLOSE, &CLocalAdressAddDialog::OnBnClickedButtonLocaladdressClose)
	ON_BN_CLICKED(IDC_BUTTON1, &CLocalAdressAddDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLocalAdressAddDialog 消息处理程序
BOOL CLocalAdressAddDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	std::list<std::string>::iterator  it;
	for (it = local_groups.begin(); it != local_groups.end(); ++it)
	{
		WCHAR  szGroup[128];
		MultiByteToWideChar(CP_UTF8, 0, it->c_str(), -1, szGroup, 128);

		m_combobox_group.AddString(szGroup);
	}
	return FALSE;
}

void CLocalAdressAddDialog::OnBnClickedButtonLocaladdressClose()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}


void CLocalAdressAddDialog::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//add new contact
	memset(&contact, 0, sizeof(contact));
	CString  szName, szPhone, szGroup,szStr;
	int sex;
	GetDlgItemText(IDC_EDIT1, szName);
	if (szName.IsEmpty())
	{
		AfxMessageBox(L"联系人姓名不能为空");
		return;
	}

	GetDlgItemText(IDC_EDIT3, szPhone);
	if (szPhone.IsEmpty())
	{
		AfxMessageBox(L"联系人电话不能为空");
		return;
	}

	sex = m_combobox_sex.GetCurSel();
	if (sex < 0)
	{
		AfxMessageBox(L"请选择联系人的性别");
		return;
	}
	WideCharToMultiByte(CP_UTF8, 0, szName, -1, contact.name, sizeof(contact.name), NULL, NULL);
	WideCharToMultiByte(CP_UTF8, 0, szPhone, -1, contact.phone, sizeof(contact.phone), NULL, NULL);
	contact.sex = sex;
	//city
	GetDlgItemText(IDC_EDIT6, szStr);
	if (!szStr.IsEmpty())
	{
		WideCharToMultiByte(CP_UTF8, 0, szStr, -1, contact.city, sizeof(contact.city), NULL, NULL);
	}
	//company
	GetDlgItemText(IDC_EDIT8, szStr);
	if (!szStr.IsEmpty())
	{
		WideCharToMultiByte(CP_UTF8, 0, szStr, -1, contact.company, sizeof(contact.company), NULL, NULL);
	}
	//department
	GetDlgItemText(IDC_EDIT9, szStr);
	if (!szStr.IsEmpty())
	{
		WideCharToMultiByte(CP_UTF8, 0, szStr, -1, contact.department, sizeof(contact.department), NULL, NULL);
	}
	//group
	if (m_combobox_group.GetCurSel() > 0)
	{
		m_combobox_group.GetLBText(m_combobox_group.GetCurSel(), szStr);
		WideCharToMultiByte(CP_UTF8, 0, szStr, -1, contact.group, sizeof(contact.group), NULL, NULL);	
	}
	else
	{
		WideCharToMultiByte(CP_UTF8, 0, L"默认组", -1, contact.group, sizeof(contact.group), NULL, NULL);
	}
	//address
	GetDlgItemText(IDC_EDIT7, szStr);
	if (!szStr.IsEmpty())
	{
		WideCharToMultiByte(CP_UTF8, 0, szStr, -1, contact.address, sizeof(contact.address), NULL, NULL);
	}

	//OnOK();

	DBHANDLE  db = db_open();
	if (!db){
		AfxMessageBox(L"添加联系人信息失败");
		return;
	}

	add_contact(db, &contact);
	db_close(db);
	AfxMessageBox(L"添加联系人信息成功");
}
