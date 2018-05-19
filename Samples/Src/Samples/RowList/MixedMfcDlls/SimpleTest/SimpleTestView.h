// SimpleTestView.h : interface of the CSimpleTestView class
//


#pragma once


class CSimpleTestView : public CView
{
protected: // create from serialization only
	CSimpleTestView();
	DECLARE_DYNCREATE(CSimpleTestView)

// Attributes
//public:

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

// Implementation
public:
	virtual ~CSimpleTestView();
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

//#ifndef _DEBUG  // debug version in SimpleTestView.cpp
//inline CSimpleTestDoc* CSimpleTestView::GetDocument() const
//   { return reinterpret_cast<CSimpleTestDoc*>(m_pDocument); }
//#endif

