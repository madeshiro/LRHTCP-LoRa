#####################################################################################
# LightWhale Communication Protocol for LoRa                                        #
# Copyright (c) 2023 Rin "madeshiro" Baudelet                                       #
#                                                                                   #
# Permission is hereby granted, free of charge, to any person obtaining a copy      #
# of this software and associated documentation files (the "Software"), to deal     #
# in the Software without restriction, including without limitation the rights      #
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell         #
# copies of the Software, and to permit persons to whom the Software is             #
# furnished to do so, subject to the following conditions:                          #
#                                                                                   #
# The above copyright notice and this permission notice shall be included in all    #
# copies or substantial portions of the Software.                                   #
#                                                                                   #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR        #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,          #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE       #
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER            #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,     #
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     #
# SOFTWARE.                                                                         #
#####################################################################################
cmake_minimum_required(VERSION 3.23)
project(lightwhale LANGUAGES C CXX VERSION 0.1.0)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 23)

# Setup CTest
include(CTest)
enable_testing()

# Resolve error concerning 'MultiThreadD11' for MSVC
set(CMAKE_MSVC_RUNTIME_LIBRARY "")


message("--- GRAPHICAL PROTOCOL[CMAKE] CONFIGURATION ---")
message("> version: ${CMAKE_VERSION} (minimum required: ${CMAKE_MINIMUM_REQUIRED_VERSION})")
message("> os: {'name': '${CMAKE_SYSTEM_NAME}', 'arch': '${CMAKE_SYSTEM_PROCESSOR}'}")
message("> check OS/architecture compatibility...")

# Check architecture
# Support 32 and 64bits
set(3CCODE_SYSTEM ${CMAKE_SYSTEM_NAME})
if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "(64)+")
    set(LIGHTWHALE_ARCH 64)
else()
    set(LIGHTWHALE_ARCH 32)
endif()
message("> detecting ${LIGHTWHALE_ARCH}bit...")

# Check operating system
# Support Windows, Linux/Unix-Like systems
message("> detecting ${3CCODE_SYSTEM}...")
if (UNIX OR WIN32)
    message("> operating system OK")
else()
    message(FATAL_ERROR "> operating system FAILED")
endif()

# Check Debug/Release version
if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_definitions(
            -DLIGHTWHALE_DEBUG
    )
    message("> debug mode OK")
else()
    add_definitions(
            -DLIGHTWHALE_RELEASE
    )
    message("> release mode OK")
endif()

add_definitions(
    -DLIGHTWHALE_${LIGHTWHALE_ARCH}
    -DLIGHTWHALE_PROJECT
)

if(UNIX)
    add_definitions(-DLIGHTWHALE_UNIX)
elseif(WIN32)
    add_definitions(-DLIGHTWHALE_WIN32)
endif()

# Headers directories
include_directories("${CMAKE_HOME_DIRECTORY}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Lib/include")

# Add sub-projects
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Drivers)