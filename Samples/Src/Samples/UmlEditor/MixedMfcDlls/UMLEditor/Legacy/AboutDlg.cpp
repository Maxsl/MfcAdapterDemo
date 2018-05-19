/* ==========================================================================
	Class :			CAboutDlg

	Author :		Johan Rosengren, Abstrakt Mekanik AB

	Date :			2004-06-21

	Purpose :		"CAboutDlg" derives from "CDialog" and is a wrapper for 
					the About dialog.

	Description :	A standard Wizard-generated dialog box class.

	Usage :			Instantiated from the application class.

   ========================================================================*/
#include "StdAfx.h"
#include "AboutDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
/* ============================================================
	Function :		CAboutDlg::CAboutDlg
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Created by MFC

   ============================================================*/
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
/* ============================================================
	Function :		CAboutDlg::DoDataExchange
	Description :	Data-exchange handler.
	Access :		Protected

	Return :		void
	Parameters :	CDataExchange* pDX	-	Pointer to exchange object
					
	Usage :			Called from MFC to exchange and validate 
					dialog data.

   ============================================================*/
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

