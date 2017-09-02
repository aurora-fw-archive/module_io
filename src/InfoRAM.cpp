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

#include <AuroraFW/TLib/Target/Platform.h>

#ifdef AFW_TARGET_PLATFORM_WINDOWS
#include <windows.h>
#elif defined(AFW_TARGET_PLATFORM_GNU_LINUX)
#include <sys/sysinfo.h>
#elif defined(AFW_TARGET_PLATFORM_APPLE_MAC)
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#endif

#include <AuroraFW/Info/RAM.h>

namespace AuroraFW
{
    namespace Info {
        namespace RAM {
            // Total virtual memory size in bytes
            unsigned long getTotalVirtualMemory()
            {
                #ifdef AFW_TARGET_PLATFORM_GNU_LINUX
                struct sysinfo mem_temp;
                sysinfo (&mem_temp);
                return (mem_temp.totalram + mem_temp.totalswap) * mem_temp.mem_unit;
                #elif defined(AFW_TARGET_PLATFORM_WINDOWS)

                // TODO: Needs to be tested
                MEMORYSTATUSEX mem_temp;
                mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
                GlobalMemoryStatusEx(&mem_temp);
                return mem_temp.ullTotalVirtual;
                #elif defined(AFW_TARGET_PLATFORM_APPLE_MAC)

                // TODO: Needs to be tested
                struct vmtotal mem_temp;
                vmtotal (&mem_temp);
                return mem_temp.t_vm;
                #endif
            }

            // Used virtual memory size in bytes
            unsigned long getUsedVirtualMemory()
            {
                #ifdef AFW_TARGET_PLATFORM_GNU_LINUX
                struct sysinfo mem_temp;
                sysinfo (&mem_temp);
                return ((mem_temp.totalram - mem_temp.freeram) + (mem_temp.totalswap - mem_temp.freeswap)) * mem_temp.mem_unit;
                #elif defined(AFW_TARGET_PLATFORM_WINDOWS)
                MEMORYSTATUSEX mem_temp;
                mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
                GlobalMemoryStatusEx(&mem_temp);
                return mem_temp.ullTotalVirtual - mem_temp.ullAvailVirtual;
                #elif defined(AFW_TARGET_PLATFORM_APPLE_MAC)
                struct vmtotal mem_temp;
                vmtotal (&mem_temp);
                return mem_temp.t_vm - mem_temp.t_free;
                #endif
            }

            // Free virtual memory size in bytes
            unsigned long getFreeVirtualMemory()
            {
                #ifdef AFW_TARGET_PLATFORM_GNU_LINUX
                struct sysinfo mem_temp;
                sysinfo (&mem_temp);
                return ((mem_temp.totalram + mem_temp.totalswap) - ((mem_temp.totalram - mem_temp.freeram) + (mem_temp.totalswap - mem_temp.freeswap))) * mem_temp.mem_unit;
                #elif defined(AFW_TARGET_WINDOWS)

                // TODO: Needs to be tested
                MEMORYSTATUSEX mem_temp;
                mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
                GlobalMemoryStatusEx(&mem_temp);
                return mem_temp.ullAvailVirtual;
                #elif defined(AFW_TARGET_PLARFORM_APPLE_MAC)

                // TODO: Needs to be tested
                struct vmtotal mem_temp;
                vmtotal (&mem_temp);
                return mem_temp.t_free;
                #endif
            }

            // Total pysical memory size in bytes
            unsigned long getTotalPhysicalMemory()
            {
                #ifdef AFW_TARGET_PLATFORM_GNU_LINUX
                struct sysinfo mem_temp;
                sysinfo (&mem_temp);
                return mem_temp.totalram * mem_temp.mem_unit;
                #elif defined(AFW_TARGET_PLATFORM_WINDOWS)

                // TODO: Needs to be tested
                MEMORYSTATUSEX mem_temp;
                mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
                GlobalMemoryStatusEx(&mem_temp);
                return mem_temp.ullTotalPhys;
                #elif defined(AFW_TARGET_PLATFORM_APPLE_MAC)

                // TODO: Needs to be tested
                int mib[2];
                int64_t physical_memory;
                size_t length;
                // Get the Physical memory size
                mib[0] = CTL_HW;
                mib[1] = HW_MEMSIZE;
                length = sizeof(int64);
                sysctl(mib, 2, &physical_memory, &length, NULL, 0);
                return physical_memory;
                #endif

            }

            // Used pysical memory size in bytes
            unsigned long getUsedPhysicalMemory()
            {
                #ifdef AFW_TARGET_PLATFORM_GNU_LINUX
                struct sysinfo mem_temp;
                sysinfo (&mem_temp);
                return (mem_temp.totalram - mem_temp.freeram) * mem_temp.mem_unit;
                #elif defined(AFW_TARGET_PLATFORM_WINDOWS)

                // TODO: Needs to be tested
                MEMORYSTATUSEX mem_temp;
                mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
                GlobalMemoryStatusEx(&mem_temp);
                return mem_temp.ullTotalPhys - mem_temp.ullAvailPhys;
                #elif defined(AFW_TARGET_PLATFORM_APPLE_MAC)

                // TODO: Needs to be tested
                struct vmmeter mem_temp;
                vmmeter (&mem_temp);
                int mib[2];
                int64_t physical_memory;
                size_t length;
                // Get the Physical memory size
                mib[0] = CTL_HW;
                mib[1] = HW_MEMSIZE;
                length = sizeof(int64);
                sysctl(mib, 2, &physical_memory, &length, NULL, 0);
                return physical_memory - mem_temp.v_free_count;
                #endif
            }

            // Free pysical memory size in bytes
            unsigned long getFreePhysicalMemory()
            {
                #ifdef AFW_TARGET_PLATFORM_GNU_LINUX
                struct sysinfo mem_temp;
                sysinfo (&mem_temp);
                return mem_temp.freeram * mem_temp.mem_unit;
                #elif defined(AFW_TARGET_PLATFORM_WINDOWS)

                // TODO: Needs to be tested
                MEMORYSTATUSEX mem_temp;
                mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
                GlobalMemoryStatusEx(&mem_temp);
                return mem_temp.ullAvailPhys;
                #elif defined(AFW_TARGET_PLATFORM_APPLE_MAC)

                // TODO: Needs to be tested
                struct vmmeter mem_temp;
                vmmeter (&mem_temp);
                return mem_temp.v_free_count;
                #endif
            }
        }
    }
}
