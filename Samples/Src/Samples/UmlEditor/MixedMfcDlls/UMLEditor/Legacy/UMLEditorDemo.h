// UMLEditorDemo.h : main header file for the UMLEDITORDEMO application
//

#if !defined(AFX_UMLEDITORDEMO_H__4CF0E788_F18B_4D65_989E_3AB2BD3277D4__INCLUDED_)
#define AFX_UMLEDITORDEMO_H__4CF0E788_F18B_4D65_989E_3AB2BD3277D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "UMLEditor/UMLClipboardHandler.h"
//******AS update start**************************//
#include "HostApp.h"       
//******AS update end****************************//

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoApp:
// See UMLEditorDemo.cpp for the implementation of this class
//

class CUMLEditorDemoApp : public CHostApp
{
public:
	CUMLEditorDemoApp();

	CUMLClipboardHandler	m_clip;
//******AS update start**************************//
	//CHostApp realisation
	BOOL AttachApplication(HWND hFrameworkWnd);
	BOOL DetachApplication();
//******AS update end****************************//
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUMLEditorDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CUMLEditorDemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CUMLEditorDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UMLEDITORDEMO_H__4CF0E788_F18B_4D65_989E_3AB2BD3277D4__INCLUDED_)
