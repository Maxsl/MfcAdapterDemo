// ViewWithList.h : interface of the CViewWithList class
//


#pragma once

#include "LayoutView.h"

class CViewWithList : public CLayoutView<CView>
{
private:
	CListCtrl	m_ListCtrl;


protected: // create from serialization only
	CViewWithList();
	DECLARE_DYNCREATE(CViewWithList)

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
	virtual ~CViewWithList();
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
	//{{AFX_MSG(CViewWithList)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//#ifndef _DEBUG  // debug version in ViewWithList.cpp
//inline CSimpleTestDoc* CViewWithList::GetDocument() const
//   { return reinterpret_cast<CSimpleTestDoc*>(m_pDocument); }
//#endif

