#pragma once


// CMessageTemplateInfoDlg �Ի���

class CMessageTemplateInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CMessageTemplateInfoDlg)

public:
	CMessageTemplateInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMessageTemplateInfoDlg();

// �Ի�������
	enum { IDD = IDD_MESSAGETEMPLATEINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
