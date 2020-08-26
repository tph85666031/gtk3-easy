#ifndef __WIDGET_TRAY_H__
#define __WIDGET_TRAY_H__

#include <libappindicator3-0.1/libappindicator/app-indicator.h>
#include <gtk/gtk.h>

typedef void (*fc_tray_on_activated)(GtkStatusIcon* object, gpointer arg);
typedef void (*fc_tray_on_popup_menu)(GtkStatusIcon* status_icon, guint button, guint32 activate_time, gpointer popup_menu);

class GTray
{
public:
    GTray();
    GTray(const char* icon_file, int width = -1, int height = -1);
    ~GTray();

    void setICON(const char* icon_file, int width = -1, int height = -1);
    void setOnActivated(fc_tray_on_activated fc, gpointer arg = NULL);
    void setOnPopupMenu(GtkWidget* menu);
    void setVisible(bool visible);
    void setTooltip(const char* tooltip);
    static void OnTrayPopup(GtkStatusIcon* status_icon, guint button, guint32 activate_time, gpointer menu);
private:
    GtkStatusIcon* tray = NULL;
};

class GTrayX
{
public:
    GTrayX();
    GTrayX(const char* icon_file);
    ~GTrayX();

    void setICON(const char* icon_file);
    void setOnPopupMenu(GtkWidget* menu);
    void setVisible(bool visible);
    void setTooltip(const char* tooltip);
private:
    AppIndicator* tray = NULL;
};

#endif /* __WIDGET_TRAY_H__ */

