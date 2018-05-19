// DialogWizDoc.h : interface of the CDialogWizDoc class
//


#pragma once


class CDialogWizDoc : public CDocument
{
protected: // create from serialization only
	CDialogWizDoc();
	DECLARE_DYNCREATE(CDialogWizDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CDialogWizDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


