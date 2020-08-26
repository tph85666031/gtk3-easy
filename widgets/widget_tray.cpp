#include <string>
#include "com_file.h"
#include "widget_tray.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
GTray::GTray()
{
    this->tray = gtk_status_icon_new();
}

GTray::GTray(const char* icon_file, int width, int height)
{
    if(icon_file != NULL)
    {
        if(width > 0 && height > 0)
        {
            GdkPixbuf* buf = gdk_pixbuf_new_from_file(icon_file, NULL);
            if(buf != NULL)
            {
                GdkPixbuf* buf_scaled = gdk_pixbuf_scale_simple(buf, width, height, GDK_INTERP_BILINEAR);
                if(buf_scaled != NULL)
                {
                    this->tray = gtk_status_icon_new_from_pixbuf(buf_scaled);
                    g_object_unref(buf_scaled);
                }
                g_object_unref(buf);
            }
        }
        else
        {
            this->tray = gtk_status_icon_new_from_file(icon_file);
        }
    }
}

GTray::~GTray()
{
}

void GTray::setICON(const char* icon_file, int width, int height)
{
    if(icon_file == NULL)
    {
        return;
    }
    if(width > 0 && height > 0)
    {
        GdkPixbuf* buf = gdk_pixbuf_new_from_file(icon_file, NULL);
        if(buf != NULL)
        {
            GdkPixbuf* buf_scaled = gdk_pixbuf_scale_simple(buf, width, height, GDK_INTERP_HYPER);
            if(buf_scaled != NULL)
            {
                gtk_status_icon_set_from_pixbuf(this->tray, buf_scaled);
                g_object_unref(buf_scaled);
            }
            g_object_unref(buf);
        }
    }
    else
    {
        this->tray = gtk_status_icon_new_from_file(icon_file);
    }
}

void GTray::setOnActivated(fc_tray_on_activated fc, gpointer arg)
{
    g_signal_connect(GTK_STATUS_ICON(this->tray), "activate", G_CALLBACK(fc), arg);
}

void GTray::setOnPopupMenu(GtkWidget* menu)
{
    g_signal_connect(GTK_STATUS_ICON(this->tray), "popup-menu", G_CALLBACK(OnTrayPopup), (gpointer)menu);
}

void GTray::setVisible(bool visible)
{
    gtk_status_icon_set_visible(this->tray, visible);
}

void GTray::setTooltip(const char* tooltip)
{
    gtk_status_icon_set_tooltip_text(this->tray, tooltip);
}

void GTray::OnTrayPopup(GtkStatusIcon* status_icon, guint button, guint32 activate_time, gpointer menu)
{
    gtk_menu_popup(GTK_MENU(menu), NULL, NULL, gtk_status_icon_position_menu, status_icon, button, activate_time);
}

GTrayX::GTrayX()
{
    this->tray = app_indicator_new(std::to_string(com_time_rtc_us()).c_str(),
                                   "UNKNOWN",
                                   APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
}

GTrayX::GTrayX(const char* icon_file)
{
    if(icon_file == NULL)
    {
        this->tray = app_indicator_new(std::to_string(com_time_rtc_us()).c_str(),
                                       "UNKNOWN",
                                       APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
    }
    else
    {
        FilePath file_path(icon_file);
        app_indicator_set_icon_theme_path(this->tray,  file_path.getLocationDirectory().c_str());

        std::string name = file_path.getName();
        std::string::size_type pos = name.rfind('.');
        if(pos != std::string::npos)
        {
            name = name.substr(0, pos);
        }

        this->tray = app_indicator_new_with_path(std::to_string(com_time_rtc_us()).c_str(),
                     name.c_str(),
                     APP_INDICATOR_CATEGORY_APPLICATION_STATUS,
                     file_path.getLocationDirectory().c_str());
    }
}

GTrayX::~GTrayX()
{
}

void GTrayX::setICON(const char* icon_file)
{
    if(icon_file == NULL)
    {
        return;
    }
    FilePath file_path(icon_file);
    app_indicator_set_icon_theme_path(this->tray, file_path.getLocationDirectory().c_str());

    std::string name = file_path.getName();
    std::string::size_type pos = name.rfind('.');
    if(pos != std::string::npos)
    {
        name = name.substr(0, pos);
    }
    app_indicator_set_icon(this->tray, name.c_str());
}

void GTrayX::setOnPopupMenu(GtkWidget* menu)
{
    app_indicator_set_menu(this->tray, GTK_MENU(menu));
}

void GTrayX::setVisible(bool visible)
{
    if(visible)
    {
        app_indicator_set_status(this->tray, APP_INDICATOR_STATUS_ACTIVE);
    }
    else
    {
        app_indicator_set_status(this->tray, APP_INDICATOR_STATUS_PASSIVE);
    }
}

void GTrayX::setTooltip(const char* tooltip)
{
}

#pragma GCC diagnostic pop

