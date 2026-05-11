/*
 * Copyright (c) 2026 Brandon Little <blittle@inco.cc>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#define GMOD_ALLOW_DEPRECATED

#include "libremidi/libremidi.hpp"
#include "GarrysMod/Lua/Interface.h"
#include "gmcl_libremidi/common.hpp"
#include "gmcl_libremidi/libraries/libremidi.hpp"

GMOD_MODULE_OPEN() {
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	LUA->CreateTable();
	LUA->PushString(GMCL_LIBREMIDI_VERSION);
	LUA->SetField(-2, "version");
	LUA->PushString(LIBREMIDI_VERSION);
	LUA->SetField(-2, "version_internal");
	LUA->PushCFunction(gmcl_libremidi::libremidi::GetAPIName);
	LUA->SetField(-2, "GetAPIName");
	LUA->PushCFunction(gmcl_libremidi::libremidi::GetAPIDisplayName);
	LUA->SetField(-2, "GetAPIDisplayName");
	LUA->PushCFunction(gmcl_libremidi::libremidi::GetCompiledAPIByName);
	LUA->SetField(-2, "GetCompiledAPIByName");
	LUA->PushCFunction(gmcl_libremidi::libremidi::GetAvailableAPIs);
	LUA->SetField(-2, "GetAvailableAPIs");
	LUA->PushCFunction(gmcl_libremidi::libremidi::GetAvailableUMPAPIs);
	LUA->SetField(-2, "GetAvailableUMPAPIs");
	LUA->SetField(-2, "libremidi");

	return 0;
}

GMOD_MODULE_CLOSE() {
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	LUA->PushNil();
	LUA->SetField(-2, "libremidi");

	return 0;
}
