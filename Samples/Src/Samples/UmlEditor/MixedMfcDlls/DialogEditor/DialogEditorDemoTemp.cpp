// UMLEditorDemoTemp.cpp : implementation file
//

#include "stdafx.h"
#include "DialogEditorDemoTemp.h"


// CDialogEditorDemoTemp

IMPLEMENT_DYNAMIC(CDialogEditorDemoTemp, CSingleDocTemplate)
CDialogEditorDemoTemp::CDialogEditorDemoTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)

 : CSingleDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

CDialogEditorDemoTemp::~CDialogEditorDemoTemp()
{
}

BEGIN_MESSAGE_MAP(CDialogEditorDemoTemp, CSingleDocTemplate)
END_MESSAGE_MAP()

CDocument* CDialogEditorDemoTemp::OpenDocumentFile(LPCTSTR lpszPathName,BOOL )
{
	// We make visible later
	CDocument* pDoc = CSingleDocTemplate::OpenDocumentFile(lpszPathName,FALSE);
	
	return pDoc;
}

