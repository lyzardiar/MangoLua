#pragma once

#include "../Window.h"

#include "gles/glew.h"
#include <GLFW/glfw3.h>

#ifdef _WIN32
#ifndef GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#ifndef GLFW_EXPOSE_NATIVE_WGL
#define GLFW_EXPOSE_NATIVE_WGL
#endif
#include "GLFW/glfw3native.h"
#endif 

namespace mango {
	class WindowWin32 : public Window {
	public:
		WindowWin32();
		virtual ~WindowWin32();

	public:
		bool Init(int w, int h) override;

	protected:
		bool initGlfw(int w, int h);
		bool initGlew();
	protected:
		GLFWwindow* _window = nullptr;
	};
}