#pragma once


// CMessageTemplateInfoDlg 对话框

class CMessageTemplateInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageTemplateInfoDlg)

public:
	CMessageTemplateInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMessageTemplateInfoDlg();

// 对话框数据
	enum { IDD = IDD_MESSAGETEMPLATEINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
