// DialogWiz.h : main header file for the DialogWiz application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
//******AS update start**************************//
#include "CHostApp.h"       
//******AS update end****************************//


// CDialogWizApp:
// See DialogWiz.cpp for the implementation of this class
//

class CDialogWizApp : public CHostApp
{
public:
	CDialogWizApp();


// Overrides
public:
	virtual BOOL InitInstance();
	
//******AS update start**************************//
	//CHostApp realisation
	BOOL AttachApplication(HWND hFrameworkWnd);
	BOOL DetachApplication();
//******AS update end****************************//

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDialogWizApp theApp;