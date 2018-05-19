#pragma once


// CDialogEditorDemoTemp

class CDialogEditorDemoTemp : public CSingleDocTemplate
{
	DECLARE_DYNAMIC(CDialogEditorDemoTemp)

public:
	CDialogEditorDemoTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
	virtual ~CDialogEditorDemoTemp();
	HWND CreateView(int nID);
protected:
// Overrides
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName,BOOL bMakeVisible = TRUE);
	DECLARE_MESSAGE_MAP()
};


