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
#ifndef LW_LIBRARY_H
#define LW_LIBRARY_H
#include <stddef.h>

/*< TYPES >*/

typedef void* lwptr_t;
typedef size_t lwenum, lwflag;
typedef size_t lwalloc_s, lwsize_t;

#ifdef __cplusplus
#define lwnull  nullptr
#define lwfalse false
#define lwtrue  true

typedef bool lwbool;
typedef char char8_t;
#else
#define lwnull  0
#define lwfalse 0
#define lwtrue  1

typedef unsigned char blbool;

typedef __WCHAR_TYPE__  wchar_t;
typedef char            char8_t;
typedef signed short    char16_t;
typedef signed int      char32_t;
#endif//__cplusplus

typedef char            lwchar;
typedef unsigned char   lwbyte;

typedef char8_t     lwc8;
typedef char16_t    lwc16;
typedef char32_t    lwc32;

typedef char        lwi8;
typedef short       lwi16;
typedef int         lwi32;
typedef long        lwi64;

typedef unsigned char     lwu8;
typedef unsigned short    lwu16;
typedef unsigned int      lwu32;
typedef unsigned long     lwu64;

typedef float       lwf32;
typedef double      lwf64;

/* BIG ENDIAN SHORT INT */
union lw_be_ushort
{
    lwbyte  _bytes[2];
    lwu16   _short;
};

/* BIG ENDIAN INT */
union lw_be_uint
{
    lwbyte  _bytes[4];
    lwu32   _int;
};

/* BIG ENDIAN LONG INT */
union lw_be_ulong
{
    lwbyte  _bytes[8];
    lwu64   _long;
};

#ifdef LIGHTWHALE_64
typedef __int128    lwi128;
typedef unsigned __int128 lwu128;
typedef long double lwf128;
#endif

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#ifdef __cplusplus
};
#endif //__cplusplus

#endif //LW_LIBRARY_H
