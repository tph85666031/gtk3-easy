#include <string.h>
#include "widget_textview.h"

GTextView::GTextView()
{
}

GTextView::~GTextView()
{
}

GtkWidget* GTextView::create()
{
    this->widget = gtk_text_view_new();
    setName("Textview");
    return this->widget;
}

GTextView& GTextView::setText(const char* text)
{
    if(text != NULL)
    {
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(this->widget));
        gtk_text_buffer_set_text(buffer, text, -1);
    }
    return *this;
}

GTextView& GTextView::appendText(const char* text)
{
    if(text != NULL)
    {
        GtkTextIter iter;
        memset(&iter, 0, sizeof(GtkTextIter));
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(this->widget));
        gtk_text_buffer_get_iter_at_offset(buffer, &iter, -1);
        gtk_text_buffer_insert(buffer, &iter, text, -1);
    }
    return *this;
}

GTextView& GTextView::clearText()
{
    return setText("");
}

std::string GTextView::getText()
{
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(this->widget));
    if(buffer == NULL)
    {
        return std::string();
    }

    GtkTextIter start = {};
    GtkTextIter end = {};
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &start, &end);
    gchar* text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &start, &end, FALSE);
    if(text == NULL)
    {
        return std::string();
    }
    return std::string(text);
}

