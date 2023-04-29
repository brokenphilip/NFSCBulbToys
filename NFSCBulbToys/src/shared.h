#pragma once
#include <cstdint>
#include <cstring>

#include "nfsc.h"

/* === main project stuff === */

#define PROJECT_NAME "NFSC Bulb Toys"

#define MENU_KEY VK_F9

inline bool exitMainLoop = false;

/* === shared hook/gui data === */

namespace needs_encounter
{
	inline bool hooked = false;
	inline bool value = false;
	inline bool overridden = false;
}

namespace needs_traffic
{
	inline bool hooked = false;
	inline bool value = false;
	inline bool overridden = false;
}

namespace gps_engage
{
	inline bool hooked = false;
	inline void* myAIVehicle = nullptr;
}

namespace click_tp
{
	inline bool hooked = false;
	inline float location[3] = {0, 0, 0};
	constexpr float extra_height = 1;
}

namespace move_vinyl
{
	inline int step_size = 1;
}

/* === helper functions === */

void Error(const char* message, ...);
inline void Sleep(int ms);

template <typename T>
inline T ReadMemory(uintptr_t address)
{
	return *reinterpret_cast<T*>(address);
}

template <typename T>
inline void WriteMemory(uintptr_t address, T value)
{
	T* memory = reinterpret_cast<T*>(address);
	*memory = value;
}

inline void WriteNop(uintptr_t address, int count = 1)
{
	memset(reinterpret_cast<void*>(address), 0x90, count);
}

// NOTE: The jump instruction is 5 bytes
inline void WriteJmp(uintptr_t address, void* jump_to, size_t length = 5)
{
	ptrdiff_t relative = reinterpret_cast<uintptr_t>(jump_to) - address - 5;

	// Write the jump instruction
	WriteMemory<uint8_t>(address, 0xE9);

	// Write the relative address to jump to
	WriteMemory<ptrdiff_t>(address + 1, relative);

	// Write nops until we've reached length
	WriteNop(address + 5, length - 5);
}