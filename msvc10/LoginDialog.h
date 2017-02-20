#pragma once

#include <string>
// CLoginDialog 对话框

class CLoginDialog : public CDialog
{
	DECLARE_DYNAMIC(CLoginDialog)

public:
	CLoginDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDialog();

// 对话框数据
	enum { IDD = IDD_LOGIN_DIALOG };
	virtual BOOL OnInitDialog();

	std::string GetLoginToken(){ return login_token; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLogin();

private:
	std::string  login_token;
};
