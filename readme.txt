-------------------------------------------------------------------------------------
AS Software. MfcAdaprerDemo v2.2.2.0 http://home.arcor.de/alexeyshalnov/home/
-------------------------------------------------------------------------------------

1. What's Included

MfcAdapterDemo contains source code and executable samples of six MFC applications hosted in WinForms and WPF applications:

	-"DialogWiz" - simple MFC application without views (only dialogs) created with VS2005 wizard
	
	-"DialogEditor" - DIY vector and dialog editor by Johan Rosengren (http://www.codeproject.com/)

	-"UMLEditor" - revisiting the vector editor by Johan Rosengren (http://www.codeproject.com/)

	-"Mesh" - A small VRML viewer using OpenGL and MFC (http://www.codeproject.com/)

	-"SimpleCtrl" - MFC simple of CLayoutView, CView

	-"RowList" - MFC simple of CListView

MfcAdapterDemo contains v100 (VS2010) x86 "Debug" (Unicode) and "MBCS Debug" (Multi-Byte Caracter Set) .Net4.0 version of MfcAdapter (\MfcAdapter\Debug\):

	-"MfcAppAdapter.dll"

	-"ViewControl.dll"

	-"ViewFrameworkElement.dll"

and documents (\MfcAdapter):

	-"MfcAdapterAPI.chm" - Help file with MfcAdapter Application Programming Interface

	-"ProgrammingGuide.htm" - programming guide for hosting MFC application in WinForms or WPF application

2. Usage
--------------------------------------------------------------------------------------
NOTE1: You can run MfcAdapterDemo, only if you have Visual Studio 2010 installed!!!
--------------------------------------------------------------------------------------


	- unzip all files from MfcAdapterDemo.zip

	- try any executable sample from \Samles\x86\Debug or \Samles\x86\MBCS Debug:
	
		"FormDemo_SimpleCtrl.exe"

		"FormsDemo_DialogWiz.exe"

		"FormsDemo_UmlEditor.exe"

		"MdiFormsDemo.exe"

		"SdiFormsDemo.exe"

		"WpfDemo_UmlEditor.exe"

		"WpfPageDemo_RowList.exe"

		"WpfPageDemo_UmlEditor.exe"

		"WpfPageDemo_WrlViewer.exe"

	- check samples source code. Load and build \Samles\Src\Samples.sln in VS2015.

All projects build outputs will be copied in the common execute directory \Samples\Src\x86\Debug or  \Samples\Src\x86\MBCS Debug with necessary MfcAdapter dll's.
By reference error, simple repeat a build.


	- try to host your MFC application with usage User Guide, MfcAdapter API help and samples.
--------------------------------------------------------------------------------------
NOTE2: MfcAdapterDemo 2.2. contains only x86, Debug, .Net 4.0, Unicode and MBCS Character Set version DLL's
 and can be used only with the same configuration projects!!! Please compare your project settings 
 with samples!!!
--------------------------------------------------------------------------------------


3. Buy full version of MfcAdapter 2.2.
	
	Full version contains source code and compatible with x86, x64 Windows, any MFC configuration (ASCII\Unicode\Mulibyte) and .Net     
	from 4.0 to 4.5. To order MfcAdapter, please mail here: http://home.arcor.de/alexeyshalnov/home/index_files/contact_de.htm 

4. License 
	
MfcAdapterDemo can be used under The Code Project Open License (CPOL) 1.02 http://www.codeproject.com/