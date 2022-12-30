#ifndef WINDOW_WIN32_H
#define WINDOW_WIN32_H

#include "window_base.h"

class Window_win32 : public WindowBase
{
public:
    std::string create(const std::string& title, uint width, uint height) override;
    std::string loop() override;
    std::string close() override;
};

#endif