// MessageBoxDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CallingShow.h"
#include "MessageBoxDlg.h"
#include "afxdialogex.h"


// CMessageBoxDlg �Ի���

IMPLEMENT_DYNAMIC(CMessageBoxDlg, CDialog)

CMessageBoxDlg::CMessageBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageBoxDlg::IDD, pParent)
{

}

CMessageBoxDlg::~CMessageBoxDlg()
{
}

void CMessageBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMessageBoxDlg, CDialog)
END_MESSAGE_MAP()


// CMessageBoxDlg ��Ϣ�������
