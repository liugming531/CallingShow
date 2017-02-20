// DeviceListDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "DeviceListDialog.h"
#include "afxdialogex.h"


// CDeviceListDialog 对话框

IMPLEMENT_DYNAMIC(CDeviceListDialog, CDialog)

CDeviceListDialog::CDeviceListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDeviceListDialog::IDD, pParent)
{

}

CDeviceListDialog::~CDeviceListDialog()
{
}

void CDeviceListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_device);
}


BEGIN_MESSAGE_MAP(CDeviceListDialog, CDialog)
END_MESSAGE_MAP()


// CDeviceListDialog 消息处理程序
BOOL CDeviceListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_list_device.InsertColumn(0,L"序号",LVCFMT_CENTER,60);
	m_list_device.InsertColumn(1,L"设备ID",LVCFMT_CENTER,150);
	m_list_device.InsertColumn(2,L"电话号码",LVCFMT_CENTER,120);
	m_list_device.InsertColumn(3,L"设备名称",LVCFMT_CENTER,150);
	m_list_device.InsertColumn(4,L"设备IP",LVCFMT_CENTER,120);
	m_list_device.InsertColumn(5,L"本机IP()",LVCFMT_CENTER,120);
	return TRUE;
}