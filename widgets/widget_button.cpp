#include "widget_button.h"

GButton::GButton()
{
}

GtkWidget* GButton::create()
{
    this->widget = gtk_button_new_with_mnemonic("");
    setLabel("");
    return this->widget;
}

GtkWidget* GButton::create(const char* label)
{
    this->widget = gtk_button_new_with_mnemonic(label);
    setLabel(label);
    return this->widget;
}

GButton::~GButton()
{
}

GButton& GButton::setLabel(const char* label)
{
    if(label != NULL)
    {
        gtk_button_set_label(GTK_BUTTON(this->widget), label);
        setName(label);
    }
    return *this;
}

GButton& GButton::setOnClickedCallback(fc_gsignal_callback fc, gpointer arg)
{
    g_signal_connect(this->widget, "clicked", G_CALLBACK(fc), arg);
    return *this;
}

