#pragma once
#include "afxcmn.h"
#include "db.h"

// CLocalAddressDialog 对话框

class CLocalAddressDialog : public CDialog
{
	DECLARE_DYNAMIC(CLocalAddressDialog)

public:
	CLocalAddressDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLocalAddressDialog();

// 对话框数据
	enum { IDD = IDD_LOCALADDRESS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_listLocalAddress;
	CTreeCtrl m_treeLocalAddress;

	CImageList  m_imglist;

	std::list<local_contact_info>  contacts;
	std::list<string>  groups;
	void InitData();
public:
	
	afx_msg void OnBnClickedButtonLocaladdressAdd();
	afx_msg void OnNMRClickTreeLocaladdressGroup(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void AddGroup();
	afx_msg void DeleteGroup();
	afx_msg void RenameGroup();
	afx_msg void ClearGroup();
	afx_msg void OnBnClickedButtonLocaladdressExport();
};
