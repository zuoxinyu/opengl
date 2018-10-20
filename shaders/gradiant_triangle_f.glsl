#version 330 core
out vec4 FragColor;
//in vec4 vertexColor; // `in` means it receives from the last shader(vertex shader) 
// uniform vec4 ourColor; // `uniform` means this is a global variable, we can access it whenever and whereever even in the host language
in vec3 ourColor;

void main()
{
//    FragColor = vertexColor;
    FragColor = vec4(ourColor, 1.0);
};
