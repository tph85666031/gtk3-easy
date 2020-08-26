#ifndef __WIDGET_BUTTON_H__
#define __WIDGET_BUTTON_H__

#include "widget.h"

class GButton : public GWidget
{
public:
    GButton();
    ~GButton();
    GtkWidget* create();
    GtkWidget* create(const char* label);
    GButton& setLabel(const char* label);
    GButton& setOnClickedCallback(fc_gsignal_callback fc, gpointer arg = NULL);
};

#endif /* __WIDGET_BUTTON_H__ */
