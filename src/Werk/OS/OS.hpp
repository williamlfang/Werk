
/*
 * Copyright (c) 2015-2020 Agalmic Ventures LLC (www.agalmicventures.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include "Werk/Utility/Attributes.hpp"

#if defined(__APPLE__) || defined(__MACH__)
	#define OS_NAME "Mac OS X";
#elif defined(_WIN32)
	#define OS_NAME "Windows (32-bit)"
#elif defined(_WIN64)
	#define OS_NAME "Windows (64-bit)"
#elif defined(__linux__)
	#define OS_NAME "Linux"
#elif defined(__FreeBSD__)
	#define OS_NAME "FreeBSD"
#else
	#define OS_NAME "Unknown OS";
#endif

namespace werk
{

/**
 * Returns the number of processors on this system.
 */
CHECKED const char *getOperatingSystemName();

}
