#pragma once

#include <string>

#include "ELF.h"

namespace Core
{
	class VirtualMemoryManager;

	class Executable
	{
	private:

		char* ProgramBuffer = nullptr;

		void InitHeader();

	public:

		int ProgramBufferSize;

		ElfHeader32 _header;

		SectionHeader32 GetSectionHeader(int index);

		void UploadToMemory(VirtualMemoryManager* memory);

		void LoadFromElfFile(std::string path);

		Executable();
		~Executable();
	};
}