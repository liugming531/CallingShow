#pragma once


// CRecordToolbarDlg 对话框

class CRecordToolbarDlg : public CDialog
{
	DECLARE_DYNAMIC(CRecordToolbarDlg)

public:
	CRecordToolbarDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRecordToolbarDlg();

// 对话框数据
	enum { IDD = IDD_RECORDTOOLBAR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
