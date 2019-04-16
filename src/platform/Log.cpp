
#include "Log.h"

#include <io.h>

#include <cstdarg>
#include <algorithm>
#include <Windows.h>


using namespace mango;

void mango::Log::outToVS(const char*buf) {
	const int buffSize = 1024 << 4;
	int pos = 0;
	int len = strlen(buf);
	char tempBuf[buffSize + 1] = { 0 };
	WCHAR wszBuf[buffSize + 1] = { 0 };

	do {
		std::copy(buf + pos, buf + pos + buffSize, tempBuf);
		tempBuf[buffSize] = 0;
		MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, sizeof(wszBuf));
		OutputDebugStringW(wszBuf);
		WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, tempBuf, sizeof(tempBuf), nullptr, FALSE);
		printf("%s", tempBuf);
		pos += buffSize;
	} while (pos < len);
	fflush(stdout);
}

int mango::Log::W(const char* format, ...) {
	va_list args;
	va_start(args, format);
	int len = GetInstance()->p(Log::TYPE::WARNING, format, args);
	va_end(args);
	return len;
}

int mango::Log::I(const char* format, ...) {
	va_list args;
	va_start(args, format);
	int len = GetInstance()->p(Log::TYPE::INFO, format, args);
	va_end(args);
	return len;
}

int mango::Log::E(const char* format, ...) {
	va_list args;
	va_start(args, format);
	int len = GetInstance()->p(Log::TYPE::ERR, format, args);
	va_end(args);
	return len;
}

int mango::Log::p(TYPE tp, const char* format, va_list args) {
	int ret = 0;
	do {
		_buff = _buff == nullptr ? (char*)malloc(MAX_LENGTH) : _buff;
		if (_buff == nullptr) return 0;
		ret = vsnprintf(_buff, MAX_LENGTH - 3, format, args);
		if (ret < 0) {
			MAX_LENGTH <<= 1;
			realloc(_buff, MAX_LENGTH);
		}
		else break;
	} while (true);
	strcat(_buff, "\n");
	outToVS(_buff);
	return ret;
}
