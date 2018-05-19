//IApplication.h
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/

// Interface to hosted MFC Application from extern Framework  
#pragma once
class CHostApp: public CWinApp
{
	protected:
		HWND   m_hFrameworkWnd;
		CWnd*  m_pCreatedWnd;
	public:
		HWND GetFrameworkWnd(){return m_hFrameworkWnd;}
		CWnd* GetCreatedWnd(){return m_pCreatedWnd;}

		// get Framework main window handle
		virtual BOOL AttachApplication(HWND hFrameworkWnd)=0;
		virtual BOOL DetachApplication()=0;

};
