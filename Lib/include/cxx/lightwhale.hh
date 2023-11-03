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
#ifndef CXX_LW_LIBRARY_HH
#define CXX_LW_LIBRARY_HH
#include "../lightwhale.h"

namespace lightwhale
{
    typedef lwbyte byte;

    typedef lwc8    c8;
    typedef lwc16   c16;
    typedef lwc32   c32;

    typedef lwi8    i8;
    typedef lwi16   i16;
    typedef lwi32   i32;
    typedef lwi64   i64;

    typedef lwu8    u8;
    typedef lwu16   u16;
    typedef lwu32   u32;
    typedef lwu64   u64;

    typedef lwf32 f32;
    typedef lwf64 f64;

    /* BIG ENDIAN SHORT INT */
    typedef lw_be_ushort be_ushort;

    /* BIG ENDIAN INT */
    typedef lw_be_uint be_uint;

    /* BIG ENDIAN LONG INT */
    typedef lw_be_ulong be_ulong;

#ifdef LIGHTWHALE_64
    typedef lwi128 i128;
    typedef lwu128 u128;
    typedef lwf128 f128;
#endif
}

#endif //CXX_LW_LIBRARY_HH
