//CLayoutView.h
/*
 * Copyright (c) 2005 Alexey Shalnov
 * All Rights Reserved
 * 
 * http://home.arcor.de/alexeyshalnov/home/
*/

// Interface to view with some layout properties in MFC application  
#pragma once

template<class T> class CLayoutView : public T
{
	public:
		virtual void SetPreferredSize()=0;
		virtual CSize GetPreferredSize(CSize proposedSize)=0;
		virtual void Scale(float scaleX,float scaleY)=0;
};
