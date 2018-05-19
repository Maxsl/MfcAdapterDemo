// UMLEditorDemoDoc.h : interface of the CUMLEditorDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UMLEDITORDEMODOC_H__8555AC91_6659_4FD5_9FBD_61FB948BAB0C__INCLUDED_)
#define AFX_UMLEDITORDEMODOC_H__8555AC91_6659_4FD5_9FBD_61FB948BAB0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UMLEditor/UMLEntityContainer.h"

class CUMLEditorDemoDoc : public CDocument
{
protected:
	CUMLEditorDemoDoc();
	DECLARE_DYNCREATE(CUMLEditorDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	//{{AFX_VIRTUAL(CUMLEditorDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	protected:
	virtual BOOL SaveModified();
//******AS update start**************************//
	virtual void SetModifiedFlag(BOOL bModified = TRUE);
//******AS update end****************************//

	//}}AFX_VIRTUAL

// Implementation
public:
	CUMLEntityContainer* GetData();
	virtual ~CUMLEditorDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUMLEditorDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CUMLEntityContainer m_objs;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UMLEDITORDEMODOC_H__8555AC91_6659_4FD5_9FBD_61FB948BAB0C__INCLUDED_)
