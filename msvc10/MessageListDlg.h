#pragma once


// CMessageListDlg �Ի���

class CMessageListDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageListDlg)

public:
	CMessageListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMessageListDlg();

// �Ի�������
	enum { IDD = IDD_MESSAGELIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
