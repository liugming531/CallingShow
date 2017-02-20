// LocalAddressDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "LocalAddressDialog.h"
#include "afxdialogex.h"
#include "LocalAdressAddDialog.h"


// CLocalAddressDialog 对话框

IMPLEMENT_DYNAMIC(CLocalAddressDialog, CDialog)

CLocalAddressDialog::CLocalAddressDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLocalAddressDialog::IDD, pParent)
{

}

CLocalAddressDialog::~CLocalAddressDialog()
{
	m_imglist.DeleteImageList();
}

void CLocalAddressDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LOCALADDRESS_INFO, m_listLocalAddress);
	DDX_Control(pDX, IDC_TREE_LOCALADDRESS_GROUP, m_treeLocalAddress);
}


BEGIN_MESSAGE_MAP(CLocalAddressDialog, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON_LOCALADDRESS_ADD, &CLocalAddressDialog::OnBnClickedButtonLocaladdressAdd)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_LOCALADDRESS_GROUP, &CLocalAddressDialog::OnNMRClickTreeLocaladdressGroup)
	ON_COMMAND(ID_MENU_ADD_GROUP,AddGroup)
	ON_COMMAND(ID_MENU_DELETE_GROUP,DeleteGroup)
	ON_COMMAND(ID_MENU_RENAME_GROUP,RenameGroup)
	ON_COMMAND(ID_MENU_CLEAR_GROUP,ClearGroup)
	ON_BN_CLICKED(IDC_BUTTON_LOCALADDRESS_EXPORT, &CLocalAddressDialog::OnBnClickedButtonLocaladdressExport)
END_MESSAGE_MAP()


// CLocalAddressDialog 消息处理程序
BOOL CLocalAddressDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_listLocalAddress.InsertColumn(0,L"序号",LVCFMT_CENTER,60);
	m_listLocalAddress.InsertColumn(1,L"姓名",LVCFMT_CENTER,120);
	m_listLocalAddress.InsertColumn(2, L"性别", LVCFMT_CENTER, 80);
	m_listLocalAddress.InsertColumn(3,L"手机号码",LVCFMT_CENTER,120);
	m_listLocalAddress.InsertColumn(4,L"工作",LVCFMT_CENTER,120);
	m_listLocalAddress.InsertColumn(5,L"所在城市",LVCFMT_CENTER,120);
	//m_listLocalAddress.InsertColumn(5,L"生日",LVCFMT_CENTER,120);
	m_listLocalAddress.InsertColumn(6,L"操作",LVCFMT_CENTER,150);
	m_listLocalAddress.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES|LVS_EX_FULLROWSELECT|LVS_EDITLABELS);

	//m_imglist.Create(36,32,ILC_COLOR32,0,4);
	//HBITMAP  hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
	//	L"./img/dir.bmp",
	//	IMAGE_BITMAP,
	//	0,
	//	0,
	//	LR_LOADFROMFILE);
	//CBitmap * pBitmap = new CBitmap();
	//pBitmap->Attach(hBitmap);
	//m_imglist.Add(pBitmap,RGB(0,0,0));
	//ASSERT(m_imglist.GetImageCount()>0);
	//m_treeLocalAddress.SetImageList(&m_imglist,1);
	m_treeLocalAddress.InsertItem(L"个人通讯录");

	InitData();
	
	return TRUE;
}


void CLocalAddressDialog::OnBnClickedButtonLocaladdressAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CLocalAdressAddDialog  dlg;
	
	dlg.DoModal();
}


void CLocalAddressDialog::InitData()
{
	DBHANDLE   db = db_open();
	if (!db) return;
	int count = get_contacts(db, contacts);
	if (count > 0)
	{
		std::list<local_contact_info>::iterator  it;
		WCHAR  buffer[256];
		for (it = contacts.begin(); it != contacts.end();++it)
		{
			int index = m_listLocalAddress.InsertItem(0, L"");

			CString szIndex;
			szIndex.Format(_T("%d"), index);
			m_listLocalAddress.SetItemText(index, 0, szIndex);
			MultiByteToWideChar(CP_UTF8, 0, it->name, -1, buffer, 256);
			m_listLocalAddress.SetItemText(index, 1, buffer);
			m_listLocalAddress.SetItemText(index, 2, (it->sex?_T("男"):_T("女")));
			m_listLocalAddress.SetItemText(index, 3, CString(it->phone));
			MultiByteToWideChar(CP_UTF8, 0, it->city, -1, buffer, 256);
			m_listLocalAddress.SetItemText(index, 5, buffer);
		}
	}
	count = get_contact_groups(db,groups);
	if (count > 0)
	{
		HTREEITEM hRoot = m_treeLocalAddress.GetRootItem();
		if (!hRoot)
			hRoot = m_treeLocalAddress.InsertItem(L"个人通讯录");

		std::list<string>::iterator  iter;
		WCHAR  buf[256];
		for (iter = groups.begin(); iter != groups.end(); ++iter)
		{
			MultiByteToWideChar(CP_UTF8, 0, iter->c_str(), -1, buf, 256);
			m_treeLocalAddress.InsertItem(buf, hRoot);
		}
	}
	db_close(db);

}

void CLocalAddressDialog::OnNMRClickTreeLocaladdressGroup(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	CMenu  menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu  *pop_menu = menu.GetSubMenu(0);
	POINT  point;
	GetCursorPos(&point);
	//ScreenToClient(&point);

	pop_menu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	*pResult = 0;
}

void  CLocalAddressDialog::AddGroup()
{
	TRACE("add Group\n");
}

void CLocalAddressDialog::RenameGroup()
{

}

void CLocalAddressDialog::DeleteGroup()
{

}

void CLocalAddressDialog::ClearGroup()
{

}

void CLocalAddressDialog::OnBnClickedButtonLocaladdressExport()
{
	// TODO:  在此添加控件通知处理程序代码
}
