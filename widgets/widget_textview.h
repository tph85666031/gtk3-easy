#ifndef __WIDGET_TEXTVIEW_H__
#define __WIDGET_TEXTVIEW_H__

#include <string>
#include "widget.h"

class GTextView : public GWidget
{
public:
	GTextView();
	~GTextView();

	GtkWidget* create();
    GTextView& setText(const char* text);
    GTextView& appendText(const char* text);
    GTextView& clearText();
    
    std::string getText();
};


#endif /* __WIDGET_TEXTVIEW_H__ */

