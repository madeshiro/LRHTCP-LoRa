/*
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
#include "lwdriver.h"

struct {
    // Examples, remove afterward
    int (*LoraRead)();
    int (*LoraWrite)();
    int (*LoraSetParams)();

} lrhtcp_driver_api;

int lw_set_driver(const char *dll)
{
    lwptr_t driver_hndl = dlopen(dll, RTLD_LAZY);
    if (!driver_hndl)
        return -1; // Unable to open the driver dll

    // Set-up function's handlers
    // ... TODO function's handlers
    lrhtcp_driver_api.LoraRead  = dlsym(driver_hndl, "LoraRead");
    lrhtcp_driver_api.LoraWrite = dlsym(driver_hndl, "LoraWrite");
    lrhtcp_driver_api.LoraSetParams = dlsym(driver_hndl, "LoraSetParams");

    dlclose(driver_hndl);
    return 0;
}