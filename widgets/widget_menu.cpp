#include "widget_menu.h"
#include "widget_image.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
GMenuX::GMenuX()
{
}

GMenuX::~GMenuX()
{
}

GtkWidget* GMenuX::create()
{
    this->widget = gtk_menu_new();
    setName("EMPTY");
    head_item = gtk_menu_item_new_with_label("EMPTY");
    gtk_widget_set_name(head_item, "EMPTY");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(head_item), this->widget);
    return this->widget;
}

GtkWidget* GMenuX::create(const char* label)
{
    this->widget = gtk_menu_new();
    if(label == NULL)
    {
        label = "EMPTY";
    }
    setName(label);
    head_item = gtk_menu_item_new_with_label(label);
    gtk_widget_set_name(head_item, label);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(head_item), this->widget);
    return this->widget;
}

void GMenuX::appendMenuItem(const char* name, const char* label, const char* icon,
                            int icon_width, int icon_height,
                            fc_gsignal_callback fc, gpointer arg)
{
    if(label == NULL)
    {
        return;
    }
    if(icon_width <= 0 || icon_height <= 0)
    {
        icon_width = 16;
        icon_height = 16;
    }
    GtkWidget* menu_item = NULL;
    if(icon != NULL)
    {
        menu_item = gtk_image_menu_item_new_with_label(label);
        GImage image;
        image.create(icon, icon_width, icon_height);
        gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(menu_item), image.getWidget());
    }
    else
    {
        menu_item = gtk_menu_item_new_with_label(label);
    }

    if(menu_item == NULL)
    {
        return;
    }
    if(name != NULL)
    {
        gtk_widget_set_name(menu_item, name);
    }
    gtk_menu_shell_append(GTK_MENU_SHELL(this->widget), menu_item);
    g_signal_connect(G_OBJECT(menu_item), "activate", G_CALLBACK(fc), arg);
    gtk_widget_show_all(this->widget);
}

GtkWidget* GMenuX::getHeader()
{
    return head_item;
}

#pragma GCC diagnostic pop

