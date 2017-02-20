#pragma once
#include "afxcmn.h"


// CAddressListDialog �Ի���

class CAddressListDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddressListDialog)

public:
	CAddressListDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddressListDialog();

// �Ի�������
	enum { IDD = IDD_ADDRESSLIST_DIALOG };

	void SetType(int type){ addr_type = type; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	CListCtrl m_list_info;
	//0-��ҵͨѶ¼  1-����ͨѶ¼  2-��ҵ�ڲ�ͨѶ¼
	int  addr_type;
};
