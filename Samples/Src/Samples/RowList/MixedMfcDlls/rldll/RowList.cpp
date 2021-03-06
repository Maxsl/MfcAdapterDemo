// RowList.cpp : Defines the class behaviors for the application.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "RowList.h"

#include "MainFrm.h"
#include "RListDoc.h"

#include "ListVwEx.h"   // base class for CRowListView
#include "RListVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRowListApp

BEGIN_MESSAGE_MAP(CRowListApp, CWinApp)
	//{{AFX_MSG_MAP(CRowListApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_BUTTON_ROWLIST, &CRowListApp::OnButtonRowList)
	// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRowListApp construction

CRowListApp::CRowListApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CRowListApp object

CRowListApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CRowListApp initialization

BOOL CRowListApp::InitInstance()
{
//******AS update start**************************//
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		InitApplication();

		//change DLL flag in AFX_MODULE_STATE
		AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
		pModuleState->m_bDLL = NULL;
//******AS update end****************************//

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	m_pDocTemplate = new CRowListTemp(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CRowListDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CRowListView));
	AddDocTemplate(m_pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	//CCommandLineInfo cmdInfo;
	//ParseCommandLine(cmdInfo);

	//// Dispatch commands specified on the command line
	//if (!ProcessShellCommand(cmdInfo))
	//	return FALSE;

	return TRUE;
}

BOOL CRowListApp::AttachApplication(HWND hFrameworkWnd)
{
	m_hFrameworkWnd = hFrameworkWnd;
	
	return TRUE;
}
BOOL CRowListApp::DetachApplication()
{
	LRESULT lRes = 0;
	
	// if m_pMainWnd==NULL than application detached yet
	if(m_pMainWnd)
	{
		lRes = ::SendMessage(m_pMainWnd->GetSafeHwnd(),WM_CLOSE,0,0);
	}
	
	return lRes==0;
}
//******AS update end****************************//

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CRowListApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CRowListApp commands
void CRowListApp::OnButtonRowList()
{
	m_pDocTemplate->OpenDocumentFile(NULL);
}