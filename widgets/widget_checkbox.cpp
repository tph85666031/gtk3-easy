#include "widget_checkbox.h"

GCheckBox::GCheckBox()
{
}

GCheckBox::~GCheckBox()
{
}

GtkWidget* GCheckBox::create()
{
    this->widget = gtk_check_button_new();
    return this->widget;
}

GtkWidget* GCheckBox::create(const char* label)
{
    this->widget = gtk_check_button_new_with_label(label);
    return this->widget;
}

void GCheckBox::setChecked(bool checked)
{
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(this->widget), checked);
}

void GCheckBox::setOnClickedCallback(fc_gsignal_callback fc, gpointer arg)
{
    g_signal_connect(G_OBJECT(this->widget), "clicked", G_CALLBACK(fc), arg);
}

