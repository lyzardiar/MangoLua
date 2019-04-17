#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

namespace mango {
	class Script {
	public:
		static Script instance;

	public:
		void Load();
		void UnLoad();

		void Register();

		int LoadFile(const char* filename);
		int RunFile(const char* filename);
		int LoadScript(const char* code);
		int RunScript(const char* code);

	protected:
		Script();
		~Script();

		static int luaLoader(lua_State * L);
		void addLuaLoader(lua_CFunction func);

	protected:
		struct lua_State *L = nullptr;
	};
}