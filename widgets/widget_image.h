#ifndef __WIDGET_IMAGE_H__
#define __WIDGET_IMAGE_H__

#include "widget.h"

class GImage : public GWidget
{
public:
	GImage();
	~GImage();

    GtkWidget* create();
	GtkWidget* create(const char* file);
	GtkWidget* create(const char* file, int width, int height);
    void setPicture(const char* file, int width, int height);
};


#endif /* __WIDGET_IMAGE_H__ */

