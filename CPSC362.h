
// CPSC362.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCPSC362App:
// See CPSC362.cpp for the implementation of this class
//

class CCPSC362App : public CWinApp
{
public:
	CCPSC362App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCPSC362App theApp;
