#pragma once
#include "afxcmn.h"


// CDeviceListDialog �Ի���

class CDeviceListDialog : public CDialog
{
	DECLARE_DYNAMIC(CDeviceListDialog)

public:
	CDeviceListDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeviceListDialog();

// �Ի�������
	enum { IDD = IDD_DEVICELIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list_device;
};
