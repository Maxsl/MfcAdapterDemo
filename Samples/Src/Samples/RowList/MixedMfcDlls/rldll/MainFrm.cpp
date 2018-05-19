// MainFrm.cpp : implementation of the CMainFrame class
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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
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

	if (!m_wndToolBar.Create(this) ||
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

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
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
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style&=~FWS_ADDTOTITLE;

	return CFrameWnd::PreCreateWindow(cs);
}
//******AS update start**************************//
// We change standard logic for invisible InitialUpdate 
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
		TRACE(traceAppMsg, 0, "Warning: destroying not detached application. Try to dispose MfcAppAdapter explicitly. \n");
		
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
