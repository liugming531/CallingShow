#pragma once
#include "afxcmn.h"


// CServiceHistoryDialog �Ի���

class CServiceHistoryDialog : public CDialog
{
	DECLARE_DYNAMIC(CServiceHistoryDialog)

public:
	CServiceHistoryDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CServiceHistoryDialog();

// �Ի�������
	enum { IDD = IDD_SERVICEHISTORY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonServiceRecordAdd();
private:
	CListCtrl m_list_service_record;
};
