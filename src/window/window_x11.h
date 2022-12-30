#ifndef WINDOW_X11_H
#define WINDOW_X11_H

#include "window.h"

class Window_x11 : public Window
{
public:
    void create(const std::string& title, uint width, uint height) override;
    void loop() override;
    void close() override;
};

#endif