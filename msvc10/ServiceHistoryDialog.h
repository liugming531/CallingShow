#pragma once
#include "afxcmn.h"


// CServiceHistoryDialog 对话框

class CServiceHistoryDialog : public CDialog
{
	DECLARE_DYNAMIC(CServiceHistoryDialog)

public:
	CServiceHistoryDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CServiceHistoryDialog();

// 对话框数据
	enum { IDD = IDD_SERVICEHISTORY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonServiceRecordAdd();
private:
	CListCtrl m_list_service_record;
};
