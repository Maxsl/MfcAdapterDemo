// IWndManager.cs
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/
using System;
using System.Windows.Forms;

namespace AS.MfcHost
{
    interface IWndManager
    {
		/// <summary>
		/// Activate parent window
		/// </summary>
		/// <param name="ctrl"></param>
	
        void Activate(Control ctrl);
   }
}
