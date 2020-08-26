#include "widget_frame.h"

GFrame::GFrame()
{
}

GFrame::~GFrame()
{
}

GtkWidget* GFrame::create()
{
    this->widget = gtk_frame_new("");
    return this->widget;
}

GtkWidget* GFrame::create(const char* label)
{
    if(label == NULL)
    {
        this->widget = gtk_frame_new("");
    }
    else
    {
        this->widget = gtk_frame_new(label);
    }
    return this->widget;
}

void GFrame::setLabel(const char* label)
{
    if(label != NULL)
    {
        gtk_frame_set_label(GTK_FRAME(this->widget), label);
    }
}

void GFrame::setLabel(GtkWidget* widget)
{
    if(widget != NULL)
    {
        gtk_frame_set_label_widget(GTK_FRAME(this->widget), widget);
    }
}
