// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DialogEditorDemo.h"

#include "MainFrm.h"
//******AS update start**************************//
#include "NotifyHook.h"
#include "afxpriv.h"
#include "..\src\mfc\afximpl.h"
//******AS update end****************************//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
//******AS update start**************************//
	ON_WM_DESTROY()
    ON_WM_CLOSE()
//******AS update end****************************//
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
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
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
 //******AS update start**************************//
//
    CHostApp* pApp = (CHostApp*)AfxGetApp(); 
    // We need set the main frame parent for modal dialogs binding 
	// with framework window
	cs.hwndParent = pApp->GetFrameworkWnd();     
//******AS update end****************************//

	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}
//******AS update start**************************//

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

    CFrameWnd::OnClose();
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
		CFrameWnd::OnDestroy();
	}
}

//******AS update end****************************//

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


