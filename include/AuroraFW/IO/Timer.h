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

#pragma once

#include <AuroraFW/Global.h>

#include <AuroraFW/TLib/Target/Environment.h>
#include <AuroraFW/TLib/Target/Platform.h>

#ifdef AFW_TARGET_ENVIRONMENT_POSIX
#include <chrono>
#elif defined(AFW_TARGET_PLATFORM_WINDOWS)
#include <Windows.h>
#endif

namespace AuroraFW {
	namespace IO {
		#ifdef AFW_TARGET_ENVIRONMENT_POSIX
		typedef std::chrono::high_resolution_clock HighResolutionClock;
		typedef std::chrono::duration<float, std::milli> milliseconds_type;
		#endif

		class AFW_PREFIX Timer
		{
		private:
			#ifdef AFW_TARGET_ENVIRONMENT_POSIX
			std::chrono::time_point<HighResolutionClock> start;
			#elif AFW_TARGET_PLATFORM_WINDOWS
			LARGE_INTEGER start;
			double frequency;
			#endif

		public:
			Timer();
			void Reset();
			float Elapsed();
			float ElapsedMillis();
		};
	}
}
