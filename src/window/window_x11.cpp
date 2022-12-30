#include "window_x11.h"

#include <X11/X.h>
#include <string>
#include <iostream>

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/XKBlib.h> // is this commonly available ?

std::string Window_x11::create(const std::string &title, uint width, uint height)
{
    _display = XOpenDisplay(NULL);
    if (_display == NULL)
        return "Could not open display";

    _screen = DefaultScreenOfDisplay(_display);
    if (_screen == NULL)
        return "Could not get screen";

    int id = DefaultScreen(_display);

    _window = XCreateSimpleWindow(_display, XRootWindow(_display, id), 0, 0, width, height, 1, XWhitePixel(_display, id), XBlackPixel(_display, id));
    XStoreName(_display, _window, title.c_str());

    XSelectInput(_display, _window, KeyPressMask | ButtonPressMask); //TODO: KeyReleaseMask causes segfault
    XClearWindow(_display, _window);
    XMapWindow(_display, _window);

    return std::string();
}

std::string Window_x11::loop()
{
    XEvent event;
    while(true)
    {
        XNextEvent(_display, &event);

        if(event.type == KeyPress)
        {
            KeySym key = XkbKeycodeToKeysym(_display, event.xkey.keycode, 0, event.xkey.state & ShiftMask ? 1 : 0);
            std::cout << "Pressing: " << (char)key << '\n';

            if(key == XK_Escape) return std::string();
        }
    }
}

std::string Window_x11::close()
{
    XDestroyWindow(_display, _window);
    XFree(_screen);
    XCloseDisplay(_display); //causes segfault

    return std::string();
}