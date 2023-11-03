/*
 * LightWhale Communication Protocol Drivers' SDK for LoRa
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
#ifndef SDK_LWDRIVER_H
#define SDK_LWDRIVER_H
#include "lwdef.h"

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

// Define methods' use by the LightWhale wrapper
// interfacing with the SDK as a dynamic link library
// load in the program's runtime

    /**
     * Connect the driver to the program's runtime.
     *
     * @param dll the library file's path
     * @return 0 if everything's okay. Value other than '0' defined the error code.
     */
    int lw_set_driver(const char* dll);

#ifdef __cplusplus
};
#endif//__cplusplus
#endif //SDK_LWDRIVER_H
