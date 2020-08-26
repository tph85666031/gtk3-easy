#ifndef __WIDGET_NOTEBOOK_H__
#define __WIDGET_NOTEBOOK_H__

#include <string>
#include "widget.h"

typedef void (*fc_gsignal_notebook_switched_callback)(GtkWidget* widget, GtkWidget* page, guint pos, gpointer arg);

class GNoteBook : public GWidget
{
public:
    GNoteBook();
    ~GNoteBook();

    GtkWidget* create();
    GNoteBook& setOnSwitchedCallback(fc_gsignal_notebook_switched_callback fc, gpointer arg = NULL);
    GNoteBook& setTabPosition(GtkPositionType pos);
    GNoteBook& setCurrentPage(int pos);
    void appendPage(const char* name, GtkWidget* widget);
    void insertPage(const char* name, GtkWidget* widget, int pos);
    int getPageCount();
    void removePage(int pos);
};


#endif /* __WIDGET_NOTEBOOK_H__ */


