#include "Window.h"

using namespace mango;

Window* Window::_instance = nullptr;

void mango::Window::Destory() {
	if (_instance != nullptr) {
		delete _instance;
		_instance = nullptr;
	}
}