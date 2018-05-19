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
#include <afxres.h>				// MFC core and standard components
#include "Resource.h"		// Used by UMLEditorDemo.rc

namespace AS
{
	namespace WrlViewer
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
		};
		public enum class MfcCommand
		{
			None				= 0,
			ADD_WIREFRAME		= ID_GL_ADD_WIREFRAME,
			SMOOTH				= ID_GL_SMOOTH,
			MESH_LOOP			= ID_MESH_LOOP,
			LINE				= ID_GL_LINE,
			VERTEX				= ID_GL_VERTEX,
			FACE				= ID_GL_FACE,
			LIGHT				= ID_GL_LIGHT,
			MESH_COLOR_HEIGHT	= ID_MESH_COLOR_HEIGHT
		};
	}
}
