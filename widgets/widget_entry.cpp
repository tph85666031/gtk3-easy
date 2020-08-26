#include "widget_entry.h"

GEntry::GEntry()
{
}

GEntry::~GEntry()
{
}

GtkWidget* GEntry::create()
{
    this->widget = gtk_entry_new();
    return this->widget;
}

void GEntry::setText(const char* text)
{
    gtk_entry_set_text(GTK_ENTRY(this->widget), text);
}

std::string GEntry::getText()
{
    const char* text = gtk_entry_get_text(GTK_ENTRY(this->widget));
    if(text == NULL)
    {
        return std::string();
    }

    return text;
}

void GEntry::setPasswordMode(bool enable)
{
    gtk_entry_set_visibility(GTK_ENTRY(this->widget), enable ? FALSE : TRUE);
}

void GEntry::setPasswordModeChar(char val)
{
    gtk_entry_set_invisible_char(GTK_ENTRY(this->widget), val);
}

