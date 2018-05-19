// SimpleTestTemp.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleTestTemp.h"


// CSimpleTestTemp

IMPLEMENT_DYNAMIC(CSimpleTestTemp, CMultiDocTemplate)
CSimpleTestTemp::CSimpleTestTemp(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)

 : CMultiDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

CSimpleTestTemp::~CSimpleTestTemp()
{
}

BEGIN_MESSAGE_MAP(CSimpleTestTemp, CMultiDocTemplate)
END_MESSAGE_MAP()

CDocument* CSimpleTestTemp::OpenDocumentFile(LPCTSTR lpszPathName,BOOL )
{
	// We make visible later
	CDocument* pDoc = CMultiDocTemplate::OpenDocumentFile(lpszPathName,FALSE);
	
	return pDoc;
}

