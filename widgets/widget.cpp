#include "widget.h"

GWidget::GWidget()
{

}

GWidget::GWidget(GtkWidget* widget)
{
    this->widget = widget;
}

GWidget::~GWidget()
{

}

void GWidget::init(GtkWidget* widget)
{
    this->widget = widget;
}

bool GWidget::getSize(int& width, int& height)
{
    gtk_widget_get_size_request(this->widget, &width, &height);
    return true;
}

void GWidget::setSize(int width, int height)
{
    if(width > 0 && height > 0)
    {
        gtk_widget_set_size_request(this->widget, width, height);
    }
}

void GWidget::setName(const char* name)
{
    if(name != NULL)
    {
        gtk_widget_set_name(this->widget, name);
    }
}

void GWidget::setToolTip(const char* tooltip)
{
    if(tooltip != NULL)
    {
        gtk_widget_set_tooltip_text(this->widget, tooltip);
    }
}


void GWidget::setEnable(bool enable)
{
    gtk_widget_set_sensitive(this->widget, enable);
}

GtkWidget* GWidget::getWidget()
{
    return this->widget;
}

std::string GWidget::getName()
{
    const char* name = gtk_widget_get_name(this->widget);
    if(name == NULL)
    {
        name = "";
    }
    return name;
}

