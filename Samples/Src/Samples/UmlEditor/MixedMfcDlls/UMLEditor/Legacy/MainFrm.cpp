/* ==========================================================================
	Class :			CMainFrm

	Author :		Johan Rosengren, Abstrakt Mekanik AB

	Date :			2004-06-20

	Purpose :		"CMainFrm", derived from "CMDIFrameWnd", is the main 
					frame window of the application.

	Description :	See MFC documentation

	Usage :			Created by MFC

========================================================================*/
//******AS update start**************************//
//	Updated Alexey Shalnov for Hosting in .NET application
//******AS update end****************************//

#include "stdafx.h"
#include "UMLEditorDemo.h"

#include "MainFrm.h"

//******AS update start**************************//
#include "Hosting\NotifyHook.h"
//******AS update end****************************//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
//******AS update start**************************//
    ON_COMMAND(ID_WINDOW_NEW, OnWindowNew)
	ON_WM_DESTROY()
    ON_WM_CLOSE()
//******AS update end****************************//
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
/* ============================================================
	Function :		CMainFrame::CMainFrame
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Created by MFC

   ============================================================*/
{
//******AS update start**************************//
    // We use COleFrameHook interface for communucation with external framework.
    // So framework look like as outstanding component object now.
    // Don't forgot close this object before close application MainWnd!!!
    CHostApp* pApp = (CHostApp*)AfxGetApp(); 
	m_pNotifyHook = new CNotifyHook(this,pApp->GetFrameworkWnd());
	m_bIsClosed = FALSE;
//******AS update end****************************//
}

CMainFrame::~CMainFrame()
/* ============================================================
	Function :		CMainFrame::~CMainFrame
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Don't delete this object.

   ============================================================*/
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
/* ============================================================
	Function :		CMainFrame::OnCreate
	Description :	Creates the frame
	Access :		Protected

	Return :		int								-	-1 if failure
	Parameters :	LPCREATESTRUCT lpCreateStruct	-	Creation
														parameters
					
	Usage :			Called from MFC.

   ============================================================*/
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

#ifndef _DEBUG	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

#endif

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
/* ============================================================
	Function :		CMainFrame::PreCreateWindow
	Description :	Called before the window is created.
	Access :		Public

	Return :		BOOL				-	"TRUE" if created ok
	Parameters :	CREATESTRUCT& cs	-	Creation parameters
					
	Usage :			Called from MFC. Modify styles here.

   ============================================================*/
{
 //******AS update start**************************//
//
	CUMLEditorDemoApp* pApp = (CUMLEditorDemoApp*)AfxGetApp(); 
    // We need set the main frame parent for modal dialogs binding 
	// with framework window
	cs.hwndParent = pApp->GetFrameworkWnd();     
//******AS update end****************************//

	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

//******AS update start**************************//
// We change standard logic for invisible InitialUpdate 
void CMainFrame::OnWindowNew()
{
    CMDIChildWnd* pActiveChild = MDIGetActive();
    CDocument* pDocument;
    if (pActiveChild == NULL ||
      (pDocument = pActiveChild->GetActiveDocument()) == NULL)
    {
            TRACE(traceAppMsg, 0, "Warning: No active document for WindowNew command.\n");
            AfxMessageBox(AFX_IDP_COMMAND_FAILURE);
            return;     // command failed
    }

    // otherwise we have a new frame !
    CDocTemplate* pTemplate = pDocument->GetDocTemplate();
    ASSERT_VALID(pTemplate);
    CFrameWnd* pFrame = pTemplate->CreateNewFrame(pDocument, pActiveChild);
    if (pFrame == NULL)
    {
            TRACE(traceAppMsg, 0, "Warning: failed to create new frame.\n");
            return;     // command failed
    }
    
    //AS
    //pTemplate->InitialUpdateFrame(pFrame, pDocument);
    // We make visible later
    pTemplate->InitialUpdateFrame(pFrame, pDocument, FALSE);
}

void CMainFrame::OnClose()
{       
	m_bIsClosed = TRUE;

	// Check that we don't have views attached to control 

	CDocManager* pDocManager = AfxGetApp()->m_pDocManager;
	// no doc manager - no templates
	if (pDocManager != NULL)
	{
		// walk all templates in the application
		CDocTemplate* pTemplate;
		POSITION pos = pDocManager->GetFirstDocTemplatePosition();
		while (pos != NULL)
		{
			pTemplate = pDocManager->GetNextDocTemplate(pos);
			ASSERT_VALID(pTemplate);
			ASSERT_KINDOF(CDocTemplate, pTemplate);

			// walk all documents in the template
			POSITION pos2 = pTemplate->GetFirstDocPosition();
			while (pos2)
			{
				CDocument* pDoc = pTemplate->GetNextDoc(pos2);
				ASSERT_VALID(pDoc);
				POSITION pos3 = pDoc->GetFirstViewPosition();
				CView* pView = NULL;
				while (pos3 != NULL)
				{
					pView = pDoc->GetNextView(pos3);
					//if view is Visible than it attached to control 
					//We can not remove attached resource
					ASSERT(pView->IsWindowVisible()==FALSE);
				}
			}
		}
	}

	// we can not exit if there are outstanding component objects
    m_pNotifyHook->m_pFrameWnd = NULL;
    delete m_pNotifyHook;
    m_pNotifyHook = NULL;

    CMDIFrameWnd::OnClose();
}

void CMainFrame::OnDestroy()
{
	if(!m_bIsClosed)
	{
		TRACE(traceAppMsg, 0, "Warning: destroying not detached application.\n");
		
		//detache application
		this->OnClose();
	}
	else
	{
		CMDIFrameWnd::OnDestroy();
	}
}

//******AS update end****************************//

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
/* ============================================================
	Function :		CMainFrame::AssertValid
	Description :	Asserts the validity of this object.
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Use for diagnostics

   ============================================================*/
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
/* ============================================================
	Function :		CMainFrame::Dump
	Description :	Dumps class information
	Access :		Public

	Return :		void
	Parameters :	CDumpContext& dc	-	Dump context
					
	Usage :			Use for diagnostics

   ============================================================*/
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

