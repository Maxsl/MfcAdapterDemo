#pragma once


// CSimpleTestTemp

class CSimpleTestTemp : public CMultiDocTemplate
{
	DECLARE_DYNAMIC(CSimpleTestTemp)

public:
	CSimpleTestTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
	virtual ~CSimpleTestTemp();
	HWND CreateView(int nID);
// Overrides
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName,BOOL bMakeVisible = TRUE);
protected:
	DECLARE_MESSAGE_MAP()
};


