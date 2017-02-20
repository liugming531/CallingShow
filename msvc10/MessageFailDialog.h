#pragma once


// CMessageFailDialog 对话框

class CMessageFailDialog : public CDialog
{
	DECLARE_DYNAMIC(CMessageFailDialog)

public:
	CMessageFailDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMessageFailDialog();

// 对话框数据
	enum { IDD = IDD_MESSAGEFAIL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
