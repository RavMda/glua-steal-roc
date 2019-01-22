/* Copyright (C) 2019 Lewis Clark

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>. */


#include "luashared.h"

typedef glt::ssdk::ILuaInterface* (__thiscall* CreateLuaInterfaceFn)(glt::ssdk::ILuaShared*,
	std::uint8_t, bool);
static CreateLuaInterfaceFn CreateLuaInterfaceOrig = nullptr;

static glt::ssdk::ILuaInterface* __fastcall CreateLuaInterfaceHk(glt::ssdk::ILuaShared* thisptr,
		std::uintptr_t*, std::uint8_t c, bool b) {

	glt::ssdk::ILuaInterface* lua = CreateLuaInterfaceOrig(thisptr, c, b);

	if (c == 0) {
		glt::ssdk::g_clientluainterface = lua;
	}

	return lua;
}

bool glt::hook::LuaSharedHooker::Hook() {
	auto luashared = reinterpret_cast<std::uintptr_t**>(ssdk::g_luashared);

	if (!luashared) {
		return false;
	}

	auto vt = CreateVTHook(luashared);

	CreateLuaInterfaceOrig = vt->HookMethod<CreateLuaInterfaceFn>(
		reinterpret_cast<std::uintptr_t>(CreateLuaInterfaceHk), 4);

	return CreateLuaInterfaceOrig;
}