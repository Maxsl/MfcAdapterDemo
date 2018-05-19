// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DialogWiz.h"

#include "MainFrm.h"
#include "NotifyHook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
//******AS update start**************************//
    ON_WM_CLOSE()
//******AS update end****************************//
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
//******AS update start**************************//
    // We use COleFrameHook interface for communucation with external framework.
    // So framework look like as outstanding component object now.
    // Don't forgot close this object before close application MainWnd!!!
    CHostApp* pApp = (CHostApp*)AfxGetApp(); 
	m_pNotifyHook = new CNotifyHook(this,pApp->GetFrameworkWnd());
	//******AS update end****************************//
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
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

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
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

	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

void CMainFrame::OnClose()
{       
//******AS update start**************************//
	// we can not exit if there are outstanding component objects
    m_pNotifyHook->m_pFrameWnd = NULL;
    delete m_pNotifyHook;
    m_pNotifyHook = NULL;
//******AS update end****************************//
    CMDIFrameWnd::OnClose();
}
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame message handlers



