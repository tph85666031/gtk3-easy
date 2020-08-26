#ifndef __WIDGET_COMBOBOX_H__
#define __WIDGET_COMBOBOX_H__

#include "widget.h"

class GComboBox : public GWidget
{
public:
    GComboBox();
    ~GComboBox();

    GtkWidget* create();
    GComboBox& appendItem(const char* text);
    GComboBox& setActiveItem(int pos);
    void setOnItemClicked(fc_gsignal_callback fc, gpointer arg = NULL);
private:
    GtkListStore* store = NULL;
    GtkTreeIter iter;
};

#endif /* __WIDGET_COMBOBOX_H__ */

