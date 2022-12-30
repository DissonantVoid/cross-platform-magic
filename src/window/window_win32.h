#ifndef WINDOW_WIN32_H
#define WINDOW_WIN32_H

#include "window_base.h"
#include <windows.h>

class Window_win32 : public WindowBase
{
public:
    std::string create(const std::string& title, uint width, uint height) override;
    std::string loop() override;
    std::string close() override;

private:
    HWND _window;
    WNDCLASSEXA _wc;
    const std::string _className = "myClass";

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        switch (msg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
            break;
        }
        return 0;
    }
};

#endif