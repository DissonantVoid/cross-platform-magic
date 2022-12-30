#ifndef WINDOW_X11_H
#define WINDOW_X11_H

#include <X11/X.h>
#include <X11/Xlib.h>
#include "window_base.h"

class Window_x11 : public WindowBase
{
public:
    std::string create(const std::string& title, uint width, uint height) override;
    std::string loop() override;
    std::string close() override;

private:
    Display* _display;
    Screen* _screen;
    Window _window;
};

#endif