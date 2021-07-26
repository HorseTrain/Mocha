#include "Core/Core.h"

#include <iostream>

int main()
{
	Core::CafeOS* os = new Core::CafeOS();

	Core::CafeProcess* process = os->CreateProcess();

	process->CreateThread();

	delete os;
}