// SimpleTest.h : main header file for the SimpleTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

//******AS update start**************************//
#include "HostApp.h"       
//******AS update end****************************//

// CSimpleTestApp:
// See SimpleTest.cpp for the implementation of this class
//

class CSimpleTestApp : public CHostApp
{
private:
	CMultiDocTemplate* m_pScrollTemplate;
	CMultiDocTemplate* m_pListTemplate;

public:
	CSimpleTestApp();

//******AS update start**************************//
	//CHostApp realisation
	BOOL AttachApplication(HWND hFrameworkWnd);
	BOOL DetachApplication();
//******AS update end****************************//

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	afx_msg void OnButtonScroll();
	afx_msg void OnButtonList();
	DECLARE_MESSAGE_MAP()
};

extern CSimpleTestApp theApp;