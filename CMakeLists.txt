Cmake_minimum_required(VERSION 3.0.0)

Project(cross-platform-magic)

add_executable(${PROJECT_NAME} 
				src/main.cpp 
				src/window/window_win32.cpp 
				src/window/window_x11.cpp
			)

if(LINUX)
	include_directories(/usr/X11R6/include)
	link_directories(/usr/X11R6/lib)
	target_link_libraries(${PROJECT_NAME} X11)
endif()