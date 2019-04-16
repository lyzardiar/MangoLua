#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/Singleton.h"

namespace mango {
	class Log : public Singleton<Log> {
	public:
		enum class TYPE {
			WARNING,
			INFO,
			ERR,
			NONE
		};

	public:
		static int W(const char* format, ...);
		static int I(const char* format, ...);
		static int E(const char* format, ...);

	protected:
		int p(TYPE tp, const char* format, va_list args);

		void outToVS(const char*buf);

	protected:
		char* _buff = nullptr;

		int MAX_LENGTH = 1024 << 4;
	};
}