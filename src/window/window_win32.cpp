#include "window_win32.h"

std::string Window_win32::create(const std::string &title, uint width, uint height)
{
    HINSTANCE hInstance = GetModuleHandleA(0);

    _wc.cbSize = sizeof(_wc);
    _wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    _wc.lpfnWndProc = Window_win32::WndProc;
    _wc.lpszClassName = _className.c_str();
    _wc.hInstance = hInstance;
    _wc.cbClsExtra = NULL;
    _wc.cbWndExtra = NULL;
    _wc.hbrBackground = CreateSolidBrush(RGB(0,0,0));
    _wc.lpszMenuName = NULL;

    _wc.hIcon = NULL;
    _wc.hCursor = NULL;
    _wc.hIconSm = NULL;

    if(RegisterClassExA(&_wc) == NULL) return "Could not register class";

    _window = CreateWindowA(_className.c_str(), title.c_str(), WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);
    if (_window == NULL) return "Could not create window";

    ShowWindow(_window, SW_SHOWNORMAL);
    UpdateWindow(_window);

    return std::string();
}

std::string Window_win32::loop()
{
    MSG msg;
    while (GetMessageA(&msg, _window, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return std::string();
}

std::string Window_win32::close()
{
    UnregisterClassA(_wc.lpszClassName, _wc.hInstance);
    return std::string();
}