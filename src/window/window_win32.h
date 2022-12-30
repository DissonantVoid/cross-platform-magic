#ifndef WINDOW_WIN32_H
#define WINDOW_WIN32_H

#include "window.h"

class Window_win32 : public Window
{
public:
    void create(const std::string& title, uint width, uint height) override;
    void loop() override;
    void close() override;
};

#endif