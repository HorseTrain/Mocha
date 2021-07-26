#pragma once

#include <vector>

namespace Core
{
	class CafeOS;
	class VirtualMemoryManager;
	class CpuInterface;

	class CafeProcess
	{
	private:

		CafeOS* os;
		VirtualMemoryManager* memory;
		std::vector<CpuInterface*> CpuCores;

	public:

		CpuInterface* CreateThread();

		CafeProcess(CafeOS* os);
		~CafeProcess();
	};
}