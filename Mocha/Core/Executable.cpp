#include "WiiUExecutable.h"
#include "Common.h"
#include "ELF.h"
#include "Memory.h"

using namespace Core;
using namespace Common;

Executable::Executable()
{

}

Executable::~Executable()
{
	if (ProgramBuffer != nullptr)
	{
		delete[] ProgramBuffer;
	}
}

void Executable::LoadFromElfFile(std::string path)
{
	ProgramBuffer = Common::ReadFile(path, &ProgramBufferSize);

	InitHeader();
}

void Executable::InitHeader()
{
	memset(&_header, 0, sizeof(ElfHeader32));

	_header = *(ElfHeader32*)ProgramBuffer;

	_header.TYPE = (ObjectFileType)Read16_BE(ProgramBuffer + 0x10);
	_header.MACHINE = (MachineType)Read16_BE(ProgramBuffer + 0x12);
	_header.e_ENTRY = Read32_BE(ProgramBuffer + 0x18);
	_header.e_PHOFF = Read32_BE(ProgramBuffer + 0x1C);
	_header.e_SHOFF = Read32_BE(ProgramBuffer + 0x20);
	_header.e_SHNUM = Read16_BE(ProgramBuffer + 0x30);
	_header.e_SHSTRNDX = Read16_BE(ProgramBuffer + 0x32);
}

SectionHeader32 Executable::GetSectionHeader(int index)
{
	SectionHeader32 out;

	memset(&out, 0, sizeof(SectionHeader32));

	char* Addr = ProgramBuffer + _header.e_SHOFF + (sizeof(SectionHeader32) * index);

	out.SH_TYPE = (SectionHeaderType)Read32_BE(Addr + 0x04);
	out.SH_FLAGS = (SectionHeaderFlags)Read32_BE(Addr + 0x08);
	out.SH_ADDRESS = Read32_BE(Addr + 0x0c);
	out.SH_OFFSET = Read32_BE(Addr + 0x10);
	out.SH_SIZE = Read32_BE(Addr + 0x14);
	out.SH_ENT_SIZE = Read32_BE(Addr + 0x24);

	return out;
}

void Executable::UploadToMemory(VirtualMemoryManager* memory)
{
	//TODO:

	throw 0;
}