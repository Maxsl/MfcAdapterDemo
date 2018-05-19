// MfcCommand.cpp
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/

// Coomand ID which could be handled by MfcAppAdapter
#pragma once
#include "stdafx.h"				
#include <afxres.h>			// MFC core and standard components
#include "Resource.h"		

namespace AS
{
	namespace RowList
	{
		/// <summary>
		/// Managed pointer to AMF_MODULE_STATE of this MFC application
		/// </summary>
		/// <remarks>
		/// This is the accessor class for external Managed or Mixed components.
		/// Mfc application can be hosted in WinForms/WPF, if it has minimum one manage class - "ModuleState" 
		/// in root Namespace. 
		/// </remarks>
		public ref class ModuleState
		{
			public:
				/// <summary>
				/// Get Managed pointer to AMF_MODULE_STATE of this MFC application
				/// </summary>
				/// <example> This sample shows how to cast ModuleState to unmanaged AFX_MODULE_STATE:
				/// <code>
				///   AFX_MODULE_STATE* moduleState = 
				///		  static_cast&lt;AFX_MODULE_STATE*&gt;(m_MfcAppAdapter->GetModuleState().ToPointer()); 
				/// </code>
				/// </example>
				static System::IntPtr GetModuleState()
				{
					return (System::IntPtr)AfxGetStaticModuleState();
				};
				static bool AppIdle()
				{
					AFX_MANAGE_STATE(AfxGetStaticModuleState());
					return ::AfxGetApp()->OnIdle(0)==TRUE;
				}
	};
		public enum class MfcCommand
		{
			None					= 0,
			
			APP_ABOUT				= ID_APP_ABOUT,
			APP_EXIT				= ID_APP_EXIT,
			
			EDIT_UNDO				= ID_EDIT_UNDO, 
			EDIT_REDO				= ID_EDIT_REDO, 
			EDIT_CUT				= ID_EDIT_CUT,
			EDIT_COPY				= ID_EDIT_COPY,
			EDIT_PASTE				= ID_EDIT_PASTE,
			EDIT_GROUP				= 57645,
			EDIT_UNGROUP			= 57646,
			
			FILE_PRINT_SETUP		= ID_FILE_PRINT_SETUP,
			FILE_PRINT_PREVIEW		= ID_FILE_PRINT_PREVIEW,
			FILE_PRINT				= ID_FILE_PRINT,
			FILE_SAVE_AS			= ID_FILE_SAVE_AS,
			FILE_SAVE				= ID_FILE_SAVE,
			FILE_NEW				= ID_FILE_NEW,
			FILE_OPEN				= ID_FILE_OPEN,
			FILE_CLOSE				= ID_FILE_CLOSE,
			FILE_MRU_FIRST			= ID_FILE_MRU_FIRST,
			FILE_MRU_FILE1			= ID_FILE_MRU_FILE1,
			FILE_MRU_FILE2			= ID_FILE_MRU_FILE2,
			FILE_MRU_FILE3			= ID_FILE_MRU_FILE3,
			FILE_MRU_FILE4			= ID_FILE_MRU_FILE4,
			FILE_MRU_FILE5			= ID_FILE_MRU_FILE5,
			FILE_MRU_FILE6			= ID_FILE_MRU_FILE6,
			FILE_MRU_FILE7			= ID_FILE_MRU_FILE7,
			FILE_MRU_FILE8			= ID_FILE_MRU_FILE8,
			FILE_MRU_FILE9			= ID_FILE_MRU_FILE9,
			FILE_MRU_FILE10			= ID_FILE_MRU_FILE10,
			FILE_MRU_FILE11			= ID_FILE_MRU_FILE11,
			FILE_MRU_FILE12			= ID_FILE_MRU_FILE12,
			FILE_MRU_FILE13			= ID_FILE_MRU_FILE13,
			FILE_MRU_FILE14			= ID_FILE_MRU_FILE14,
			FILE_MRU_FILE15			= ID_FILE_MRU_FILE15,
			FILE_MRU_FILE16			= ID_FILE_MRU_FILE16,
			FILE_MRU_LAST			= ID_FILE_MRU_LAST,
			
			VIEW_TOOLBAR			= ID_VIEW_TOOLBAR,
			WINDOW_NEW				= ID_WINDOW_NEW,
			WINDOW_ARRANGE			= ID_WINDOW_ARRANGE,
			WINDOW_CASCADE			= ID_WINDOW_CASCADE,
			WINDOW_TILE_HORZ		= ID_WINDOW_TILE_HORZ,
			WINDOW_TILE_VERT		= ID_WINDOW_TILE_VERT,

			VIEW_DETAILSMODE		= ID_VIEW_DETAILS,
			VIEW_CLIENTWIDTHSEL		= ID_VIEW_CLIENTWIDTHSEL,
			VIEW_LISTMODE 			= ID_VIEW_LIST,
			VIEW_ROWDETAILS			= ID_VIEW_ROWDETAILS,
			VIEW_LICONS				= ID_VIEW_LARGEICONS,
			VIEW_SICONS			= ID_VIEW_SMALLICONS
		};
	}
}
