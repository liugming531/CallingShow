#pragma once


// CMessageListDlg 对话框

class CMessageListDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageListDlg)

public:
	CMessageListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMessageListDlg();

// 对话框数据
	enum { IDD = IDD_MESSAGELIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
