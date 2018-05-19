// NotifyHook.h
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/

#pragma once
#include "afxole.h"
#include "..\src\mfc\oleimpl2.h"
#include <stack>

class CNotifyHook : public COleFrameHook
{
private:
	// containers for disabled dialogs
	std::stack <HWND>	m_StackDisableDialog;
	std::stack <HWND>	m_StackFocus;
	
	HWND				m_hExternFrameHwnd;
	BOOL				m_IsExternEnable;
	HWND*				m_phWndDisable;       // disabled ExternFrame windows  
public:
	CNotifyHook(CFrameWnd* pFrameWnd,const HWND hExternFrameHwnd);

// Overrides
	virtual void OnEnableModeless(BOOL bEnable);

// Implementation
public:
	virtual ~CNotifyHook();
};

