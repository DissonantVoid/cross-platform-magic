#ifndef WINDOW_H
#define WINDOW_H

#include <string>

using uint = unsigned int;

class Window
{
public:
	void virtual create(const std::string& title, uint width, uint height) = 0;
	void virtual loop() = 0;
	void virtual close() = 0;
};

#endif
