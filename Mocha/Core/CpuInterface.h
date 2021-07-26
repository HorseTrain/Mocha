#pragma once

#include <iostream>

namespace Core
{
	class CafeProcess;

	class CpuInterface
	{
	public:

		CafeProcess* process;

	public:

		CpuInterface(CafeProcess* process) { this->process = process; };

		virtual void SetReg(int index, uint32_t value) {};
		virtual uint32_t GetReg(int index) { return -1; }
	};
}