// NotifyHook.cpp : implementation file
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/

//
// We use COleFrameHook interface for communucation with external framework.

#include "stdafx.h"
#include "NotifyHook.h"
#include "afxpriv.h"
#include "..\src\mfc\afximpl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotifyHook construction/destruction

CNotifyHook::CNotifyHook(CFrameWnd* pFrameWnd,const HWND hExternFrameHwnd):COleFrameHook(pFrameWnd, new COleClientItem)
{
	m_hExternFrameHwnd = hExternFrameHwnd;
}

CNotifyHook::~CNotifyHook()
{
	delete m_pActiveItem;
}
/////////////////////////////////////////////////////////////////////////////
// CNotifyHook methods
//
// We overwrite this methods for modal dialogs support by MFC application hosting
void CNotifyHook::OnEnableModeless(BOOL bEnable)
{		
	CWinApp* pApp = AfxGetApp(); 
	if(bEnable)
	{
		HWND hDialogWnd = NULL;
		// Enable last dialog
		if (m_StackDisableDialog.size()>0)
		{
			hDialogWnd = m_StackDisableDialog.top( );
			m_StackDisableDialog.pop();
			if (::IsWindow(hDialogWnd))
			{
				::EnableWindow(hDialogWnd, TRUE);
				TRACE(traceAppMsg, 0, "Enable Dialog, hDialogWnd=%x StackSize=%x\n", hDialogWnd, m_StackDisableDialog.size());
			}
		}
		// Enable Framework windows
		else if (m_StackDisableDialog.size()== NULL && m_IsExternEnable==FALSE)
		{
			m_IsExternEnable = TRUE;

			// enable all the windows disabled by BeginModalState
			ASSERT(m_phWndDisable != NULL);
			UINT nIndex = 0;
			while (m_phWndDisable[nIndex] != NULL)
			{
				ASSERT(m_phWndDisable[nIndex] != NULL);
				if (::IsWindow(m_phWndDisable[nIndex]))
				{
					::EnableWindow(m_phWndDisable[nIndex], TRUE);
				}
				++nIndex;
			}
			delete[] (void*)m_phWndDisable;
			m_phWndDisable = NULL;

		}
		
		HWND hFocusWnd = m_StackFocus.top( );
		m_StackFocus.pop();
		SetFocus(hFocusWnd);
	}
	else // disable 
	{
		// MessageBox or Modal Dialog can have Legacy MainWnd or Framework MainForm 
		// As TopLevelParent

		HWND hFocusWnd = CWnd::GetFocus()->GetSafeHwnd();
		m_StackFocus.push(hFocusWnd);
	
		// try to find not disabled Legacy MainWnd child wnd, disable it and add to the list
		CWnd* pParent = pApp->GetMainWnd()->GetTopLevelParent();

		HWND hWnd = ::GetWindow(::GetDesktopWindow(), GW_CHILD);
		while (hWnd != NULL)
		{
			if (::IsWindowEnabled(hWnd) &&
				CWnd::FromHandlePermanent(hWnd) != NULL &&
				AfxIsDescendant(pParent->m_hWnd, hWnd) &&
				::SendMessage(hWnd, WM_DISABLEMODAL, 0, 0) == 0 &&
				hWnd!=pParent->m_hWnd)
			{
				::EnableWindow(hWnd, FALSE);
				m_StackDisableDialog.push(hWnd);
				TRACE(traceAppMsg, 0, "Disable Legacy Dialog, hWnd=%x StackSize=%x \n", hWnd, m_StackDisableDialog.size());
				break;
			}
			hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
		}
		
		// if this is the first disable by stack - disable all childs from Framework MainForm
		// we use MFC code for this:
		if(m_IsExternEnable)
		{
			// first count all windows that need to be disabled
			UINT nCount = 0;
			HWND hWnd = ::GetWindow(::GetDesktopWindow(), GW_CHILD);
			while (hWnd != NULL)
			{
				if (::IsWindowEnabled(hWnd) &&
					//CWnd::FromHandlePermanent(hWnd) != NULL &&
					AfxIsDescendant(m_hExternFrameHwnd, hWnd) &&
					::SendMessage(hWnd, WM_DISABLEMODAL, 0, 0) == 0)
				{
					++nCount;
				}
				hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
			}
			if (nCount == 0)
				return;

			m_phWndDisable = new HWND[nCount+1];

			// disable all windows connected to this frame (and add them to the list)
			UINT nIndex = 0;
			hWnd = ::GetWindow(::GetDesktopWindow(), GW_CHILD);
			while (hWnd != NULL)
			{
				if (::IsWindowEnabled(hWnd) &&
					//CWnd::FromHandlePermanent(hWnd) != NULL &&
					AfxIsDescendant(m_hExternFrameHwnd, hWnd) &&
					::SendMessage(hWnd, WM_DISABLEMODAL, 0, 0) == 0)
				{
					::EnableWindow(hWnd, FALSE);
					ASSERT(nIndex < nCount);
					m_phWndDisable[nIndex] = hWnd;
					++nIndex;
				}
				hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
			}

			// terminate the list with a NULL
			ASSERT(nIndex < nCount+1);
			m_phWndDisable[nIndex] = NULL;
			m_IsExternEnable = FALSE;
		}
		else //m_IsExternEnable == FALSE
		{
			// try to find not disabled Framework MainForm child wnd, disable it and add to the list
			hWnd = ::GetWindow(::GetDesktopWindow(), GW_CHILD);
			while (hWnd != NULL)
			{
				if (::IsWindowEnabled(hWnd) &&
				//CWnd::FromHandlePermanent(hWnd) != NULL &&
				AfxIsDescendant(m_hExternFrameHwnd, hWnd) &&
				::SendMessage(hWnd, WM_DISABLEMODAL, 0, 0) == 0 &&
				::IsWindowVisible(hWnd))
				{
					::EnableWindow(hWnd, FALSE);
					m_StackDisableDialog.push(hWnd);
					TRACE(traceAppMsg, 0, "Disable Framework dialog, hWnd=%x StackSize=%x \n", hWnd, m_StackDisableDialog.size());
				}
				hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
			}
		}
	}
}


