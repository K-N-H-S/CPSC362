// CPSC362Dlg.h : header file
//

#pragma once

#include "CPage1Dlg.h"
#include "CPage2Dlg.h"

// CCPSC362Dlg dialog
class CCPSC362Dlg : public CDialogEx
{
private:
	CPage1Dlg* m_pPage1;
	CPage2Dlg* m_pPage2;

	void ShowPage(CDialogEx* pPage);

public:
	CCPSC362Dlg(CWnd* pParent = nullptr);

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CPSC362_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	HICON m_hIcon;

	virtual BOOL OnInitDialog();

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
};
