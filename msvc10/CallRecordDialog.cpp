// CallRecordDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "CallRecordDialog.h"
#include "afxdialogex.h"


// CCallRecordDialog �Ի���

IMPLEMENT_DYNAMIC(CCallRecordDialog, CDialog)

CCallRecordDialog::CCallRecordDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCallRecordDialog::IDD, pParent)
{

}

CCallRecordDialog::~CCallRecordDialog()
{
}

void CCallRecordDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCallRecordDialog, CDialog)
END_MESSAGE_MAP()


// CCallRecordDialog ��Ϣ�������
