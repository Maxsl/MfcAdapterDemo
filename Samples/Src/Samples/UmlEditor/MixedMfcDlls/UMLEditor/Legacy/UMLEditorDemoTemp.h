#pragma once


// CUMLEditorDemoTemp

class CUMLEditorDemoTemp : public CMultiDocTemplate
{
	DECLARE_DYNAMIC(CUMLEditorDemoTemp)

public:
	CUMLEditorDemoTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
	virtual ~CUMLEditorDemoTemp();
	HWND CreateView(int nID);
protected:
// Overrides
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName,BOOL bMakeVisible = TRUE);
	DECLARE_MESSAGE_MAP()
};


