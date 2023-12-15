/*
 * LightWhale Communication Protocol for LoRa
 * Copyright (c) 2023 Rin "madeshiro" Baudelet
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef LW_LIGHTWHALELIBRARY_H
#define LW_LIGHTWHALELIBRARY_H
/**
 * LightWhale Library -=- Low-Rate/Heavy Transfert Control Protocol
 *
 * @file liblightwhale.h
 * @version 2023/12 0.0.1 (alpha)
 * @author Rin "madeshiro" Baudelet
 *
 * ----- << OS/SPECIFICATION >> -----
 * > support OS(arch):
 *   - GNU/Linux distribution (AMD64, ARM64)
 *   - Unix-Like distribution (AMD64, ARM64)
 *   - Windows 10 and latest  (32 and 64bit)
 *
 * > Project made with CMake (@see CMakeLists.txt)
 * > C Standard:    c11
 * > CXX Standard:  c++23
 */

#define LIGHTWHALE_LRHTCP          202312001L //>! 2023/11 0.0.1-alpha
#define LIGHTWHALE_LRHTCP_VERSION "2023/12 v0.0.1-alpha"
#define LIGHTWHALE_LRHTCP_RELEASE 0
#define LIGHTWHALE_LRHTCP_MAJOR   0
#define LIGHTWHALE_LRHTCP_MINOR   1

#define LW_DECL_IMPORT  __declspec(dllimport)
#define LW_DECL_EXPORT  __declspec(dllexport)

#if defined(LIGHTWHALE_PROJECT)
#define LIGHTWHALE_DIR      __declspec(dllexport)
#else
#define LIGHTWHALE_DIR      __declspec(dllimport)
#endif

#endif //LW_LIGHTWHALELIBRARY_H
