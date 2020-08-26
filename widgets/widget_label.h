#ifndef __WIDGET_LABEL_H__
#define __WIDGET_LABEL_H__

#include "widget.h"

class GLabel : public GWidget
{
public:
    GLabel();
    ~GLabel();

    GtkWidget* create();
    GtkWidget* create(const char* text);
    GLabel& setText(const char* text);
    GLabel& setTextJustifcation(GtkJustification type);
    GLabel& setFontSize(int size);
    GLabel& setFontColor(const char* color);
    std::string getText();
private:
    std::string createMakeup();

private:
    int font_size = 16;
    std::string font_color = "black";
};


#endif /* __WIDGET_LABEL_H__ */
