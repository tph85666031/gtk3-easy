#include "widget_image.h"

GImage::GImage()
{
}

GImage::~GImage()
{
}

GtkWidget* GImage::create()
{
    this->widget = gtk_image_new();
    return this->widget;
}

GtkWidget* GImage::create(const char* file)
{
    if(file == NULL)
    {
        this->widget = gtk_image_new();
    }
    else
    {
        this->widget = gtk_image_new_from_file(file);
    }
    return this->widget;
}

GtkWidget* GImage::create(const char* file, int width, int height)
{
    if(file == NULL)
    {
        return NULL;
    }
    GdkPixbuf* src = gdk_pixbuf_new_from_file(file, NULL);
    if(src == NULL)
    {
        return NULL;
    }
    GdkPixbuf* dst = NULL;
    if(width > 0 && height > 0)
    {
        dst = gdk_pixbuf_scale_simple(src, width, height, GDK_INTERP_BILINEAR);
        if(dst == NULL)
        {
            g_object_unref(src);
            return NULL;
        }
        this->widget = gtk_image_new_from_pixbuf(dst);
        g_object_unref(src);
        g_object_unref(dst);
    }
    else
    {
        this->widget = gtk_image_new_from_pixbuf(src);
        g_object_unref(src);
    }

    return this->widget;
}

void GImage::setPicture(const char* file, int width, int height)
{
    if(file == NULL)
    {
        return;
    }

    GdkPixbuf* src = gdk_pixbuf_new_from_file(file, NULL);
    if(src == NULL)
    {
        printf("failed to load file:%s\n", file);
        return;
    }
    GdkPixbuf* dst = NULL;
    if(width > 0 && height > 0)
    {
        dst = gdk_pixbuf_scale_simple(src, width, height, GDK_INTERP_BILINEAR);
        if(dst == NULL)
        {
            printf("failed to scale file:%s\n", file);
            g_object_unref(src);
            return;
        }
        gtk_image_set_from_pixbuf(GTK_IMAGE(this->widget), dst);
        g_object_unref(src);
        g_object_unref(dst);
    }
    else
    {
        gtk_image_set_from_pixbuf(GTK_IMAGE(this->widget), src);
        g_object_unref(src);
    }
}


