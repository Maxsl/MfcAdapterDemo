/* ==========================================================================
	Class :			CUMLEditorDemoDoc

	Author :		Johan Rosengren, Abstrakt Mekanik AB

	Date :			2004-06-20

	Purpose :		"CUMLEditorDemoDoc", derived from "CDocument", is the 
					data container class for the application.

	Description :	See the MFC documentation for "CDocument"-specifics.
					Several members are modified to use a 
					"CUMLEntityContainer" as the data class.

	Usage :			Created by MFC.

   ========================================================================*/
//******AS update start**************************//
//	Updated Alexey Shalnov for Hosting in .NET application
//******AS update end****************************//

#include "stdafx.h"
#include "UMLEditorDemo.h"

#include "UMLEditorDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoDoc

IMPLEMENT_DYNCREATE(CUMLEditorDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CUMLEditorDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CUMLEditorDemoDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoDoc construction/destruction

CUMLEditorDemoDoc::CUMLEditorDemoDoc()
/* ============================================================
	Function :		CUMLEditorDemoDoc::CUMLEditorDemoDoc
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Created by MFC

   ============================================================*/
{

	m_objs.SetClipboardHandler( &theApp.m_clip );

}

CUMLEditorDemoDoc::~CUMLEditorDemoDoc()
/* ============================================================
	Function :		CUMLEditorDemoDoc::~CUMLEditorDemoDoc
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Don't delete this object.

   ============================================================*/
{
}

BOOL CUMLEditorDemoDoc::OnNewDocument()
/* ============================================================
	Function :		CUMLEditorDemoDoc::OnNewDocument
	Description :	Called when a new document is created.
	Access :		Public

	Return :		BOOL	-	"TRUE" if ok.
	Parameters :	none

	Usage :			Called from MFC. We clear the internal 
					data container.

   ============================================================*/
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_objs.Clear();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoDoc serialization

void CUMLEditorDemoDoc::Serialize(CArchive& ar)
/* ============================================================
	Function :		CUMLEditorDemoDoc::Serialize
	Description :	Save-function.
	Access :		Public

	Return :		void
	Parameters :	CArchive& ar	-	"CArchive" to save to.
					
	Usage :			Called from MFC. We save/load information 
					to the data container.

   ============================================================*/
{
	if (ar.IsStoring())
		m_objs.Save( ar );
	else
		m_objs.Load( ar );
}

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoDoc diagnostics

#ifdef _DEBUG
void CUMLEditorDemoDoc::AssertValid() const
/* ============================================================
	Function :		CUMLEditorDemoDoc::AssertValid
	Description :	Asserts the validity of the current object.
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Diagnostics function.

   ============================================================*/
{
	CDocument::AssertValid();
}

void CUMLEditorDemoDoc::Dump(CDumpContext& dc) const
/* ============================================================
	Function :		CUMLEditorDemoDoc::Dump
	Description :	Dumps the current object state.
	Access :		Public

	Return :		void
	Parameters :	CDumpContext& dc	-	Not used
					
	Usage :			Diagnostics function.

   ============================================================*/
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUMLEditorDemoDoc commands

BOOL CUMLEditorDemoDoc::SaveModified() 
/* ============================================================
	Function :		CUMLEditorDemoDoc::SaveModified
	Description :	Called before a check is made to see if 
					the data is modified.
	Access :		Public

	Return :		BOOL	-	From the framework
	Parameters :	none

	Usage :			We set the modified-flag from the data 
					container.

   ============================================================*/
{

	SetModifiedFlag( m_objs.IsModified() );
	return CDocument::SaveModified();

}

CUMLEntityContainer* CUMLEditorDemoDoc::GetData()
/* ============================================================
	Function :		CUMLEditorDemoDoc::GetData
	Description :	Accessor for the internal data container.
	Access :		Public

	Return :		CUMLEntityContainer*	-	A pointer to the 
												data container.
	Parameters :	none

	Usage :			Call to get a pointer to the data.

   ============================================================*/
{

	return &m_objs;

}
//******AS update start**************************//
void CUMLEditorDemoDoc::SetModifiedFlag(BOOL bModified)
{
	m_objs.SetModified(bModified);
	CDocument::SetModifiedFlag(bModified);
}
//******AS update end****************************//
