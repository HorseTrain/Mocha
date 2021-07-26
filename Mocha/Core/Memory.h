#pragma once

#include <iostream>

namespace Core
{
	#define ADDRESSSPACE 4ULL * 1024 * 1024 * 1024

	class VirtualMemoryManager
	{
	public:

		void* BasePointer;
		
		void* GetAddress(uint64_t VirtualAddress);

		VirtualMemoryManager();
		~VirtualMemoryManager();

		void Read(void* des, uint64_t VirtualAddress, int size);
		void Write(uint64_t VirtualAddress, void* src, int size);
	};
}