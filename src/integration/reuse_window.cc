#include <windows.h>
#define GLEW_STATIC 
#include <GL/glew.h>
#include <iostream>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glew32s.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f,
};
unsigned int program;
bool inited = false;
const char * fragmentShaderSource =
	"#version 330 core\n"
	"out vec4 FragColor;"
	"void main()"
	"{"
	"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0);"
	"}";

const char * vertexShaderSource =
	"#version 330 core\n"
	"layout (location = 0) in vec3 aPos;"
	"void main()"
	"{"
	"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
	"}";


// referenced from: https://www.khronos.org/opengl/wiki/Creating_an_OpenGL_Context_(WGL)
int __stdcall WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
	MSG msg          = {0};
	WNDCLASS wc      = {0}; 
	wc.lpfnWndProc   = WndProc;
	wc.hInstance     = hInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszClassName = "openglwindow";
	wc.style = CS_OWNDC;
	if( !RegisterClass(&wc) )
		return 1;
	HWND h = CreateWindowW(L"openglwindow",L"reuse an existing window",WS_OVERLAPPEDWINDOW|WS_VISIBLE,0,0,800,600,0,0,hInstance,0);
	ShowWindow(h, 1);

	while(GetMessage( &msg, NULL, 0, 0 ) > 0)
		DispatchMessage( &msg );

	return 0;
}

unsigned int buildGLProgram() {
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO; // vertex buffer object
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		MessageBoxA(0,"ERROR::SHADER::VERTEX::COMILATION:", "Error",0);
	}

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		MessageBoxA(0,"ERROR::SHADER::VERTEX::COMILATION:", "Error",0);
	}

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);;
	glAttachShader(shaderProgram, fragmentShader);;
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		MessageBoxA(0,"ERROR::PROGRAM::LINK", "Error",0);
	}

	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	return shaderProgram;
}

void settingUpOpenGLContext(HWND hWnd) {
	PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 8;
	pfd.iLayerType = PFD_MAIN_PLANE;

	HDC ourWindowHandleToDeviceContext = GetDC(hWnd);

	int  letWindowsChooseThisPixelFormat;
	letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
	SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

	HGLRC ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
	wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

	glewInit();
	inited = true;
	glViewport(0, 0, 800, 600);

	program = buildGLProgram();
}

void doRender() {
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_CREATE:
		settingUpOpenGLContext(hWnd);
		break;

	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	default:
		HDC ourWindowHandleToDeviceContext = GetDC(hWnd);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		doRender();
		SwapBuffers(ourWindowHandleToDeviceContext);
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}