#pragma once

#include <string>
#include <fstream>
#include <iostream>

namespace Common
{
	inline char* ReadFile(std::string path, int* size)
	{
		std::ifstream stream;

		stream.open(path, std::ios::binary);

		stream.seekg(0,stream.end);

		*size = stream.tellg();

		char* Out = new char[*size];

		stream.seekg(0, stream.beg);

		stream.read(Out, *size);

		stream.close();

		return Out;
	}

	inline uint16_t _rev16(uint16_t src)
	{
		return (src >> 8) | (src << 8);
	}

	inline uint32_t _rev32(uint32_t src)
	{
		return (src & 0x000000FFU) << 24 | (src & 0x0000FF00U) << 8 |
			(src & 0x00FF0000U) >> 8 | (src & 0xFF000000U) >> 24;
	}

	inline uint64_t _rev64(uint64_t src)
	{
		return (src & 0x00000000000000FFUL) << 56 | (src & 0x000000000000FF00UL) << 40 |
			(src & 0x0000000000FF0000UL) << 24 | (src & 0x00000000FF000000UL) << 8 |
			(src & 0x000000FF00000000UL) >> 8 | (src & 0x0000FF0000000000UL) >> 24 |
			(src & 0x00FF000000000000UL) >> 40 | (src & 0xFF00000000000000UL) >> 56;
	}

	inline std::string ReadString(char* addr, uint64_t size = ULLONG_MAX)
	{
		std::string out = "";

		for (int i = 0; i < size; i++)
		{
			out += addr[i];

			if (addr[i] == 0)
				break;
		}

		return out;
	}

	inline uint8_t Read8(void* Addr)
	{
		return *(uint8_t*)Addr;
	}

	inline uint32_t Read32_BE(void* Addr)
	{
		return _rev32(*(uint32_t*)Addr);
	}

	inline uint16_t Read16_BE(void* Addr)
	{
		return _rev16(*(uint16_t*)Addr);
	}
}