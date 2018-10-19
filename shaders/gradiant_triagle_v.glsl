#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
//out vec4 vertexColor; // `out` means this variable will transport to the next shader(fragment shader)
out vec3 ourColor; 

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    ourColor = aColor;
//    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // dark red
};
