/* ==========================================================================
	Class :			CChildFrm

	Author :		Johan Rosengren, Abstrakt Mekanik AB

	Date :			2004-06-20

	Purpose :		"CChildFrm", derived from "CMDIChildWnd" is the frame 
					window for the MDI-views.

	Description :	See MFC documentation.

	Usage :			Created by MFC.

   ========================================================================*/

#include "stdafx.h"
#include "UMLEditorDemo.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
/* ============================================================
	Function :		CChildFrame::CChildFrame
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Created by MFC

   ============================================================*/
{
}

CChildFrame::~CChildFrame()
/* ============================================================
	Function :		CChildFrame::~CChildFrame
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Don't delete this object.

   ============================================================*/
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
/* ============================================================
	Function :		CChildFrame::PreCreateWindow
	Description :	"PreCreateWindow" is called before the 
					window is created.
	Access :		Public

	Return :		BOOL				-	"TRUE" if created ok.
	Parameters :	CREATESTRUCT& cs	-	Create parameters
					
	Usage :			Add styles here, for example.

   ============================================================*/
{
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
/* ============================================================
	Function :		CChildFrame::AssertValid
	Description :	The function asserts that this object is 
					valid.
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Use for diagnostics.

   ============================================================*/
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
/* ============================================================
	Function :		CChildFrame::Dump
	Description :	The function dumps diagnostic information
					for this instance
	Access :		Public

	Return :		void
	Parameters :	CDumpContext& dc	-	Dump context
					
	Usage :			Use for debugging

   ============================================================*/
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
