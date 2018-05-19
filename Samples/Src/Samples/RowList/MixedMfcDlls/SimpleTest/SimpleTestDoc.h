// SimpleTestDoc.h : interface of the CSimpleTestDoc class
//


#pragma once


class CSimpleTestDoc : public CDocument
{
protected: // create from serialization only
	CSimpleTestDoc();
	DECLARE_DYNCREATE(CSimpleTestDoc)

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
	virtual ~CSimpleTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


