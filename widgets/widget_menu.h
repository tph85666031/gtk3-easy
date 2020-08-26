#ifndef __WIDGET_MENU_H__
#define __WIDGET_MENU_H__

#include "widget.h"

class GMenuX : public GWidget
{
public:
    GMenuX();
    ~GMenuX();

    GtkWidget* create();
    GtkWidget* create(const char* label);
    void appendMenuItem(const char* name, const char* label, const char* icon,
                        int icon_width, int icon_height,
                        fc_gsignal_callback fc, gpointer arg);
    GtkWidget* getHeader();
private:
    GtkWidget* head_item = NULL;
};

#endif /* __WIDGET_MENU_H__ */