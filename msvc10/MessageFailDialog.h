#pragma once


// CMessageFailDialog �Ի���

class CMessageFailDialog : public CDialog
{
	DECLARE_DYNAMIC(CMessageFailDialog)

public:
	CMessageFailDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMessageFailDialog();

// �Ի�������
	enum { IDD = IDD_MESSAGEFAIL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
