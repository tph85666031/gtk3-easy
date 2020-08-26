#ifndef __WIDGET_MENUBAR_H__
#define __WIDGET_MENUBAR_H__

#include "widget.h"

class GMenubar : public GWidget
{
public:
	GMenubar();
	~GMenubar();
	
	GtkWidget* create();
};

#endif /* __WIDGET_MENUBAR_H__ */