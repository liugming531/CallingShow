#pragma once


// CMessageTemplateDlg 对话框

class CMessageTemplateDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageTemplateDlg)

public:
	CMessageTemplateDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMessageTemplateDlg();

// 对话框数据
	enum { IDD = IDD_MESSAGETEMPLATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
