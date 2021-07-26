#include "CafeProcess.h"
#include "Memory.h"

using namespace Core;

CafeProcess::CafeProcess(CafeOS* os)
{
	this->os = os;
	memory = new VirtualMemoryManager();
}

CafeProcess::~CafeProcess()
{
	for (CpuInterface* Cpu : CpuCores)
	{
		delete Cpu;
	}

	delete memory;
}

CpuInterface* CafeProcess::CreateThread()
{
	throw 0;
}