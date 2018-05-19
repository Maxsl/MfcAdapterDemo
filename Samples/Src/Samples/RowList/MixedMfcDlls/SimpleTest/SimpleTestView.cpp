// SimpleTestView.cpp : implementation of the CSimpleTestView class
//

#include "stdafx.h"
#include "SimpleTest.h"

#include "SimpleTestDoc.h"
#include "SimpleTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleTestView

IMPLEMENT_DYNCREATE(CSimpleTestView, CView)

BEGIN_MESSAGE_MAP(CSimpleTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSimpleTestView construction/destruction

CSimpleTestView::CSimpleTestView()
{
	// TODO: add construction code here

}

CSimpleTestView::~CSimpleTestView()
{
}

BOOL CSimpleTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSimpleTestView drawing

void CSimpleTestView::OnDraw(CDC* /*pDC*/)
{
	//CSimpleTestDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	// TODO: add draw code for native data here
}


// CSimpleTestView printing

BOOL CSimpleTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSimpleTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSimpleTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSimpleTestView diagnostics

#ifdef _DEBUG
void CSimpleTestView::AssertValid() const
{
	CView::AssertValid();
}

void CSimpleTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimpleTestDoc* CSimpleTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimpleTestDoc)));
	return (CSimpleTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSimpleTestView message handlers
