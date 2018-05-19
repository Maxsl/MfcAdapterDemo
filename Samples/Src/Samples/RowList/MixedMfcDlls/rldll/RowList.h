// RowList.h : main header file for the ROWLIST application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
//******AS update start**************************//
#include "HostApp.h"       
//******AS update end****************************//
#include "RowListTemp.h"

/////////////////////////////////////////////////////////////////////////////
// CRowListApp:
// See RowList.cpp for the implementation of this class
//

class CRowListApp : public CHostApp 
{
private:
	CRowListTemp* m_pDocTemplate;

public:
	CRowListApp();
	//******AS update start**************************//
	//CHostApp realisation
	BOOL AttachApplication(HWND hFrameworkWnd);
	BOOL DetachApplication();
	//******AS update end****************************//

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRowListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRowListApp)
	afx_msg void OnAppAbout();
	afx_msg void OnButtonRowList();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
