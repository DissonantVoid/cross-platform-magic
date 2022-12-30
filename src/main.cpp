#include <cstddef>
#include <iostream>

#if defined(_WIN32)
	#include "window/window_win32.h"
	#define NativeWindow Window_win32
#elif defined(__linux__)
	#include "window/window_x11.h"
	#define NativeWindow Window_x11
#else
	#error "This platform is not supported, only Windows and Linux are"
#endif


int main()
{
	WindowBase* window = new NativeWindow();
	std::string ret;

	ret = window->create("Haha, I did it!", 640, 360);
	if(ret.empty() == false)
	{
		std::cout << "setup error: " + ret + '\n'; 
		return -1;
	}
	std::cout << "created!\n";

	ret = window->loop();
	if(ret.empty() == false)
	{
		std::cout << "loop error: " + ret + '\n';
		return -1;
	}

	std::cout << "closing..\n";
	ret = window->close();
	if(ret.empty() == false)
	{
		std::cout << "cleanup error: " + ret + '\n';
		return -1;
	}

	delete window;
}
