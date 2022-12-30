Cmake_minimum_required(VERSION 3.0.0)

Project(cross-platform-magic)

add_executable(${PROJECT_NAME} 
				src/main.cpp 
				src/window/window_win32.cpp 
				src/window/window_x11.cpp
			)
