#include <list>
#include <string>
#include "afxwin.h"
#include "db.h"
// CLocalAdressAddDialog �Ի���

class CLocalAdressAddDialog : public CDialog
{
	DECLARE_DYNAMIC(CLocalAdressAddDialog)

public:
	CLocalAdressAddDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLocalAdressAddDialog();

// �Ի�������
	enum { IDD = IDD_LOCALADRESS_ADD_DIALOG };
	virtual BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	std::list<std::string> local_groups;

	CComboBox m_combobox_group;
	CComboBox m_combobox_sex;

	local_contact_info  contact;
public:
	void InitGroupsText(std::list<std::string> groups){ local_groups = groups; }
	afx_msg void OnBnClickedButtonLocaladdressClose();
	afx_msg void OnBnClickedButton1();

	
	local_contact_info & GetContactInfo(){ return contact; }
};
