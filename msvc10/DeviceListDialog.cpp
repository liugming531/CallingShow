// DeviceListDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "DeviceListDialog.h"
#include "afxdialogex.h"


// CDeviceListDialog �Ի���

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


// CDeviceListDialog ��Ϣ�������
BOOL CDeviceListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_list_device.InsertColumn(0,L"���",LVCFMT_CENTER,60);
	m_list_device.InsertColumn(1,L"�豸ID",LVCFMT_CENTER,150);
	m_list_device.InsertColumn(2,L"�绰����",LVCFMT_CENTER,120);
	m_list_device.InsertColumn(3,L"�豸����",LVCFMT_CENTER,150);
	m_list_device.InsertColumn(4,L"�豸IP",LVCFMT_CENTER,120);
	m_list_device.InsertColumn(5,L"����IP()",LVCFMT_CENTER,120);
	return TRUE;
}