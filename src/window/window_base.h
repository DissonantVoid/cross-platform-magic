#ifndef WINDOW_H
#define WINDOW_H

#include <string>

using uint = unsigned int;

class WindowBase
{
public:
	virtual ~WindowBase() {};

	std::string virtual create(const std::string& title, uint width, uint height) = 0;
	std::string virtual loop() = 0;
	std::string virtual close() = 0;
};

#endif
