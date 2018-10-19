project(glexample)
cmake_minimum_required(VERSION 3.2)

include_directories(
    3rdparty/glfw-3.2.1.bin.WIN32/include
    3rdparty/glad/include
)

link_directories(3rdparty/glfw-3.2.1.bin.WIN32/lib-vc2015)
link_libraries(
    glfw3.lib
    opengl32.lib
)

add_executable(simple_triangle
    3rdparty/glad/src/glad.c
    src/triangle.cc
)

add_executable(gradiant_triangle
    3rdparty/glad/src/glad.c
    src/gradiant_triangle.cc
)
