#pragma once


// CMessageBoxDlg �Ի���

class CMessageBoxDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageBoxDlg)

public:
	CMessageBoxDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMessageBoxDlg();

// �Ի�������
	enum { IDD = IDD_MESSAGEBOX_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
