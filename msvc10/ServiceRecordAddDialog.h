//#pragma once


// CServiceRecordAddDialog �Ի���

class CServiceRecordAddDialog : public CDialog
{
	DECLARE_DYNAMIC(CServiceRecordAddDialog)

public:
	CServiceRecordAddDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CServiceRecordAddDialog();

// �Ի�������
	enum { IDD = IDD_SERVICERECORD_ADD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonClose();
};
