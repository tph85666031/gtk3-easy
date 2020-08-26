#ifndef __WIDGET_WINDOW_H__
#define __WIDGET_WINDOW_H__

#include "widget.h"

class GWindow : public GWidget
{
public:
    GWindow();
    ~GWindow();

    GtkWidget* create();
    GWindow& setTitle(const char* title);
    GWindow& setStartPosition(GtkWindowPosition position);
    GWindow& setOnDestroyCallback(fc_gsignal_callback fc, gpointer arg = NULL);
    GWindow& setIcon(const char* file);
    void setSize(int width, int height);
    void show();
    void hide();
};

#endif /* __WIDGET_WINDOW_H__ */
