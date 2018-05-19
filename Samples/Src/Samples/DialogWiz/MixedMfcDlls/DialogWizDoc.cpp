// DialogWizDoc.cpp : implementation of the CDialogWizDoc class
//

#include "stdafx.h"
#include "DialogWiz.h"

#include "DialogWizDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogWizDoc

IMPLEMENT_DYNCREATE(CDialogWizDoc, CDocument)

BEGIN_MESSAGE_MAP(CDialogWizDoc, CDocument)
END_MESSAGE_MAP()


// CDialogWizDoc construction/destruction

CDialogWizDoc::CDialogWizDoc()
{
	// TODO: add one-time construction code here

}

CDialogWizDoc::~CDialogWizDoc()
{
}

BOOL CDialogWizDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDialogWizDoc serialization

void CDialogWizDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CDialogWizDoc diagnostics

#ifdef _DEBUG
void CDialogWizDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDialogWizDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDialogWizDoc commands
