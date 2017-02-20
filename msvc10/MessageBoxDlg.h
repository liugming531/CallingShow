#pragma once


// CMessageBoxDlg 对话框

class CMessageBoxDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageBoxDlg)

public:
	CMessageBoxDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMessageBoxDlg();

// 对话框数据
	enum { IDD = IDD_MESSAGEBOX_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
