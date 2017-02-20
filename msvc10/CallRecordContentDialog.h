#pragma once
#include "afxcmn.h"
#include "easysize.h"

// CallRecordContentDialog 对话框

class CallRecordContentDialog : public CDialog
{
	DECLARE_DYNAMIC(CallRecordContentDialog)

public:
	CallRecordContentDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CallRecordContentDialog();

// 对话框数据
	enum { IDD = IDD_CALLRECORD_CONTENT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnSize(UINT nType,int cx,int cy);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_EASYSIZE
private:
	CListCtrl m_list_record;

	void InitUI();
};
