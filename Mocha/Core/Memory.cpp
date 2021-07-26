#include "Memory.h"

using namespace Core;

VirtualMemoryManager::VirtualMemoryManager()
{
	BasePointer = malloc(ADDRESSSPACE);

	memset(BasePointer, 0,ADDRESSSPACE);
}

VirtualMemoryManager::~VirtualMemoryManager()
{
	free(BasePointer);
}

void* VirtualMemoryManager::GetAddress(uint64_t VirtualAddress)
{
	return ((char*)BasePointer) + VirtualAddress;
}

void VirtualMemoryManager::Read(void* des, uint64_t VirtualAddress, int size)
{
	memcpy(des, GetAddress(VirtualAddress),size);
}

void VirtualMemoryManager::Write(uint64_t VirtualAddress, void* src, int size)
{
	memcpy(GetAddress(VirtualAddress), src, size);
}