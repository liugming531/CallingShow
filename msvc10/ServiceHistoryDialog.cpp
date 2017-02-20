// ServiceHistoryDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "ServiceHistoryDialog.h"
#include "afxdialogex.h"
#include "ServiceRecordAddDialog.h"


// CServiceHistoryDialog �Ի���

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


// CServiceHistoryDialog ��Ϣ�������
BOOL CServiceHistoryDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_list_service_record.InsertColumn(0,L"���",LVCFMT_CENTER,60);
	m_list_service_record.InsertColumn(1,L"�ͻ�����",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(2,L"�绰����",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(3,L"��Ʒ�۸�",LVCFMT_CENTER,80);
	m_list_service_record.InsertColumn(4,L"��Ʒ����",LVCFMT_CENTER,100);
	m_list_service_record.InsertColumn(5,L"����Ա",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(6,L"��������",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(7,L"��������",LVCFMT_CENTER,80);
	m_list_service_record.InsertColumn(8,L"��ע",LVCFMT_CENTER,120);
	m_list_service_record.InsertColumn(9,L"",LVCFMT_CENTER,60);
	m_list_service_record.InsertColumn(10,L"",LVCFMT_CENTER,60);
	return TRUE;
}

void CServiceHistoryDialog::OnBnClickedButtonServiceRecordAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CServiceRecordAddDialog dlg;
	dlg.DoModal();
}
