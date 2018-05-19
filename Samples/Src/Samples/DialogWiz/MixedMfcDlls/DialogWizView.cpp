// DialogWizView.cpp : implementation of the CDialogWizView class
//

#include "stdafx.h"
#include "DialogWiz.h"

#include "DialogWizDoc.h"
#include "DialogWizView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogWizView

IMPLEMENT_DYNCREATE(CDialogWizView, CView)

BEGIN_MESSAGE_MAP(CDialogWizView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDialogWizView construction/destruction

CDialogWizView::CDialogWizView()
{
	// TODO: add construction code here

}

CDialogWizView::~CDialogWizView()
{
}

BOOL CDialogWizView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDialogWizView drawing

void CDialogWizView::OnDraw(CDC* /*pDC*/)
{
	CDialogWizDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDialogWizView printing

BOOL CDialogWizView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDialogWizView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDialogWizView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDialogWizView diagnostics

#ifdef _DEBUG
void CDialogWizView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogWizView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogWizDoc* CDialogWizView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogWizDoc)));
	return (CDialogWizDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialogWizView message handlers
