#pragma once

#include <string>
// CLoginDialog �Ի���

class CLoginDialog : public CDialog
{
	DECLARE_DYNAMIC(CLoginDialog)

public:
	CLoginDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDialog();

// �Ի�������
	enum { IDD = IDD_LOGIN_DIALOG };
	virtual BOOL OnInitDialog();

	std::string GetLoginToken(){ return login_token; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLogin();

private:
	std::string  login_token;
};
