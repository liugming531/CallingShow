#pragma once


// CMessageSucessDialog �Ի���

class CMessageSucessDialog : public CDialog
{
	DECLARE_DYNAMIC(CMessageSucessDialog)

public:
	CMessageSucessDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMessageSucessDialog();

// �Ի�������
	enum { IDD = IDD_MESSAGESUCESS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
