#ifndef __WIDGET_ENTRY_H__
#define __WIDGET_ENTRY_H__

#include "widget.h"

class GEntry : public GWidget
{
public:
    GEntry();
	~GEntry();

    GtkWidget* create();
	void setText(const char* text);
	void setPasswordMode(bool enable);
	void setPasswordModeChar(char val);
	
	std::string getText();
};

#endif /* __WIDGET_ENTRY_H__ */
