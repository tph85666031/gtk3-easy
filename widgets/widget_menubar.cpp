#include "widget_menubar.h"

GMenubar::GMenubar()
{

}

GMenubar::~GMenubar()
{
}

GtkWidget* GMenubar::create()
{
    this->widget = 	gtk_menu_bar_new();
    return this->widget;
}
