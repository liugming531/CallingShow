#pragma once


// CMessageTemplateDlg �Ի���

class CMessageTemplateDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageTemplateDlg)

public:
	CMessageTemplateDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMessageTemplateDlg();

// �Ի�������
	enum { IDD = IDD_MESSAGETEMPLATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
