#pragma once
#include "afxcmn.h"


// CAddressListDialog 对话框

class CAddressListDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddressListDialog)

public:
	CAddressListDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddressListDialog();

// 对话框数据
	enum { IDD = IDD_ADDRESSLIST_DIALOG };

	void SetType(int type){ addr_type = type; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	CListCtrl m_list_info;
	//0-企业通讯录  1-个人通讯录  2-企业内部通讯录
	int  addr_type;
};
