#pragma once

#include <iostream>

namespace Core
{
	//TODO: Add 64 bit support?
	//TODO: Add inhouse loaders.
	//TODO: Add better support for big endian.
	enum SectionHeaderType : uint32_t
	{
		SHT_NULL = 0x0,
		SHT_PROGBITS = 0x1,
		SHT_SYMTAB = 0x2,
		SHT_STRTAB = 0x3,
		SHT_RELA = 0x4,
		SHT_HASH = 0x5,
		SHT_DYNAMIC = 0x6,
		SHT_NOTE = 0x7,
		SHT_NOBITS = 0x8,
		SHT_REL = 0x9,
		SHT_SHLIB = 0x0A,
		SHT_DYNSYM = 0x0B,
		SHT_INIT_ARRAY = 0x0E,
		SHT_FINI_ARRAY = 0x0F,
		SHT_PREINIT_ARRAY = 0x10,
		SHT_GROUP = 0x11,
		SHT_SYMTAB_SHNDX = 0x12,
		SHT_NUM = 0x13,
		SHT_LOOS = 0x60000000,
	};

	enum SectionHeaderFlags : uint32_t
	{
		SHF_WRITE = 0x1,
		SHF_ALLOC = 0x2,
		SHF_EXECINSTR = 0x4,
		SHF_MERGE = 0x10,
		SHF_STRINGS = 0x20,
		SHF_INFO_LINK = 0x40,
		SHF_LINK_ORDER = 0x80,
		SHF_OS_NONCONFORMING = 0x100,
		SHF_GROUP = 0x200,
		SHF_TLS = 0x400,
		SHF_MASKOS = 0x0ff00000,
		SHF_MASKPROC = 0xf0000000,
		SHF_ORDERED = 0x4000000,
		SHF_EXCLUDE = 0x8000000,
	};

	enum ABI : uint8_t
	{
		System_V = 0x00,
		HP_UX = 0x01,
		NetBSD = 0x02,
		Linux = 0x03,
		GNU_Hurd = 0x04,
		Solaris = 0x06,
		AIX = 0x07,
		IRIX = 0x08,
		FreeBSD = 0x09,
		Tru64 = 0x0A,
		Novell_Modesto = 0x0B,
		OpenBSD = 0x0C,
		OpenVMS = 0x0D,
		NonStop_Kernel = 0x0E,
		AROS = 0x0F,
		Fenix_OS = 0x10,
		CloudABI = 0x11,
		Stratus_Technologies_OpenVOS = 0x12,
	};

	enum ObjectFileType : uint16_t
	{
		ET_NONE = 0x00,
		ET_REL = 0x01,
		ET_EXEC = 0x02,
		ET_DYN = 0x03,
		ET_CORE = 0x04,
		ET_LOOS = 0xFE00,
		ET_HIOS = 0xFEFF,
		ET_LOPROC = 0xFF00,
		ET_HIPROC = 0xFFFF,
	};

	enum MachineType : uint16_t
	{
		PowerPC = 0x14,
		Arm64 = 0xB7
	};

	struct ElfHeader32
	{
		uint32_t MAGIC;
		uint8_t CLASS;
		uint8_t DATA;
		uint8_t VERSION;
		ABI e_ABI;
		uint8_t ABI_VERSION;
		uint8_t PAD[7];
		ObjectFileType TYPE;
		MachineType MACHINE;
		uint32_t e_VERSION;
		uint32_t e_ENTRY;
		uint32_t e_PHOFF;
		uint32_t e_SHOFF;
		uint32_t e_FLAGS;
		uint16_t e_EHSIZE;
		uint16_t e_PHENTSIZE;
		uint16_t e_PHNUM;
		uint16_t e_SHENTSIZE;
		uint16_t e_SHNUM;
		uint16_t e_SHSTRNDX;
	};

	struct ProgramHeader32
	{
		uint32_t TYPE;
		uint32_t FLAGS;
		uint32_t PHYSICAL_OFFSET;
		uint32_t VIRTUAL_ADDRESS;
		uint32_t PHYSICAL_ADDRESS;
		uint32_t FILE_SIZE;
		uint32_t MEMSZ;
		uint32_t P_FLAGS;
		uint32_t P_ALIGN;
	};

	struct SectionHeader32
	{
		uint32_t SH_NAME;
		SectionHeaderType SH_TYPE;
		SectionHeaderFlags SH_FLAGS;
		uint32_t SH_ADDRESS;
		uint32_t SH_OFFSET;
		uint32_t SH_SIZE;
		uint32_t SH_LINK;
		uint32_t SH_INFO;
		uint32_t SH_ADDRESS_ALIGN;
		uint32_t SH_ENT_SIZE;
	};
}