
// CPSC362Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CPSC362.h"
#include "CPSC362Dlg.h"
#include "afxdialogex.h"
#include "Dialog1.h";

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCPSC362Dlg dialog



CCPSC362Dlg::CCPSC362Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CPSC362_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pPage1 = nullptr;
	m_pPage2 = nullptr;
}

void CCPSC362Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCPSC362Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCPSC362Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCPSC362Dlg message handlers

BOOL CCPSC362Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);

		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING,
				IDM_ABOUTBOX,
				strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_pPage1 = new CPage1Dlg();

	if (!m_pPage1->Create(IDD_DIALOG1, this))
	{
		delete m_pPage1;
		m_pPage1 = nullptr;

		return FALSE;
	}

	m_pPage2 = new CPage2Dlg();

	if (!m_pPage2->Create(IDD_DIALOG2, this))
	{
		delete m_pPage2;
		m_pPage2 = nullptr;

		return FALSE;
	}

	// Get the main dialog's client area
	CRect rect;
	GetClientRect(&rect);

	// Position Page 1 to fill the main dialog
	if (m_pPage1 != nullptr)
	{
		m_pPage1->SetWindowPos(
			nullptr,
			0, 0,
			rect.Width(),
			rect.Height(),
			SWP_NOZORDER | SWP_NOACTIVATE);
	}

	// Position Page 2 to fill the main dialog
	if (m_pPage2 != nullptr)
	{
		m_pPage2->SetWindowPos(
			nullptr,
			0, 0,
			rect.Width(),
			rect.Height(),
			SWP_NOZORDER | SWP_NOACTIVATE);
	}

	// Center the main dialog on the screen
	CRect windowRect;
	GetWindowRect(&windowRect);

	int windowWidth = windowRect.Width();
	int windowHeight = windowRect.Height();

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	int x = (screenWidth - windowWidth) / 2;
	int y = (screenHeight - windowHeight) / 2;

	SetWindowPos(
		nullptr,
		x, y,
		windowWidth,
		windowHeight,
		SWP_NOZORDER | SWP_NOACTIVATE);

	// Start with the welcome screen
	ShowPage(nullptr);

	return TRUE;
}

void CCPSC362Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCPSC362Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCPSC362Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCPSC362Dlg::ShowPage(CDialogEx* pPage)
{
	if (m_pPage1 != nullptr)
		m_pPage1->ShowWindow(SW_HIDE);

	if (m_pPage2 != nullptr)
		m_pPage2->ShowWindow(SW_HIDE);

	if (pPage != nullptr)
	{
		pPage->ShowWindow(SW_SHOW);
		pPage->SetFocus();
	}
}

void CCPSC362Dlg::OnBnClickedButton1()
{
	ShowPage(m_pPage1);
}

void CCPSC362Dlg::ShowClassPage(
	const CString& name,
	const CString& major)
{
	if (m_pPage2 != nullptr)
	{
		m_pPage2->SetStudentInfo(name, major);
		ShowPage(m_pPage2);
	}
}
