#pragma once
#include "afxcmn.h"
#include "easysize.h"

// CallRecordContentDialog �Ի���

class CallRecordContentDialog : public CDialog
{
	DECLARE_DYNAMIC(CallRecordContentDialog)

public:
	CallRecordContentDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CallRecordContentDialog();

// �Ի�������
	enum { IDD = IDD_CALLRECORD_CONTENT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnSize(UINT nType,int cx,int cy);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_EASYSIZE
private:
	CListCtrl m_list_record;

	void InitUI();
};
