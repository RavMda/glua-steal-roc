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


#ifndef HOOK_LUAINTERFACE_H
#define HOOK_LUAINTERFACE_H

#include <fstream>
#include <filesystem>

#include "../logger.h"
#include "../file.h"

#include "../lua/lualoader.h"

#include "ihooker.h"

#include "../gamesdk/ILuaInterface.h"
#include "../gamesdk/IVEngineClient.h"

#include "../os.h"

namespace glt::hook {
	class LuaInterfaceHooker : public IHooker {
		public:
		bool Hook();
	};
}

#endif
