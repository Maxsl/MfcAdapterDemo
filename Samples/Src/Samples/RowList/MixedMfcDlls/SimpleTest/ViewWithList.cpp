// ViewWithList.cpp : implementation of the CViewWithList class
//

#include "stdafx.h"
#include "SimpleTest.h"

#include "SimpleTestDoc.h"
#include "ViewWithList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// data for the list view control

#define NUM_COLUMNS 5
#define NUM_ITEMS   3

static _TCHAR *_gszColumnLabel[NUM_COLUMNS] =
{
	_T("Name"), _T("Title"), _T("Department"), _T("Telephone"), _T("E-mail")
};

static int _gnColumnFmt[NUM_COLUMNS] =
{
	LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT
};

static int _gnColumnWidth[NUM_COLUMNS] =
{
	150, 150, 150, 100, 100
};

static _TCHAR *_gszItem[NUM_ITEMS][NUM_COLUMNS] =
{
	_T("Jossef Goldberg"),  _T("President & CEO"), _T("Department Office of the President"), _T("555-0100"),   _T("jossef@championzone.net"),
	_T("Suzan Fine"),  _T("Executive Assistant"), _T("Department Office of the President"), _T("555-0101"),   _T("suzan@championzone.net"),
	_T("Clair Hector"),  _T("COO"), _T("Operations"), _T("555-0102"),   _T("clair@championzone.net"),
};

/////////////////////////////////////////////////////////////////////////////
// CViewWithList

IMPLEMENT_DYNCREATE(CViewWithList, CView)

BEGIN_MESSAGE_MAP(CViewWithList, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CViewWithList construction/destruction

CViewWithList::CViewWithList()
{
	// TODO: add construction code here

}

CViewWithList::~CViewWithList()
{
}

BOOL CViewWithList::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CViewWithList drawing

void CViewWithList::OnDraw(CDC* /*pDC*/)
{
	//CSimpleTestDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	// TODO: add draw code for native data here
}


// CViewWithList printing

BOOL CViewWithList::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CViewWithList::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CViewWithList::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CViewWithList::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	if(m_ListCtrl.m_hWnd!=NULL)
	{
		CRect r;
		GetClientRect(r);
		m_ListCtrl.SetWindowPos (&wndTop,0,0,r.right,r.bottom ,SWP_SHOWWINDOW);
	}
}

void CViewWithList::OnInitialUpdate() 
{
	m_ListCtrl.Create( LVS_REPORT | LVS_SHOWSELALWAYS | LBS_NOTIFY, CRect(0,0,400,200), this, IDC_LISTCTRL );
	m_ListCtrl.SetExtendedStyle(LVS_EX_FLATSB  | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );		

	CFont fArial;
	fArial.CreatePointFont (100,_T("System"));
	m_ListCtrl.SetFont(&fArial);

	CView::OnInitialUpdate();
	
	// insert columns
	int i, j;
	LV_COLUMN lvc;

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

	for(i = 0; i<NUM_COLUMNS; i++)
	{
		lvc.iSubItem = i;
		lvc.pszText = _gszColumnLabel[i];
		lvc.cx = _gnColumnWidth[i];
		lvc.fmt = _gnColumnFmt[i];
		m_ListCtrl.InsertColumn(i,&lvc);
	}

    // insert items
	LV_ITEM lvi;

	for(i = 0; i < NUM_ITEMS; i++)
	{
		lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
		lvi.iItem = i;
		lvi.iSubItem = 0;
		lvi.pszText = _gszItem[i][0];
		lvi.iImage = i;
		lvi.stateMask = LVIS_STATEIMAGEMASK;
		lvi.state = INDEXTOSTATEIMAGEMASK(1);

		m_ListCtrl.InsertItem(&lvi);
	}

	// set item text for additional columns
	for(i = 0; i<NUM_ITEMS; i++)
	{
		for(j = 1; j<NUM_COLUMNS; j++)
		{
			m_ListCtrl.SetItemText(i,j,_gszItem[i][j]);
		}
	}

}

void CViewWithList::SetPreferredSize()
{
}		
CSize CViewWithList::GetPreferredSize(CSize )
{
	return CSize(300,300);
}
void CViewWithList::Scale(float scaleX,float )
{
}
// CViewWithList diagnostics

#ifdef _DEBUG
void CViewWithList::AssertValid() const
{
	CView::AssertValid();
}

void CViewWithList::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimpleTestDoc* CViewWithList::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimpleTestDoc)));
	return (CSimpleTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CViewWithList message handlers
