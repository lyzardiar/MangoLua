#pragma once

namespace mango {
	class Window {
	public:
		typedef void* ViewPtr;

	public:
		static Window* GetInstance();
	protected:
		static Window* _instance;
		static void Destory();

	public:
		virtual bool Init(int w, int h) = 0;

	protected:
		virtual ~Window() {}

	protected:
		ViewPtr _view = nullptr;
		int _width = 640, _height = 480;
	};
}