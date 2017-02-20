
// CallingShowDlg.h : ͷ�ļ�
//

#include "CallRecordContentDialog.h"
#include "CallRecordTitleDialog.h"
#include "easysize.h"
#include "RecordToolbarDlg.h"


class CLoginDialog;
// CCallingShowDlg �Ի���
class CCallingShowDlg : public CDialogEx
{
// ����
public:
	CCallingShowDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALLINGSHOW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_EASYSIZE
	afx_msg void OnMenuShowLocalAddress();
	afx_msg void OnMenuShowCompanyAddress();
	afx_msg void OnMenuMessageSuccess();
	afx_msg void OnMenuMessageFail();
	afx_msg void OnMenuShowPersonAdress();
	afx_msg void OnMenuShowInnerAddress();
	afx_msg void OnMenuHistory();
	afx_msg void OnMenuDeviceList();
	afx_msg void OnMenuSystemUpdate();

	afx_msg void OnSize(UINT nType,int cx, int cy);
	afx_msg void OnSizing(UINT nSide, LPRECT  lpRect);
private:
	CallRecordContentDialog  content;
	CallRecordTitleDialog title;
	CRecordToolbarDlg  m_recordtoolbar_dlg;
	CLoginDialog * login_dlg_p;

	void InitUI();

	int m_nMinWidth;
	int m_nMinHeight;
};
