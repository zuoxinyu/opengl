project(glexample)
cmake_minimum_required(VERSION 3.2)

include_directories(
	3rdparty/stb/include
    3rdparty/glfw-3.2.1.bin.WIN32/include
    3rdparty/glad/include
	3rdparty/glm-0.9.9.2/glm
)

link_directories(
	3rdparty/glfw-3.2.1.bin.WIN32/lib-vc2015
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
