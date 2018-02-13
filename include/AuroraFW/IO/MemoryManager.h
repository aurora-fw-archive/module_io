/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#ifndef AURORAFW_IO_MEMORY_H
#define AURORAFW_IO_MEMORY_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/Internal/Config.h>

namespace AuroraFW {
	namespace IO {
		struct AFW_API SystemMemoryInfo
		{
			size_t totalPhysicalMemory;
			size_t availablePhysicalMemory;

			size_t totalVirtualMemory;
			size_t availableVirtualMemory;
		};

		struct AFW_API MemoryStats
		{
			void add(size_t );
			void remove(size_t );

			size_t totalAllocated;
			size_t totalFreed;
			size_t currentUsed;
			size_t totalAllocations;
		};

		class AFW_API MemoryManager
		{
			static MemoryStats memStats;

		public:
			static SystemMemoryInfo getSystemInfo();
			inline static MemoryStats& getMemoryStats() { return memStats; }
		};
	}
}

#endif // AURORAFW_IO_MEMORY_H