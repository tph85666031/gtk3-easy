#include "widget_notebook.h"

GNoteBook::GNoteBook()
{
}

GNoteBook::~GNoteBook()
{
}

GtkWidget* GNoteBook::create()
{
    this->widget = gtk_notebook_new();
    setName("Notebook");
    return this->widget;
}

GNoteBook& GNoteBook::setOnSwitchedCallback(fc_gsignal_notebook_switched_callback fc, gpointer arg)
{
    g_signal_connect(this->widget, "switch-page", G_CALLBACK(fc), arg);
    return *this;
}

GNoteBook& GNoteBook::setTabPosition(GtkPositionType pos)
{
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(this->widget), pos);
    return *this;
}

GNoteBook& GNoteBook::setCurrentPage(int pos)
{
    gtk_notebook_set_current_page(GTK_NOTEBOOK(this->widget), pos);
    return *this;
}

void GNoteBook::appendPage(const char* name, GtkWidget* widget)
{
    if(name != NULL && widget != NULL)
    {
        GtkWidget* label = gtk_label_new(name);
        gtk_notebook_append_page(GTK_NOTEBOOK(this->widget), widget, label);
    }
}

void GNoteBook::insertPage(const char* name, GtkWidget* widget, int pos)
{
    if(pos < 0)
    {
        pos = 0;
    }
    if(pos > 0 && pos >= getPageCount())
    {
        pos = getPageCount() - 1;
    }
    if(name != NULL && widget != NULL)
    {
        GtkWidget* label = gtk_label_new(name);
        gtk_notebook_insert_page(GTK_NOTEBOOK(this->widget), widget, label, pos);
    }
}

int GNoteBook::getPageCount()
{
    return gtk_notebook_get_n_pages(GTK_NOTEBOOK(this->widget));
}

void GNoteBook::removePage(int pos)
{
    if(pos >= 0 && pos < getPageCount())
    {
        gtk_notebook_remove_page(GTK_NOTEBOOK(this->widget), pos);
    }
}

