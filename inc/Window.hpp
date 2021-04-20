#pragma once
#include <GLFW/glfw3.h>

class Window
{
public:
	GLFWwindow *handle;
	Window(int width,int height)
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		handle = glfwCreateWindow(width, height, "Culkan", nullptr, nullptr);
	}
	~Window()
	{
		glfwDestroyWindow(handle);
	}
};