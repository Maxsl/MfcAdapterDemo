#pragma once


// CRowListTemp

class CRowListTemp : public CSingleDocTemplate
{
	DECLARE_DYNAMIC(CRowListTemp)

public:
	CRowListTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
	virtual ~CRowListTemp();
	HWND CreateView(int nID);
// Overrides
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName,BOOL bMakeVisible = TRUE);
protected:
	DECLARE_MESSAGE_MAP()
};


