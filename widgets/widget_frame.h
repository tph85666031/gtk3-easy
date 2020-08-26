#ifndef __WIDGET_FRAME_H__
#define __WIDGET_FRAME_H__

#include "widget.h"

class GFrame : public GWidget
{
public:
    GFrame();
	~GFrame();

    GtkWidget* create();
    GtkWidget* create(const char* label);
	void setLabel(const char* label);
	void setLabel(GtkWidget* widget);
};


#endif /* __WIDGET_FRAME_H__ */

