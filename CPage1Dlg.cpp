// CPage1Dlg.cpp : implementation file
//

#include "pch.h"
#include "CPSC362.h"
#include "CPSC362Dlg.h"
#include "CPage1Dlg.h"
#include "afxdialogex.h"


// CPage1Dlg dialog

IMPLEMENT_DYNAMIC(CPage1Dlg, CDialogEx)

CPage1Dlg::CPage1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CPage1Dlg::~CPage1Dlg()
{
}

BOOL CPage1Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    return TRUE;
}

void CPage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CPage1Dlg::OnBnClickedEnter()
{
    GetDlgItemText(IDC_EDIT_NAME, m_name);
    GetDlgItemText(IDC_EDIT_MAJOR, m_major);

    m_name.Trim();
    m_major.Trim();

    if (m_name.IsEmpty() || m_major.IsEmpty())
    {
        AfxMessageBox(
            _T("Please enter your name and major."));
        return;
    }

    CCPSC362Dlg* pMain =
        DYNAMIC_DOWNCAST(CCPSC362Dlg, GetParent());

    if (pMain != nullptr)
    {
        pMain->ShowClassPage(m_name, m_major);
    }
}


BEGIN_MESSAGE_MAP(CPage1Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPage1Dlg::OnBnClickedEnter)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

//Function for darker colors

/*HBRUSH CPage1Dlg::OnCtlColor(
    CDC* pDC,
    CWnd* pWnd,
    UINT nCtlColor)
{
    static CBrush blueBrush(RGB(190, 225, 250));

    if (nCtlColor == CTLCOLOR_DLG)
    {
        return (HBRUSH)blueBrush.GetSafeHandle();
    }

    if (nCtlColor == CTLCOLOR_STATIC)
    {
        pDC->SetTextColor(RGB(255, 255, 255));
        pDC->SetBkMode(TRANSPARENT);

        return (HBRUSH)blueBrush.GetSafeHandle();
    }

    return CDialogEx::OnCtlColor(
        pDC, pWnd, nCtlColor);
}*/

//Function for lighter colors

HBRUSH CPage1Dlg::OnCtlColor(
    CDC* pDC,
    CWnd* pWnd,
    UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(
        pDC, pWnd, nCtlColor);

    if (nCtlColor == CTLCOLOR_DLG)
    {
        static CBrush blueBrush(RGB(190, 220, 250));
        return blueBrush;
    }

    return hbr;
}


// CPage1Dlg message handlers
