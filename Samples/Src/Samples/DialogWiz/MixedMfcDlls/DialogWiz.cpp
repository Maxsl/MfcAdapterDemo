// DialogWiz.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DialogWiz.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "DialogWizDoc.h"
#include "DialogWizView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogWizApp

BEGIN_MESSAGE_MAP(CDialogWizApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CDialogWizApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CDialogWizApp construction

CDialogWizApp::CDialogWizApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CDialogWizApp object

CDialogWizApp theApp;


// CDialogWizApp initialization

BOOL CDialogWizApp::InitInstance()
{
//******AS update start**************************//
	//trick with error LNK2005
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
//******AS update end****************************//

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

//******AS update start**************************//
	//CWinApp::InitInstance();
	InitApplication();

	//change DLL flag in AFX_MODULE_STATE
	AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
	pModuleState->m_bDLL = NULL;
//******AS update end****************************//

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)

//******AS update start**************************//
	//// Register the application's document templates.  Document templates
	////  serve as the connection between documents, frame windows and views
	//CMultiDocTemplate* pDocTemplate;
	//pDocTemplate = new CMultiDocTemplate(IDR_DialogWizTYPE,
	//	RUNTIME_CLASS(CDialogWizDoc),
	//	RUNTIME_CLASS(CChildFrame), // custom MDI child frame
	//	RUNTIME_CLASS(CDialogWizView));
	//if (!pDocTemplate)
	//	return FALSE;
	//AddDocTemplate(pDocTemplate);

	//// create main MDI Frame window
	//CMainFrame* pMainFrame = new CMainFrame;
	//if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	//{
	//	delete pMainFrame;
	//	return FALSE;
	//}
	//m_pMainWnd = pMainFrame;
	//// call DragAcceptFiles only if there's a suffix
	////  In an MDI app, this should occur immediately after setting m_pMainWnd


	//// Parse command line for standard shell commands, DDE, file open
	//CCommandLineInfo cmdInfo;
	//ParseCommandLine(cmdInfo);


	//// Dispatch commands specified on the command line.  Will return FALSE if
	//// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	//if (!ProcessShellCommand(cmdInfo))
	//	return FALSE;
	//// The main window has been initialized, so show and update it
	//pMainFrame->ShowWindow(m_nCmdShow);
	//pMainFrame->UpdateWindow();
//******AS update end****************************//
	
	return TRUE;
}

//******AS update start**************************//
// Realisation of the IApplication interface
// attach MFC legacy application to external Framework
BOOL CDialogWizApp::AttachApplication(HWND hFrameworkWnd)
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
BOOL CDialogWizApp::DetachApplication()
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


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// App command to run the dialog
void CDialogWizApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CDialogWizApp message handlers

