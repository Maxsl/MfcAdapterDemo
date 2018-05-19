// RowListTemp.cpp : implementation file
//

#include "stdafx.h"
#include "RowListTemp.h"


// CRowListTemp

IMPLEMENT_DYNAMIC(CRowListTemp, CSingleDocTemplate)
CRowListTemp::CRowListTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)

 : CSingleDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

CRowListTemp::~CRowListTemp()
{
}

BEGIN_MESSAGE_MAP(CRowListTemp, CSingleDocTemplate)
END_MESSAGE_MAP()

CDocument* CRowListTemp::OpenDocumentFile(LPCTSTR lpszPathName,BOOL )
{
	// We make visible later
	CDocument* pDoc = CSingleDocTemplate::OpenDocumentFile(lpszPathName,FALSE);
	
	return pDoc;
}

