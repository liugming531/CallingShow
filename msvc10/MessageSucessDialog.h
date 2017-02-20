#pragma once


// CMessageSucessDialog 对话框

class CMessageSucessDialog : public CDialog
{
	DECLARE_DYNAMIC(CMessageSucessDialog)

public:
	CMessageSucessDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMessageSucessDialog();

// 对话框数据
	enum { IDD = IDD_MESSAGESUCESS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
