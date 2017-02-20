#pragma once

#include "easysize.h"

// CallRecordTitleDialog 对话框

class CallRecordTitleDialog : public CDialog
{
	DECLARE_DYNAMIC(CallRecordTitleDialog)

public:
	CallRecordTitleDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CallRecordTitleDialog();

// 对话框数据
	enum { IDD = IDD_CALLRECORD_TITLE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
	DECLARE_EASYSIZE
};
