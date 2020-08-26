#include "widget_label.h"

GLabel::GLabel()
{
}

GLabel::~GLabel()
{
}

GtkWidget* GLabel::create()
{
    this->widget = gtk_label_new("");
    return this->widget;
}

GtkWidget* GLabel::create(const char* text)
{
    if(text == NULL)
    {
        this->widget = gtk_label_new("");
    }
    else
    {
        this->widget = gtk_label_new(text);
    }

    return this->widget;
}

GLabel& GLabel::setText(const char* text)
{
    if(text != NULL)
    {
        gtk_label_set_text(GTK_LABEL(this->widget), text);
    }
    return *this;
}

GLabel& GLabel::setTextJustifcation(GtkJustification type)
{
    //gtk_label_set_justify(GTK_LABEL(this->widget), type);//单行不起作用
    if(type == GTK_JUSTIFY_LEFT)
    {
        //gtk_misc_set_alignment(GTK_MISC(this->widget), 0, 0.5);
        gtk_label_set_xalign(GTK_LABEL(this->widget), 0);
        gtk_label_set_yalign(GTK_LABEL(this->widget), 0.5);
    }
    else if(type == GTK_JUSTIFY_RIGHT)
    {
        //gtk_misc_set_alignment(GTK_MISC(this->widget), 1, 0.5);
        gtk_label_set_xalign(GTK_LABEL(this->widget), 1);
        gtk_label_set_yalign(GTK_LABEL(this->widget), 0.5);
    }
    else if(type == GTK_JUSTIFY_CENTER)
    {
        //gtk_misc_set_alignment(GTK_MISC(this->widget), 0.5, 0.5);
        gtk_label_set_xalign(GTK_LABEL(this->widget), 0.5);
        gtk_label_set_yalign(GTK_LABEL(this->widget), 0.5);
    }
    return *this;
}

GLabel& GLabel::setFontSize(int size)
{
    if(size > 0)
    {
        this->font_size = size;
        gtk_label_set_markup(GTK_LABEL(this->widget), createMakeup().c_str());
    }
    return *this;
}

GLabel& GLabel::setFontColor(const char* color)
{
    if(color != NULL)
    {
        this->font_color = color;
        gtk_label_set_markup(GTK_LABEL(this->widget), createMakeup().c_str());
    }
    return *this;
}

std::string GLabel::getText()
{
    const char* text = gtk_label_get_text(GTK_LABEL(this->widget));
    if(text == NULL)
    {
        text = "";
    }
    return text;
}

std::string GLabel::createMakeup()
{
    std::string val = "<span foreground='" + this->font_color
                      + "' font_desc='" + std::to_string(this->font_size)
                      + "'>" + getText() + "</span>";
    return val;


}