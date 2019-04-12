# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (RealEngine2D)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


# Compile external dependencies
add_subdirectory (external)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# Create a group for Visual Studio
	SOURCE_GROUP(RealEngine2D REGULAR_EXPRESSION ".*/RealEngine2D/.*" )
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

include_directories(
	external/glfw-3.0.3/include/GLFW/
	external/glm-0.9.8.4/
	external/glew-1.9.0/include/
	.
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	GLEW_190
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# RealEngine2D (libRealEngine2D.a)
add_library(RealEngine2D
	RealEngine2D/camera.h
	RealEngine2D/camera.cpp
	RealEngine2D/renderer.h
	RealEngine2D/renderer.cpp
	RealEngine2D/sprite.h
	RealEngine2D/sprite.cpp
	RealEngine2D/scene.h
	RealEngine2D/scene.cpp
	RealEngine2D/entity.h
	RealEngine2D/entity.cpp
	RealEngine2D/core.h
	RealEngine2D/core.cpp
	RealEngine2D/input.h
	RealEngine2D/input.cpp
)

# Demo
add_executable(demo
	demo/demo.cpp
	demo/mainScene.h
	demo/mainScene.cpp
	demo/kingkong.h
	demo/kingkong.cpp
)
target_link_libraries(demo
	RealEngine2D
	${ALL_GRAPHICS_LIBS}
)
# Copy assets and shaders to the build directory
# (In Visual Studio, copy these directories to either 'Release' or 'Build')
file(
	COPY demo/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY RealEngine2D/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
