#pragma once


// CRecordToolbarDlg �Ի���

class CRecordToolbarDlg : public CDialog
{
	DECLARE_DYNAMIC(CRecordToolbarDlg)

public:
	CRecordToolbarDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRecordToolbarDlg();

// �Ի�������
	enum { IDD = IDD_RECORDTOOLBAR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
