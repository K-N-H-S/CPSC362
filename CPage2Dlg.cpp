// CPage2Dlg.cpp : implementation file
//

#include "pch.h"
#include "CPSC362.h"
#include "CPage2Dlg.h"
#include "afxdialogex.h"


// CPage2Dlg dialog

IMPLEMENT_DYNAMIC(CPage2Dlg, CDialogEx)

CPage2Dlg::CPage2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CPage2Dlg::~CPage2Dlg()
{
}

void CPage2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CPage2Dlg::SetStudentInfo
(
    const CString& name,
    const CString& major)
{
    m_name = name;
    m_major = major;

    if (GetSafeHwnd() != nullptr)
    {
        SetDlgItemText(IDC_STATIC_NAME, m_name);
        SetDlgItemText(IDC_STATIC_MAJOR, m_major);
    }
}


BEGIN_MESSAGE_MAP(CPage2Dlg, CDialogEx)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

HBRUSH CPage2Dlg::OnCtlColor(
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

// CPage2Dlg message handlers
