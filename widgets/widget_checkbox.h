#ifndef __WIDGET_CHECKBOX_H__
#define __WIDGET_CHECKBOX_H__

#include "widget.h"

class GCheckBox : public GWidget
{
public:
    GCheckBox();
    ~GCheckBox();
    GtkWidget* create();
    GtkWidget* create(const char* label);
    void setChecked(bool checked);
    void setOnClickedCallback(fc_gsignal_callback fc, gpointer arg = NULL);
};

#endif /* __WIDGET_CHECKBOX_H__ */

