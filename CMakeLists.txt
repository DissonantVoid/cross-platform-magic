Cmake_minimum_required(VERSION 3.0.0)

Project(cross-platform-magic)

set(SRC src/main.cpp)

if(WIN32)
	set(SRC 
				${SRC}
				src/window/window_win32.cpp
		)
elseif(LINUX)
	set(SRC 
				${SRC}
				src/window/window_x11.cpp
		)
	
	include_directories(/usr/X11R6/include)
	link_directories(/usr/X11R6/lib)
	target_link_libraries(${PROJECT_NAME} X11)
endif()


add_executable(${PROJECT_NAME} ${SRC})