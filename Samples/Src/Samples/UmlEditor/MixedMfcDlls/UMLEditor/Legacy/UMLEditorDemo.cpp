/* ==========================================================================
	Class :			CUMLEditorDemo

	Author :		Johan Rosengren, Abstrakt Mekanik AB

	Date :			2004-06-20

	Purpose :		"CUMLEditorDemo", derived from "CWinApp" is the 
					application class of UMLEditorDemo.

	Description :	See the MFC documentation

	Usage :			Created by MFC. The shared clipboard handler is a member 
					of this class. The single instance of the object is 
					exposed through the global variable "theApp".

   ========================================================================*/
//******AS update start**************************//
//	Updated Alexey Shalnov for Hosting in .NET application
//******AS update end****************************//

#include "stdafx.h"
#include "UMLEditorDemo.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "UMLEditorDemoDoc.h"
#include "UMLEditorDemoView.h"
#include "AboutDlg.h"

//******AS update start**************************//
#include "UMLEditorDemoTemp.h"
//******AS update end****************************//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoApp

BEGIN_MESSAGE_MAP(CUMLEditorDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CUMLEditorDemoApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoApp construction

CUMLEditorDemoApp::CUMLEditorDemoApp()
/* ============================================================
	Function :		CUMLEditorDemoApp::CUMLEditorDemoApp
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Created by MFC

   ============================================================*/
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CUMLEditorDemoApp object

CUMLEditorDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoApp initialization

BOOL CUMLEditorDemoApp::InitInstance()
/* ============================================================
	Function :		CUMLEditorDemoApp::InitInstance
	Description :	Main entry point for the application.
	Access :		Public

	Return :		BOOL	-	"TRUE" if run ok.
	Parameters :	none

	Usage :			Called from MFC

   ============================================================*/
{
//******AS update start**************************//
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		InitApplication();

		//change DLL flag in AFX_MODULE_STATE
		AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
		pModuleState->m_bDLL = NULL;

		// InitCommonControlsEx() is required on Windows XP if an application
		// manifest specifies use of ComCtl32.dll version 6 or later to enable
		// visual styles.  Otherwise, any window creation will fail.
		INITCOMMONCONTROLSEX InitCtrls;
		InitCtrls.dwSize = sizeof(InitCtrls);
		// Set this to include all the common control classes you want to use
		// in your application.
		InitCtrls.dwICC = ICC_WIN95_CLASSES;
		InitCommonControlsEx(&InitCtrls);
//******AS update end****************************//

	AfxEnableControlContainer();

	SetRegistryKey( _T( "UMLEditorDemo" ) );

	LoadStdProfileSettings();

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CUMLEditorDemoTemp(
		IDR_UMLEDITYPE,
		RUNTIME_CLASS( CUMLEditorDemoDoc ),
		RUNTIME_CLASS( CChildFrame ),
		RUNTIME_CLASS( CUMLEditorDemoView ) );
	AddDocTemplate(pDocTemplate);

	//******AS update start**************************//
	//CMainFrame* pMainFrame = new CMainFrame;
	//if( !pMainFrame->LoadFrame( IDR_MAINFRAME ) )
	//	return FALSE;
	//m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	//CCommandLineInfo cmdInfo;
	//ParseCommandLine( cmdInfo );

	//// Dispatch commands specified on the command line
	//if ( !ProcessShellCommand( cmdInfo ) )
	//	return FALSE;

	// The main window has been initialized, so show and update it.
	//pMainFrame->ShowWindow( m_nCmdShow );
	//pMainFrame->UpdateWindow();
//******AS update end****************************//

	return TRUE;
}
//******AS update start**************************//

BOOL CUMLEditorDemoApp::AttachApplication(HWND hFrameworkWnd)
{
	m_hFrameworkWnd = hFrameworkWnd;

	// create MainFrame
	CMainFrame* pMainFrame = new CMainFrame;
	
	if( !pMainFrame->LoadFrame( IDR_MAINFRAME ) )
	{	
		return FALSE;
	}
	
	m_pMainWnd = pMainFrame;
	
	return TRUE;
}
BOOL CUMLEditorDemoApp::DetachApplication()
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

// App command to run the dialog
void CUMLEditorDemoApp::OnAppAbout()
/* ============================================================
	Function :		CUMLEditorDemoApp::OnAppAbout
	Description :	Handler for the About-message
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Called from MFC

   ============================================================*/
{

	CAboutDlg aboutDlg;
	aboutDlg.DoModal();

}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoApp message handlers

