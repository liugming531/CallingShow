// ServiceRecordAddDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "ServiceRecordAddDialog.h"
#include "afxdialogex.h"


// CServiceRecordAddDialog �Ի���

IMPLEMENT_DYNAMIC(CServiceRecordAddDialog, CDialog)

CServiceRecordAddDialog::CServiceRecordAddDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CServiceRecordAddDialog::IDD, pParent)
{

}

CServiceRecordAddDialog::~CServiceRecordAddDialog()
{
}

void CServiceRecordAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CServiceRecordAddDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CServiceRecordAddDialog::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CServiceRecordAddDialog::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// CServiceRecordAddDialog ��Ϣ�������


void CServiceRecordAddDialog::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}


void CServiceRecordAddDialog::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
