#pragma once

#include "easysize.h"

// CallRecordTitleDialog �Ի���

class CallRecordTitleDialog : public CDialog
{
	DECLARE_DYNAMIC(CallRecordTitleDialog)

public:
	CallRecordTitleDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CallRecordTitleDialog();

// �Ի�������
	enum { IDD = IDD_CALLRECORD_TITLE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
	DECLARE_EASYSIZE
};
