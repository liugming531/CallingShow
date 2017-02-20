#pragma once


// CCallRecordDialog 对话框

class CCallRecordDialog : public CDialog
{
	DECLARE_DYNAMIC(CCallRecordDialog)

public:
	CCallRecordDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCallRecordDialog();

// 对话框数据
	enum { IDD = IDD_CALLRECORD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
