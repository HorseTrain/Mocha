#include "CafeOS.h"
#include "CafeProcess.h"

using namespace Core;

CafeOS::CafeOS()
{

}

CafeOS::~CafeOS()
{
	for (CafeProcess* process : Processes)
	{
		delete process;
	}
}

CafeProcess* CafeOS::CreateProcess()
{
	CafeProcess* out = new CafeProcess(this);

	Processes.push_back(out);

	return out;
}