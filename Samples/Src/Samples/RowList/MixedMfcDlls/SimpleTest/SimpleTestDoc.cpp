// SimpleTestDoc.cpp : implementation of the CSimpleTestDoc class
//

#include "stdafx.h"
#include "SimpleTest.h"

#include "SimpleTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleTestDoc

IMPLEMENT_DYNCREATE(CSimpleTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSimpleTestDoc, CDocument)
END_MESSAGE_MAP()


// CSimpleTestDoc construction/destruction

CSimpleTestDoc::CSimpleTestDoc()
{
	// TODO: add one-time construction code here

}

CSimpleTestDoc::~CSimpleTestDoc()
{
}

BOOL CSimpleTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSimpleTestDoc serialization

void CSimpleTestDoc::Serialize(CArchive& ar)
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


// CSimpleTestDoc diagnostics

#ifdef _DEBUG
void CSimpleTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSimpleTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSimpleTestDoc commands
