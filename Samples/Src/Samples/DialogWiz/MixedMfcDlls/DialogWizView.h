// DialogWizView.h : interface of the CDialogWizView class
//


#pragma once


class CDialogWizView : public CView
{
protected: // create from serialization only
	CDialogWizView();
	DECLARE_DYNCREATE(CDialogWizView)

// Attributes
public:
	CDialogWizDoc* GetDocument() const;

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
	virtual ~CDialogWizView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DialogWizView.cpp
inline CDialogWizDoc* CDialogWizView::GetDocument() const
   { return reinterpret_cast<CDialogWizDoc*>(m_pDocument); }
#endif

