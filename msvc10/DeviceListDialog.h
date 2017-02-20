#pragma once
#include "afxcmn.h"


// CDeviceListDialog 对话框

class CDeviceListDialog : public CDialog
{
	DECLARE_DYNAMIC(CDeviceListDialog)

public:
	CDeviceListDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeviceListDialog();

// 对话框数据
	enum { IDD = IDD_DEVICELIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list_device;
};
