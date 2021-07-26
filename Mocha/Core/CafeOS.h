#pragma once

#include <vector>

namespace Core
{
	class CafeProcess;

	class CafeOS
	{
	public:
		
		std::vector<CafeProcess*> Processes;

		CafeProcess* CreateProcess();

		CafeOS();
		~CafeOS();
	};
}