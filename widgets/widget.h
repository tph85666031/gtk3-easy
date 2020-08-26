#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <string>
#include <string.h>
#include <gtk/gtk.h>

typedef void (*fc_gsignal_callback)(GtkWidget* widget, gpointer arg);

class GWidget
{
public:
	GWidget();
    GWidget(GtkWidget* widget);
	~GWidget();
	void init(GtkWidget* widget);
	bool getSize(int& width, int& height);
    void setSize(int width,int height);
    void setName(const char* name);
    void setToolTip(const char* tooltip);
    void setEnable(bool enable);

    std::string getName();
    GtkWidget* getWidget();
protected:
    GtkWidget* widget = NULL;
};


#endif /* __WIDGET_H__ */
