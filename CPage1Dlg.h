#pragma once

// CPage1Dlg dialog

class CPage1Dlg : public CDialogEx
{
    DECLARE_DYNAMIC(CPage1Dlg)

public:
    CPage1Dlg(CWnd* pParent = nullptr);
    virtual ~CPage1Dlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_DIALOG1 };
#endif

    // Student information
    CString m_name;
    CString m_major;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedEnter();
};
