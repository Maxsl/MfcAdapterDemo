// UMLEditorDemoView.h : interface of the CUMLEditorDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UMLEDITORDEMOVIEW_H__63E4EB35_F4EC_429C_BCB2_479078E01003__INCLUDED_)
#define AFX_UMLEDITORDEMOVIEW_H__63E4EB35_F4EC_429C_BCB2_479078E01003__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UMLEditor/UMLEditor.h"
#include "LayoutView.h"


class CUMLEditorDemoView : public CLayoutView<CView>
{
protected:
	CUMLEditorDemoView();
	DECLARE_DYNCREATE(CUMLEditorDemoView)

// Attributes
public:
	CUMLEditorDemoDoc* GetDocument();

// Operations
public:

// Overrides
	//{{AFX_VIRTUAL(CUMLEditorDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUMLEditorDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUMLEditorDemoView)
	afx_msg void OnButtonClass();
	afx_msg void OnButtonLink();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnButtonNote();
	afx_msg void OnButtonPackage();
	afx_msg void OnButtonLabel();
	afx_msg void OnButtonInterface();
	afx_msg void OnButtonDisplayProperties();
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnExport();
	afx_msg void OnFlipLink();
	afx_msg void OnUpdateFlipLink(CCmdUI* pCmdUI);
	afx_msg void OnProperty();
	afx_msg void OnZoom100();
	afx_msg void OnZoom150();
	afx_msg void OnZoom200();
	afx_msg void OnZoom25();
	afx_msg void OnZoom50();
	afx_msg void OnSnap();
	afx_msg void OnUpdateSnap(CCmdUI* pCmdUI);
	afx_msg void OnShowGrid();
	afx_msg void OnUpdateShowGrid(CCmdUI* pCmdUI);
	afx_msg void OnImport();
	afx_msg void OnUpdateImport(CCmdUI* pCmdUI);
	afx_msg void OnEditDelete();
	afx_msg void OnUpdateEditDelete(CCmdUI* pCmdUI);
	afx_msg void OnButtonTemplate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//ICtrlLayout interface
public:
	virtual void SetPreferredSize();
	virtual CSize GetPreferredSize(CSize proposedSize);
	virtual void Scale(float scaleX,float scaleY);
private:
	BOOL		m_AutoSize;
	CSize		m_DefaultSize;

private:
	CUMLEditor	m_editor;
	int			m_screenResolutionX;
	BOOL		m_onlyh;
};

#ifndef _DEBUG  // debug version in UMLEditorDemoView.cpp
inline CUMLEditorDemoDoc* CUMLEditorDemoView::GetDocument()
   { return (CUMLEditorDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UMLEDITORDEMOVIEW_H__63E4EB35_F4EC_429C_BCB2_479078E01003__INCLUDED_)
