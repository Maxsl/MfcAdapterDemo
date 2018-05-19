// SimpleScrollView.cpp : implementation of the CSimpleScrollView class
//

#include "stdafx.h"
#include "SimpleTest.h"

#include "SimpleTestDoc.h"
#include "SimpleScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleScrollView

IMPLEMENT_DYNCREATE(CSimpleScrollView, CScrollView)

BEGIN_MESSAGE_MAP(CSimpleScrollView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSimpleScrollView construction/destruction

CSimpleScrollView::CSimpleScrollView()
{
	// TODO: add construction code here

}

CSimpleScrollView::~CSimpleScrollView()
{
}

BOOL CSimpleScrollView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSimpleScrollView drawing

void CSimpleScrollView::OnDraw(CDC* pDC)
{
	//CSimpleTestDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

   // create and select a solid blue brush
   CBrush brushBlue(RGB(0, 0, 255));
   CBrush* pOldBrush = pDC->SelectObject(&brushBlue);

   // create and select a thick, black pen
   CPen penBlack;
   penBlack.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
   CPen* pOldPen = pDC->SelectObject(&penBlack);

   // get our client rectangle
   CRect rect = CRect(0,0,300,300);
   //GetClientRect(rect);

   // shrink our rect 20 pixels in each direction
   rect.DeflateRect(20, 20);

   // draw a thick black rectangle filled with blue
   pDC->Rectangle(rect);

   // put back the old objects
   pDC->SelectObject(pOldBrush);
   pDC->SelectObject(pOldPen);
}

void CSimpleScrollView::OnInitialUpdate()
{
	SetScrollSizes(MM_TEXT, CSize(500,600));
	
	CScrollView::OnInitialUpdate();
}

void CSimpleScrollView::SetPreferredSize()
{
}		
CSize CSimpleScrollView::GetPreferredSize(CSize )
{
	return CSize(300,300);
}
void CSimpleScrollView::Scale(float scaleX,float )
{
}
// CSimpleScrollView printing

BOOL CSimpleScrollView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSimpleScrollView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSimpleScrollView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSimpleScrollView diagnostics

#ifdef _DEBUG
void CSimpleScrollView::AssertValid() const
{
	CView::AssertValid();
}

void CSimpleScrollView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimpleTestDoc* CSimpleScrollView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimpleTestDoc)));
	return (CSimpleTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSimpleScrollView message handlers
