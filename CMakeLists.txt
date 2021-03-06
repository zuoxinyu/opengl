project(glexample)
cmake_minimum_required(VERSION 3.2)

include_directories(
	src/common
	3rdparty/stb/include
    3rdparty/glfw-3.2.1.bin.WIN32/include
    3rdparty/glad/include
	3rdparty/glm-0.9.9.2/glm
    3rdparty/glew-2.1.0/include
)

link_directories(
	3rdparty/glfw-3.2.1.bin.WIN32/lib-vc2015
    3rdparty/glew-2.1.0/lib/Release/Win32
	build
)

link_libraries(
    glfw3.lib
    opengl32.lib
	glad.lib
)

add_library(glad STATIC
    3rdparty/glad/src/glad.c
)

add_executable(simple_triangle src/simple_triangle.cc)
add_executable(gradiant_triangle src/gradiant_triangle.cc)
add_executable(texture_triangle src/texture_triangle.cc)
add_executable(transform src/transform.cc)
add_executable(coord_transform src/coord_transform.cc)
add_executable(cube src/cube.cc)
add_executable(camera_control src/camera_control.cc)
add_executable(reuse_window WIN32 src/integration/reuse_window.cc)
