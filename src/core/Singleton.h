#pragma once

template<typename  T>
class Singleton {
public:
	static T* GetInstance() {
		if (_instance == nullptr) {
			_instance = new T();

			atexit(Destory);
		}
		return _instance;
	}
protected:
	static T* _instance;

protected:
	Singleton() {}
	Singleton(const Singleton&) {}
	Singleton(const Singleton&&) {}
	Singleton& operator=(const Singleton&) {}
	Singleton& operator=(const Singleton&&) {}
	
	virtual ~Singleton() { }
	static void Destory() {
		if (_instance != nullptr) {
			delete _instance;
			_instance = nullptr;
		}
	}
};

template<typename  T>
T* Singleton<T>::_instance = nullptr;