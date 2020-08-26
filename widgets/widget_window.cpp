#include "widget_window.h"


GWindow::GWindow()
{
}

GWindow::~GWindow()
{
}

GtkWidget* GWindow::create()
{
    this->widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    return this->widget;
}

GWindow& GWindow::setTitle(const char* title)
{
    if(title != NULL)
    {
        gtk_window_set_title(GTK_WINDOW(this->widget), title);
    }
    return *this;
}

void GWindow::setSize(int width, int height)
{
    gtk_window_set_default_size(GTK_WINDOW(this->widget), width, height);
}

GWindow& GWindow::setStartPosition(GtkWindowPosition position)
{
    gtk_window_set_position(GTK_WINDOW(this->widget), position);
    return *this;
}

GWindow& GWindow::setOnDestroyCallback(fc_gsignal_callback fc, gpointer arg)
{
    g_signal_connect(this->widget, "destroy", G_CALLBACK(fc), arg);
    return *this;
}

GWindow& GWindow::setIcon(const char* file)
{
    GdkPixbuf* buf = gdk_pixbuf_new_from_file(file, NULL);
    if(buf != NULL)
    {
        gtk_window_set_icon(GTK_WINDOW(this->widget), buf);
        g_object_unref(buf);
    }
    return *this;
}

void GWindow::show()
{
    gtk_widget_show_all(this->widget);
}

void GWindow::hide()
{
    gtk_widget_hide(this->widget);
}

