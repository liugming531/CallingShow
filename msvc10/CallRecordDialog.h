#pragma once


// CCallRecordDialog �Ի���

class CCallRecordDialog : public CDialog
{
	DECLARE_DYNAMIC(CCallRecordDialog)

public:
	CCallRecordDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCallRecordDialog();

// �Ի�������
	enum { IDD = IDD_CALLRECORD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
