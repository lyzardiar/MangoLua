#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#include "Script.h"
#include "../platform/Log.h"

mango::Script mango::Script::instance;

extern "C" {
	extern int luaopen_moonimage(struct lua_State *L);
	extern int luaopen_moonnuklear(struct lua_State *L);
	extern int luaopen_moongl(lua_State *L);
	extern int luaopen_moonglfw(lua_State *L);
}

void mango::Script::Load() {
	Register();
}

void mango::Script::UnLoad() {
	lua_close(L);
	L = nullptr;
}

void mango::Script::Register() {
	lua_register(L, "log", [](lua_State *L)->int {
		auto str = lua_tostring(L, 1);
		mango::Log::I(str);
		return 0;
	});

	addLuaLoader(luaLoader);

	luaopen_moongl(L); lua_setglobal(L, "moongl");
	luaopen_moonglfw(L); lua_setglobal(L, "moonglfw");
	luaopen_moonimage(L); lua_setglobal(L, "moonimage");
	luaopen_moonnuklear(L); lua_setglobal(L, "moonnuklear");
}

int mango::Script::LoadFile(const char* filename) {
	if (filename == nullptr) {
		mango::Log::E("Filename Inccorect.");
		return -1;
	}
	FILE* fp = nullptr;

	std::vector<std::string> orders = {
		"src/", "src/nk/"
	};
	fp = fopen(filename, "rb");
	if (fp == nullptr) {
		for (int i = 0; i < orders.size(); ++i) {
			auto path = orders[i] + filename;
			fp = fopen(path.c_str(), "rb");
			if (fp != nullptr) break;
		}
	}
	
	if (fp == nullptr) {
		mango::Log::E("File can not read. [%s]", filename);
		return -1;
	}

	auto curPos = ftell(fp);
	fseek(fp, 0, SEEK_END);
	auto size = ftell(fp);
	fseek(fp, curPos, SEEK_SET);

	auto buff = (char*)malloc(size + 1);
	fread(buff, size, 1, fp);
	fclose(fp);

	buff[size] = 0;

	auto ret = luaL_loadbuffer(L, buff, size, filename);
	if (ret != 0) {
		auto es = lua_tostring(L, -1);
		if (es != nullptr) {
			Log::E(es);
		}
	}

	free(buff);
	return ret;
}

int mango::Script::RunFile(const char* filename) {
	int ret = LoadFile(filename);
	if (ret == 0) {
		lua_pcall(L, 0, LUA_MULTRET, 0);
	}
	return ret;
}

int mango::Script::LoadScript(const char* code) {
	auto ret = luaL_loadbuffer(L, code, strlen(code), code);
	if (ret != 0) {
		auto es = lua_tostring(L, -1);
		if (es != nullptr) {
			RunScript("debug.traceback()");
			Log::E("%s\n%s", es, lua_tostring(L, -1));
		}
	}
	return ret;
}

int mango::Script::RunScript(const char* code) {
	int ret = LoadScript(code);
	if (ret == 0) {
		lua_pcall(L, 0, LUA_MULTRET, 0);
	}
	return ret;
}

mango::Script::Script() {
	L = luaL_newstate();
	luaL_openlibs(L);
}

mango::Script::~Script() {

}

int mango::Script::luaLoader(lua_State * L) {
	std::string path = lua_tostring(L, 1);
	for (int i = 0, len = path.size(); i < len; ++i) {
		if (path[i] == '.') path[i] = '/';
	}
	path.append(".lua");

	auto ret = Script::instance.LoadFile(path.c_str());
	if (ret == 0) return 1;
	return 0;
}

void mango::Script::addLuaLoader(lua_CFunction func) {
	if (!func)return;
	lua_getglobal(L, "package");
	lua_getfield(L, -1, "searchers");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	}
	else {
		lua_pushcfunction(L, func);
		auto len = lua_objlen(L, -2);
		if (len >= 2) {
			for (int i = len + 1; i > 2; --i) {
				lua_rawgeti(L, -2, i - 1);
				lua_rawseti(L, -3, i);
			}
			lua_rawseti(L, -2, 2);
		}
		else {
			lua_rawseti(L, -2, len+1);
		}
		lua_setfield(L, -2, "loaders");
		lua_pop(L, 1);
	}
}
