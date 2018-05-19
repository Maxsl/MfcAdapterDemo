/* ==========================================================================
	Class :			CUMLEditorDemoView

	Author :		Johan Rosengren, Abstrakt Mekanik AB

	Date :			2004-06-20

	Purpose :		"CUMLEditorDemoView", derived from "CView", is the view 
					of an MDI-window.

	Description :	See the MFC-documentation.

	Usage :			We use this class to host the editor, "m_editor". We 
					also get the commands from the toolbar and menu into 
					this class, and pass them on as appropriate to the 
					editor.

   ========================================================================
	Changes :		12/7 2004	Added CUMLEntityClassTemplate.
   ========================================================================*/
//******AS update start**************************//
//	Updated Alexey Shalnov for Hosting in .NET application
//******AS update end****************************//

#include "stdafx.h"
#include "UMLEditorDemo.h"

#include "UMLEditorDemoDoc.h"
#include "UMLEditorDemoView.h"

#include "UMLEditor/UMLEntityClass.h"
#include "UMLEditor/UMLLineSegment.h"
#include "UMLEditor/UMLEntityNote.h"
#include "UMLEditor/UMLEntityPackage.h"
#include "UMLEditor/UMLEntityLabel.h"
#include "UMLEditor/UMLEntityInterface.h"
#include "UMLEditor/UMLEntityClassTemplate.h"

#include "UMLEditor/UMLEditorPropertyDialog.h"

#include "ExportDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView

IMPLEMENT_DYNCREATE(CUMLEditorDemoView, CView)

BEGIN_MESSAGE_MAP(CUMLEditorDemoView, CView)
	//{{AFX_MSG_MAP(CUMLEditorDemoView)
	ON_COMMAND(ID_BUTTON_CLASS, OnButtonClass)
	ON_COMMAND(ID_BUTTON_LINK, OnButtonLink)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_BUTTON_NOTE, OnButtonNote)
	ON_COMMAND(ID_BUTTON_PACKAGE, OnButtonPackage)
	ON_COMMAND(ID_BUTTON_LABEL, OnButtonLabel)
	ON_COMMAND(ID_BUTTON_INTERFACE, OnButtonInterface)
	ON_COMMAND(ID_BUTTON_DISPLAY_PROPERTIES, OnButtonDisplayProperties)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_EXPORT, OnExport)
	ON_COMMAND(ID_FLIP_LINK, OnFlipLink)
	ON_UPDATE_COMMAND_UI(ID_FLIP_LINK, OnUpdateFlipLink)
	ON_COMMAND(ID_PROPERTY, OnProperty)
	ON_COMMAND(ID_ZOOM_100, OnZoom100)
	ON_COMMAND(ID_ZOOM_150, OnZoom150)
	ON_COMMAND(ID_ZOOM_200, OnZoom200)
	ON_COMMAND(ID_ZOOM_25, OnZoom25)
	ON_COMMAND(ID_ZOOM_50, OnZoom50)
	ON_COMMAND(ID_SNAP, OnSnap)
	ON_UPDATE_COMMAND_UI(ID_SNAP, OnUpdateSnap)
	ON_COMMAND(ID_SHOW_GRID, OnShowGrid)
	ON_UPDATE_COMMAND_UI(ID_SHOW_GRID, OnUpdateShowGrid)
	ON_COMMAND(ID_IMPORT, OnImport)
	ON_UPDATE_COMMAND_UI(ID_IMPORT, OnUpdateImport)
	ON_COMMAND(ID_EDIT_DELETE, OnEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, OnUpdateEditDelete)
	ON_COMMAND(ID_BUTTON_TEMPLATE, OnButtonTemplate)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView construction/destruction

CUMLEditorDemoView::CUMLEditorDemoView()
/* ============================================================
	Function :		CUMLEditorDemoView::CUMLEditorDemoView
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Created by MFC

   ============================================================*/
{

	m_screenResolutionX = 0;
	m_onlyh = FALSE;

}

CUMLEditorDemoView::~CUMLEditorDemoView()
/* ============================================================
	Function :		CUMLEditorDemoView::~CUMLEditorDemoView
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Don't delete this object.

   ============================================================*/
{
}

BOOL CUMLEditorDemoView::PreCreateWindow(CREATESTRUCT& cs)
/* ============================================================
	Function :		CUMLEditorDemoView::PreCreateWindow
	Description :	Called before the view is created.
	Access :		Public

	Return :		BOOL				-	"TRUE" if ok.
	Parameters :	CREATESTRUCT& cs	-	Creation parameters
					
	Usage :			Called from MFC.

   ============================================================*/
{	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView drawing

void CUMLEditorDemoView::OnDraw(CDC* pDC)
/* ============================================================
	Function :		CUMLEditorDemoView::OnDraw
	Description :	Draws the view.
	Access :		Public

	Return :		void
	Parameters :	CDC* pDC	-	"CDC" to draw to
					
	Usage :			The editor draws itself, but we use 
					"OnDraw" when printing - we want to set 
					the zoom level to 100% regardless of the 
					current level, we want to change the 
					background color and also to use the 
					printer/print preview "CDC".

   ============================================================*/
{

	CUMLEditorDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if( pDC->IsPrinting() )
	{

		COLORREF col = m_editor.GetBackgroundColor();

		// Print zoom is the difference between screen- 
		// and printer resolution.
		double zoom = pDC->GetDeviceCaps( LOGPIXELSX ) / m_screenResolutionX;

		CRect rect( 0,0, 
			round( static_cast< double >( m_editor.GetVirtualSize().cx ) * zoom ), 
			round( static_cast< double >( m_editor.GetVirtualSize().cy ) * zoom ) );

		m_editor.SetRedraw( FALSE );
		m_editor.SetBackgroundColor( RGB( 255, 255, 255 ) );
		m_editor.Print( pDC, rect, zoom );
		m_editor.SetBackgroundColor( col );
		m_editor.SetRedraw( TRUE );

	}

}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView printing

BOOL CUMLEditorDemoView::OnPreparePrinting(CPrintInfo* pInfo)
/* ============================================================
	Function :		CUMLEditorDemoView::OnPreparePrinting
	Description :	Setup function for printing.
	Access :		Protected

	Return :		BOOL				-	"TRUE" if ok
	Parameters :	CPrintInfo* pInfo	-	Print job info
					
	Usage :			Called from MFC. We just call default.

   ============================================================*/
{

	// default preparation
	return DoPreparePrinting(pInfo);

}

void CUMLEditorDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
/* ============================================================
	Function :		CUMLEditorDemoView::OnBeginPrinting
	Description :	Printing is starting.
	Access :		Protected

	Return :		void
	Parameters :	CDC*		-	Printer "CDC"
					CPrintInfo*	-	Print job info	
					
	Usage :			Called from MFC. We do nothing.

   ============================================================*/
{
}

void CUMLEditorDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
/* ============================================================
	Function :		CUMLEditorDemoView::OnEndPrinting
	Description :	Printing is finished
	Access :		Protected

	Return :		void
	Parameters :	CDC*		-	Printer "CDC"
					CPrintInfo*	-	Print job info	
					
	Usage :			Called from MFC. We do nothing.

   ============================================================*/
{
}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView diagnostics

#ifdef _DEBUG
void CUMLEditorDemoView::AssertValid() const
/* ============================================================
	Function :		CUMLEditorDemoView::AssertValid
	Description :	Asserts the object validity.
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Diagnostics function.

   ============================================================*/
{

	CView::AssertValid();

}

void CUMLEditorDemoView::Dump(CDumpContext& dc) const
/* ============================================================
	Function :		CUMLEditorDemoView::Dump
	Description :	Dumps the object state
	Access :		Public

	Return :		void
	Parameters :	CDumpContext& dc	-	Not used
					
	Usage :			Diagnostics function.

   ============================================================*/
{

	CView::Dump(dc);

}

CUMLEditorDemoDoc* CUMLEditorDemoView::GetDocument()
/* ============================================================
	Function :		CUMLEditorDemoView::GetDocument
	Description :	Gets a casted pointer to the attached 
					document.
	Access :		Public

	Return :		CUMLEditorDemoDoc*	-	Pointer to document.
	Parameters :	none

	Usage :			Call to get a pointer to the view document.

   ============================================================*/
{

	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUMLEditorDemoDoc)));
	return (CUMLEditorDemoDoc*)m_pDocument;

}
#endif //_DEBUG

void CUMLEditorDemoView::OnInitialUpdate() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnInitialUpdate
	Description :	Called when a view is created.
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			We set up an editor for the view.

   ============================================================*/
{

	CView::OnInitialUpdate();
	
	if( !m_editor.m_hWnd )
	{
		// Creating the editor window
		CUMLEditorDemoDoc* pDoc = GetDocument();

		CRect rect;
		GetClientRect( rect );
		pDoc->GetData()->SetClipboardHandler( &theApp.m_clip );
		m_editor.Create( WS_CHILD | WS_VISIBLE, rect, this, pDoc->GetData() );

		// We get the screen resolution, which we will use 
		// for scaling to printer. See also OnDraw.
		CClientDC dc( this );
		m_screenResolutionX = dc.GetDeviceCaps( LOGPIXELSX );

		// Setting up the virtual screen size
		// We want this to represent a single paper 
		// from the default printer.

		CPrintDialog	printer( TRUE, PD_RETURNDC );
		printer.GetDefaults();
		HDC	hdc = printer.GetPrinterDC();
		if( hdc )
		{

			double zoom = GetDeviceCaps( hdc, LOGPIXELSX ) / m_screenResolutionX;
			int horzSize = ::GetDeviceCaps( hdc, PHYSICALWIDTH );
			int vertSize = ::GetDeviceCaps( hdc, PHYSICALHEIGHT );

			m_editor.SetVirtualSize( CSize( round( static_cast< double >( horzSize ) / zoom ), round( static_cast< double >( vertSize ) / zoom ) ) );

			int leftMarg = ::GetDeviceCaps( hdc, PHYSICALOFFSETX );
			int topMarg = ::GetDeviceCaps( hdc, PHYSICALOFFSETY );

			int horzPrintable = ::GetDeviceCaps( hdc, HORZRES );
			int vertPrintable = ::GetDeviceCaps( hdc, VERTRES );

			int rightMarg = horzSize - ( horzPrintable + leftMarg );
			int bottomMarg = vertSize - ( vertPrintable + topMarg );

			m_editor.SetMargins( round( static_cast< double >( leftMarg ) / zoom ), round( static_cast< double >( topMarg ) / zoom ), round( static_cast< double >( rightMarg ) / zoom ), round( static_cast< double >( bottomMarg ) / zoom ) );

			::DeleteDC( hdc );

		}
		else
		{
			// No default printer installed
			m_editor.SetVirtualSize( CSize( 8 * m_screenResolutionX, 11 * m_screenResolutionX ) );
		}

		m_editor.SetScrollWheelMode( WHEEL_ZOOM );
		m_editor.SetModified( FALSE );

	}
	else
		m_editor.Clear();
	
}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView message handlers

void CUMLEditorDemoView::OnSize(UINT nType, int cx, int cy) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnSize
	Description :	Handler for the "WM_SIZE"-message.
	Access :		Protected

	Return :		void
	Parameters :	UINT nType	-	Not used
					int cx		-	New x-size
					int cy		-	New y-size
					
	Usage :			Resizes the editor to fill the whole client 
					area.

   ============================================================*/
{
	CView::OnSize(nType, cx, cy);
	
	if( m_editor.m_hWnd )
		m_editor.MoveWindow(0,0,cx,cy);
	
}

BOOL CUMLEditorDemoView::OnEraseBkgnd(CDC* /*pDC*/) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnEraseBkgnd
	Description :	Handler for the "WM_ERASEBKGND"-message.
	Access :		Protected

	Return :		BOOL		-	Always "TRUE".
	Parameters :	CDC* pDC	-	Not used
					
	Usage :			We override to avoid background erasing, as 
					the editor covers all of the view.

   ============================================================*/
{
	
	return TRUE;

}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView button- and menu handlers

void CUMLEditorDemoView::OnButtonLink() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonLink
	Description :	Handler for the link-button on the toolbar.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC when the button is pressed.
					Starts drawing an object of the selected 
					type.

   ============================================================*/
{

	m_editor.StartDrawingObject( new CUMLLineSegment );
	
}

void CUMLEditorDemoView::OnButtonNote() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonNote
	Description :	Handler for the note-button on the toolbar.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC when the button is pressed.
					Starts drawing an object of the selected 
					type.


   ============================================================*/
{

	CUMLEntityNote* obj = new CUMLEntityNote;
	m_editor.StartDrawingObject( obj );
	
}

void CUMLEditorDemoView::OnButtonPackage() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonPackage
	Description :	Handler for the package-button on the 
					toolbar.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC when the button is pressed.
					Starts drawing an object of the selected 
					type.


   ============================================================*/
{

	CUMLEntityPackage* obj = new CUMLEntityPackage;
	m_editor.StartDrawingObject( obj );
	
}

void CUMLEditorDemoView::OnButtonClass() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonClass
	Description :	Handler for the class-button on the 
					toolbar.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC when the button is pressed.
					Starts drawing an object of the selected 
					type.


   ============================================================*/
{

	CUMLEntityClass* obj = new CUMLEntityClass;
	m_editor.StartDrawingObject( obj );
	
}


void CUMLEditorDemoView::OnButtonLabel() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonLabel
	Description :	Handler for the label-button on the 
					toolbar.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC when the button is pressed.
					Starts drawing an object of the selected 
					type.


   ============================================================*/
{

	CUMLEntityLabel* obj = new CUMLEntityLabel;
	m_editor.StartDrawingObject( obj );
	
}

void CUMLEditorDemoView::OnButtonInterface() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonInterface
	Description :	Handler for the interface-button on the 
					toolbar.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC when the button is pressed.
					Starts drawing an object of the selected 
					type.


   ============================================================*/
{

	CUMLEntityInterface* obj = new CUMLEntityInterface;
	m_editor.StartDrawingObject( obj );
	
}

void CUMLEditorDemoView::OnButtonDisplayProperties() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonDisplayProperties
	Description :	Handles the Properties button on the toolbar.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Displays the editor 
					properties dialog.

   ============================================================*/
{

	CUMLEditorPropertyDialog	dlg;

	dlg.m_color = m_editor.GetBackgroundColor();
	dlg.m_showgrid = m_editor.IsGridVisible();
	dlg.m_grid = m_editor.GetSnapToGrid();
	dlg.m_showmargin = m_editor.IsMarginVisible();

	int displayOptions = m_editor.GetDisplayOptions();
	if( displayOptions & DISPLAY_ONLY_PUBLIC )
		dlg.m_onlypublic = TRUE;
	if( displayOptions & DISPLAY_NO_MARKERS )
		dlg.m_nomarkers = TRUE;
	if( displayOptions & DISPLAY_NO_ATTRIBUTES )
		dlg.m_noattributes = TRUE;
	if( displayOptions & DISPLAY_NO_OPERATIONS )
		dlg.m_nooperations = TRUE;
	if( displayOptions & DISPLAY_NO_OPERATION_ATTRIBUTE_NAMES )
		dlg.m_nooperationattributenames = TRUE;
	displayOptions = DISPLAY_ALL;
	if( dlg.DoModal() == IDOK )
	{
		m_editor.ShowGrid( dlg.m_showgrid );
		m_editor.ShowMargin( dlg.m_showmargin );
		m_editor.SetSnapToGrid( dlg.m_grid );
		m_editor.SetColor( dlg.m_color );

		if( dlg.m_onlypublic )
			displayOptions |= DISPLAY_ONLY_PUBLIC;

		if( dlg.m_nomarkers )
			displayOptions |= DISPLAY_NO_MARKERS;

		if( dlg.m_noattributes )
			displayOptions |= DISPLAY_NO_ATTRIBUTES;

		if( dlg.m_nooperations )
			displayOptions |= DISPLAY_NO_OPERATIONS;

		if( dlg.m_nooperationattributenames )
			displayOptions |= DISPLAY_NO_OPERATION_ATTRIBUTE_NAMES;

		m_editor.SetDisplayOptions( displayOptions );
		m_editor.RedrawWindow();

	}

}

void CUMLEditorDemoView::OnEditUndo() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnEditUndo
	Description :	Handles the Undo-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Undo the last operation.

   ============================================================*/
{

	m_editor.Undo();
	
}

void CUMLEditorDemoView::OnEditCopy() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnEditCopy
	Description :	Handles the Copy-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Copies the objects 
					currently selected in the editor to the 
					internal clipboard.

   ============================================================*/
{

	m_editor.Copy();
	
}

void CUMLEditorDemoView::OnEditCut() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnEditCut
	Description :	Handles the Cut-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Cuts the currently selected 
					items from the editor to the internal 
					clipboard.

   ============================================================*/
{

	m_editor.Cut();
	
}

void CUMLEditorDemoView::OnEditPaste() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnEditPaste
	Description :	Handles the Paste-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Pastes the contents of the 
					internal clipboard to the editor.

   ============================================================*/
{

	m_editor.Paste();
	
}

void CUMLEditorDemoView::OnEditDelete() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnEditDelete
	Description :	Handles the Delete-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Deletes all selected items.

   ============================================================*/
{

	m_editor.DeleteAllSelected();
	
}

void CUMLEditorDemoView::OnFlipLink() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnFlipLink
	Description :	Handles the Flip link-command from the 
					menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. If there is currently a 
					single line segment selected, the direction 
					of it is flipped.

   ============================================================*/
{

	m_editor.FlipLink();
	m_editor.RedrawWindow();

}

void CUMLEditorDemoView::OnProperty() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnProperty
	Description :	Handles the Property-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Shows the property dialog, 
					either for the selected object (if one and 
					only one selected) or the editor (all other 
					cases).

   ============================================================*/
{
	if( m_editor.GetSelectCount() == 1 )
		m_editor.ShowProperties();
	else
		OnButtonDisplayProperties();
}

void CUMLEditorDemoView::OnZoom100() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnZoom100
	Description :	Handles the Zoom 100%-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Zoom to this level.

   ============================================================*/
{

	m_editor.SetZoom( 1 );
	
}

void CUMLEditorDemoView::OnZoom150() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnZoom150
	Description :	Handles the Zoom 150%-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Zoom to this level.

   ============================================================*/
{

	m_editor.SetZoom( 1.5 );
	
}

void CUMLEditorDemoView::OnZoom200() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnZoom200
	Description :	Handles the Zoom 200%-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Zoom to this level.

   ============================================================*/
{

	m_editor.SetZoom( 2 );
	
}

void CUMLEditorDemoView::OnZoom25() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnZoom25
	Description :	Handles the Zoom 25%-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Zoom to this level.

   ============================================================*/
{

	m_editor.SetZoom( .25 );

}

void CUMLEditorDemoView::OnZoom50() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnZoom50
	Description :	Handles the Zoom 50%-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Zoom to this level.

   ============================================================*/
{

	m_editor.SetZoom( .5 );

}

void CUMLEditorDemoView::OnSnap() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnSnap
	Description :	Handles the Snap to grid-command from the 
					menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Sets or resets snap to grid 
					in the editor.

   ============================================================*/
{

	m_editor.SetSnapToGrid( !m_editor.GetSnapToGrid() );
	
}

void CUMLEditorDemoView::OnShowGrid() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnShowGrid
	Description :	Handles the Show/hide grid-command from 
					the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Shows or hides the editor 
					grid.

   ============================================================*/
{

	m_editor.ShowGrid( !m_editor.IsGridVisible() );
	
}

void CUMLEditorDemoView::OnImport() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnImport
	Description :	Handler for the Import-menu alternative.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Imports information from a 
					h-file to the currently selected object.

   ============================================================*/
{
	
	m_editor.Import();
	
}

void CUMLEditorDemoView::OnExport() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnExport
	Description :	Handles the Export-command from the menu.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC. Displays the Export dialog 
					and exports the editor contents to the 
					desired format.

   ============================================================*/
{

	// We save the current modified-state of 
	// the editor. The export mechanism 
	// modifies the data (although in a harmless 
	// way) and we want to reset the state 
	// after the operation - to avoid save 
	// questions when no conscious changes have 
	// been made.

	BOOL modified = m_editor.IsModified();

	CUMLEditorDemoDoc* doc = GetDocument();
	CExportDialog	dlg;
	dlg.m_onlyh = m_onlyh;
	if( dlg.DoModal() == IDOK )
	{
		CWaitCursor	wait;
		CString title = doc->GetTitle();
		int found = title.ReverseFind( _TCHAR( '.' ) );
		if( found != -1 )
			title = title.Left( found );
		switch( dlg.m_format )
		{
			case 0:
				m_editor.ExportEMF();
			break;
			case 1:
				m_editor.ExportHTML();
			break;
			case 2:
				m_editor.SetStripLeadingClassCharacter( dlg.m_strip );
				m_onlyh = dlg.m_onlyh;
				m_editor.ExportCPP( title, m_onlyh );
			break;
		}
	}

	m_editor.SetModified( modified );

}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoView update handlers

void CUMLEditorDemoView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateEditUndo
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{

	m_editor.UpdateUndo( pCmdUI );
	
}

void CUMLEditorDemoView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateEditCopy
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{

	m_editor.UpdateCopy( pCmdUI );
	
}

void CUMLEditorDemoView::OnUpdateEditCut(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateEditCut
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{

	m_editor.UpdateCut( pCmdUI );
	
}

void CUMLEditorDemoView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateEditPaste
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{

	m_editor.UpdatePaste( pCmdUI );
	
}

void CUMLEditorDemoView::OnUpdateFlipLink(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateFlipLink
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{
	
	pCmdUI->Enable( m_editor.IsLinkSelected() );
	
}

void CUMLEditorDemoView::OnUpdateSnap(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateSnap
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{
	pCmdUI->SetCheck( m_editor.GetSnapToGrid() );
	
}

void CUMLEditorDemoView::OnUpdateShowGrid(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateShowGrid
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{
	pCmdUI->SetCheck( m_editor.IsGridVisible() );
	
}

void CUMLEditorDemoView::OnUpdateImport(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateImport
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{

	BOOL	result = FALSE;

	if( m_editor.GetSelectCount() == 1 )
	{

		CUMLEntityClass* obj = dynamic_cast< CUMLEntityClass* >( m_editor.GetSelectedObject() );
		if( obj )
			result = TRUE;
	}

	pCmdUI->Enable( result );
	
}

void CUMLEditorDemoView::OnUpdateEditDelete(CCmdUI* pCmdUI) 
/* ============================================================
	Function :		CUMLEditorDemoView::OnUpdateEditDelete
	Description :	Command enabler.
	Access :		Protected.

	Return :		void
	Parameters :	CCmdUI* pCmdUI	-	Command enabler
					
	Usage :			Called from MFC.

   ============================================================*/
{

	pCmdUI->Enable( m_editor.GetSelectCount() );
	
}

void CUMLEditorDemoView::OnButtonTemplate() 
/* ============================================================
	Function :		CUMLEditorDemoView::OnButtonTemplate
	Description :	Handler for the dialog button Template
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Called from MFC.

   ============================================================*/
{

	CUMLEntityClassTemplate* obj = new CUMLEntityClassTemplate;
	m_editor.StartDrawingObject( obj );
	
}
void CUMLEditorDemoView::SetPreferredSize()
{
	CSize ts = m_editor.GetDiagramEntityContainer()->GetTotalSize();
	CPoint start = m_editor.GetDiagramEntityContainer()->GetStartPoint();
	m_DefaultSize = CSize(CSize(ts.cx + start.x*2, ts.cy + start.y*2));
	m_editor.SetVirtualSize(m_DefaultSize);
	m_editor.SetModified( FALSE );
}		
CSize CUMLEditorDemoView::GetPreferredSize(CSize )
{
	return m_DefaultSize;
}
void CUMLEditorDemoView::Scale(float scaleX,float )
{
	m_editor.SetZoom(scaleX);
}
