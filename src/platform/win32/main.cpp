#include "../Log.h"
#include "../Window.h"
#include <windows.h>
#include <stdio.h>

int main(void) {
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	mango::Log::I("Log Initialize Success.");

	mango::Window::GetInstance();

	//FreeConsole();
}