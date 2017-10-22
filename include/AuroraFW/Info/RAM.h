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

#ifndef INCLUDE_H_AFW_INFO_RAM
#define INCLUDE_H_AFW_INFO_RAM

namespace AuroraFW {
    namespace Info {
        namespace RAM {
            unsigned long getTotalVirtualMemory(); // Total virtual memory size in bytes
            unsigned long getUsedVirtualMemory(); // Used virtual memory size in bytes
            unsigned long getFreeVirtualMemory(); // Free virtual memory size in bytes
            unsigned long getTotalPhysicalMemory(); // Total pysical memory size in bytes
            unsigned long getUsedPhysicalMemory(); // Used pysical memory size in bytes
            unsigned long getFreePhysicalMemory(); // Free pysical memory size in bytes
        }
    }
}

#endif // INCLUDE_H_AFW_INFO_RAM