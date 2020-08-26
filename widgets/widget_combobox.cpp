#include "widget_combobox.h"

GComboBox::GComboBox()
{
}

GComboBox::~GComboBox()
{
}

GtkWidget* GComboBox::create()
{
    store = gtk_list_store_new(1, G_TYPE_STRING);
    this->widget = gtk_combo_box_new_with_model(GTK_TREE_MODEL(store));
    GtkCellRenderer* renderer = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(this->widget), renderer, TRUE);
    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(this->widget), renderer, "text", 0, NULL);
    return this->widget;
}

GComboBox& GComboBox::setActiveItem(int pos)
{
    gtk_combo_box_set_active(GTK_COMBO_BOX(this->widget), pos);
    return *this;
}

GComboBox& GComboBox::appendItem(const char* text)
{
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, text, -1);
    return *this;
}

void GComboBox::setOnItemClicked(fc_gsignal_callback fc, gpointer arg)
{
    g_signal_connect(this->widget, "changed", G_CALLBACK(fc), arg);
}

