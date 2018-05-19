// UMLEditorDemoTemp.cpp : implementation file
//

#include "stdafx.h"
#include "UMLEditorDemoTemp.h"


// CUMLEditorDemoTemp

IMPLEMENT_DYNAMIC(CUMLEditorDemoTemp, CMultiDocTemplate)
CUMLEditorDemoTemp::CUMLEditorDemoTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)

 : CMultiDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

CUMLEditorDemoTemp::~CUMLEditorDemoTemp()
{
}

BEGIN_MESSAGE_MAP(CUMLEditorDemoTemp, CMultiDocTemplate)
END_MESSAGE_MAP()

CDocument* CUMLEditorDemoTemp::OpenDocumentFile(LPCTSTR lpszPathName,BOOL )
{
	// We make visible later
	CDocument* pDoc = CMultiDocTemplate::OpenDocumentFile(lpszPathName,FALSE);
	
	return pDoc;
}

