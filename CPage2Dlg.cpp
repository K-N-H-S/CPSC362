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
END_MESSAGE_MAP()


// CPage2Dlg message handlers
