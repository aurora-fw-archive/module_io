# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
# A Powerful General Purpose Framework
# More information in: https://aurora-fw.github.io/
#
# Copyright (C) 2017 Aurora Framework, All rights reserved.
#
# This file is part of the Aurora Framework. This framework is free
# software; you can redistribute it and/or modify it under the terms of
# the GNU Lesser General Public License version 3 as published by the
# Free Software Foundation and appearing in the file LICENSE included in
# the packaging of this file. Please review the following information to
# ensure the GNU Lesser General Public License version 3 requirements
# will be met: https://www.gnu.org/licenses/lgpl-3.0.html.

message(STATUS "Loading io module...")

if (NOT CONFIGURED_ONCE)
	set(AURORAFW_MODULE_IO_SOURCE_DIR ${AURORAFW_MODULE_IO_DIR}/src)
endif()

include_directories(${AURORAFW_MODULE_IO_DIR}/include)

file(GLOB_RECURSE AURORAFW_MODULE_IO_HEADERS ${AURORAFW_MODULE_IO_DIR}/include/*.*)
file(GLOB_RECURSE AURORAFW_MODULE_IO_SOURCE ${AURORAFW_MODULE_IO_SOURCE_DIR}/*.*)

add_library (aurorafw-io SHARED ${AURORAFW_MODULE_IO_SOURCE})
aurora_add_library_target(aurorafw-io)

if(AURORA_PCH)
	add_precompiled_header(aurorafw-io "${AURORAFW_MODULE_IO_HEADERS}")
endif()
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_link_libraries(aurorafw-io aurorafw-core psapi)
else()
	target_link_libraries(aurorafw-io aurorafw-core)
endif()