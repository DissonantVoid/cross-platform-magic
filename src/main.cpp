#include <iostream>
#include "window/window_win32.h"
#include "window/window_x11.h"

enum Platform {UNKNOWN, WIN32, X11};

Platform currPlatform =
#ifdef _WIN32
	Platform::WIN32;
#elifdef __linux__
	Platform::X11;
#else
	Platform::UNKNOWN;
#endif


int main()
{
	if (currPlatform == Platform::UNKNOWN)
	{
		std::cout << "This platform is not supported, only Windows and Linux are\n";
		return -1;
	}

	Window* window;
	if (currPlatform == Platform::WIN32)    window = new Window_win32();
	else if (currPlatform == Platform::X11) window = new Window_x11();


	window->create("Haha, I did it!", 320, 180);

	window->loop();

	window->close();

	delete window;
}
