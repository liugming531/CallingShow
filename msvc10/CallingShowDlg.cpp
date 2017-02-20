
// CallingShowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CallingShow.h"
#include "CallingShowDlg.h"
#include "afxdialogex.h"
#include "LocalAddressDialog.h"
#include "AddressListDialog.h"
#include "MessageSucessDialog.h"
#include "MessageFailDialog.h"
#include "ServiceHistoryDialog.h"
#include "DeviceListDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCallingShowDlg 对话框

CCallingShowDlg::CCallingShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCallingShowDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nMinWidth = 720;
	m_nMinHeight = 500;
}

void CCallingShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCallingShowDlg, CDialogEx)
	ON_WM_SIZING()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_COMMAND(ID_MENU_ADDR_LOCAL,OnMenuShowLocalAddress)
	ON_COMMAND(ID_MENU_ADDR_COMPANY,OnMenuShowCompanyAddress)
	ON_COMMAND(ID_MENU_ADDR_PERSON, OnMenuShowPersonAdress)
	ON_COMMAND(ID_MENU_ADDR_INNER, OnMenuShowInnerAddress)
	ON_COMMAND(ID_MENU_MSG_SUCCESS,OnMenuMessageSuccess)
	ON_COMMAND(ID_MENU_MSG_FAIL,OnMenuMessageFail)
	ON_COMMAND(ID_MENU_SERV_HISTORY, OnMenuHistory)
	ON_COMMAND(ID_MENU_SYS_DEVLIST, OnMenuDeviceList)
	ON_COMMAND(ID_MENU_SYS_UPDATE, OnMenuSystemUpdate)
END_MESSAGE_MAP()

//BEGIN_EASYSIZE_MAP(CCallingShowDlg)
//	EASYSIZE(IDD_CALLRECORD_TITLE_DIALOG,)
//END_EASYSIZE_MAP

// CCallingShowDlg 消息处理程序

BOOL CCallingShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitUI();
	//this->UpdateWindow();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCallingShowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCallingShowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCallingShowDlg::InitUI()
{
	title.Create(IDD_CALLRECORD_TITLE_DIALOG, this);
	title.SetParent(this);
	title.ShowWindow(SW_SHOW);
	content.Create(IDD_CALLRECORD_CONTENT_DIALOG, this);
	content.SetParent(this);
	content.ShowWindow(SW_SHOW);
	m_recordtoolbar_dlg.Create(IDD_RECORDTOOLBAR_DIALOG,this);
	m_recordtoolbar_dlg.ShowWindow(SW_SHOW);
	//this->MoveWindow()
	int desk_cx = GetSystemMetrics(SM_CXSCREEN);
	int desk_cy = GetSystemMetrics(SM_CYSCREEN);

	int width = (780 > desk_cx) ? desk_cx : 780;
	int height = (670 > desk_cy) ? desk_cy : 670;

	this->MoveWindow((desk_cx - width) / 2, (desk_cy - height) / 2, width, height);
}

void CCallingShowDlg::OnMenuShowLocalAddress()
{
	CLocalAddressDialog  dlg;
	dlg.DoModal();
}

void CCallingShowDlg::OnMenuShowCompanyAddress()
{
	CAddressListDialog  dlg;
	dlg.DoModal();
}

void CCallingShowDlg::OnMenuShowPersonAdress()
{
	CAddressListDialog  dlg;
	dlg.DoModal();
}

void CCallingShowDlg::OnMenuShowInnerAddress()
{

}
void CCallingShowDlg::OnMenuMessageSuccess()
{
	CMessageSucessDialog dlg;
	dlg.DoModal();
}
void CCallingShowDlg::OnMenuMessageFail()
{
	CMessageFailDialog dlg;
	dlg.DoModal();
}
void CCallingShowDlg::OnMenuHistory()
{
	CServiceHistoryDialog dlg;
	dlg.DoModal();
}
void CCallingShowDlg::OnMenuDeviceList()
{
	CDeviceListDialog dlg;
	dlg.DoModal();
}
void CCallingShowDlg::OnMenuSystemUpdate()
{

}

void CCallingShowDlg::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);
	if (title.GetSafeHwnd() && content.GetSafeHwnd())
	{
		CRect rect;
		title.GetWindowRect(&rect);
		title.MoveWindow(0, 0, cx, rect.Height());

		content.MoveWindow(0, rect.Height()+1, cx, cy - rect.Height() - 33);

		m_recordtoolbar_dlg.MoveWindow(0,cy-32,cx,30);
	}
}

void CCallingShowDlg::OnSizing(UINT nSide, LPRECT  lpRect)
{
	CDialog::OnSizing(nSide, lpRect);

	EASYSIZE_MINSIZE(m_nMinWidth,m_nMinHeight, nSide, lpRect);
}