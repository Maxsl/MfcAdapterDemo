// SimpleScrollView.h : interface of the CSimpleScrollView class
//


#pragma once

#include "LayoutView.h"

class CSimpleScrollView :  public CLayoutView<CScrollView>
{
protected: // create from serialization only
	CSimpleScrollView();
	DECLARE_DYNCREATE(CSimpleScrollView)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnInitialUpdate();

// Implementation
public:
	virtual ~CSimpleScrollView();
//******AS update start**************************//
public:
	virtual void SetPreferredSize();
	virtual CSize GetPreferredSize(CSize proposedSize);
	virtual void Scale(float scaleX,float scaleY);
//******AS update end***************************//
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	CSimpleTestDoc* GetDocument() const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

//#ifndef _DEBUG  // debug version in SimpleScrollView.cpp
//inline CSimpleViewDoc* CSimpleScrollView::GetDocument() const
//   { return reinterpret_cast<CSimpleViewDoc*>(m_pDocument); }
//#endif

