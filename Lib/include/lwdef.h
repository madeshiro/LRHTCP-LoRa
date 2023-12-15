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
#ifndef LW_LWDEF_H
#define LW_LWDEF_H
#include <stddef.h>
#include "liblightwhale.h"


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

typedef unsigned char lwbool;

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
typedef union lw_be_ushort lw_be_ushort;
union lw_be_ushort
{
    lwbyte  _bytes[2];
    lwu16   _short;
};

/* BIG ENDIAN INT */
typedef union lw_be_uint lw_be_uint;
union lw_be_uint
{
    lwbyte  _bytes[4];
    lwu32   _int;
};

/* BIG ENDIAN LONG INT */
typedef union lw_be_ulong lw_be_ulong;
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
#endif

    /**
     * Check if the system use the Big Endian Byte order
     * @return True if the system is in Big Endian
     */
    lwbool lwisbe();

    /**
     * Lw sHort to Network sHort integer (16bit). Convert any short int to its
     * Big Endian Network Byte Order equivalent.
     * @param hostshort the number to convert.
     * @return a Big-Endian encoding short integer.
     */
    lw_be_ushort lwhtonh(lwu16 hostshort);

    /**
     * Lw Int to Network Integer (32bit). Convert any int to its
     * Big Endian Network Byte Order equivalent.
     * @param hostint the number to convert.
     * @return a Big-Endian encoding integer.
     */
    lw_be_uint lwltonhl(lwu32 hostint);

    /**
     * Lw Long int to Network Long Integer (64bit). Convert any long int to its
     * Big Endian network Byte Order equivalent.
     * @param hostlong the number to convert.
     * @return a Big-Endian encoding long integer.
     */
    lw_be_ulong lwlltonhll(lwu64 hostlong);

    typedef union lightwhale_lp_addr lw_lp_addr;
    union lightwhale_lp_addr
    {
        lwu8  lp_addr_seg[4];
        lwu16 lp_addr_s16[2];
        lwu32 lp_addr;
    };

    typedef struct lightwhale_header_lp lw_lp_header, *plw_lp_header;
    /**
     * LightWhale Header Lora Protocol
     */
    struct lightwhale_header_lp
    {
        lwu8 lp_length;         /**< Header length          */
        lwu8 lp_flags;          /**< Header flag            */
        lwu8 lp_ttc;            /**< number of root iter    */

        lw_lp_addr lp_addr;     /**< Target address         */
        lwu16      lp_port;     /**< Target port            */

        lwu32 packet_length;    /**< Full packet length     */

        lwu32 packet_comm_index;    /**< index of the packet in full communication    */
        lwu32 packet_comm_count;    /**< count of total packets in full communication */
    };

#ifdef __cplusplus
};
#endif // __cplusplus
#endif // LW_LWDEF_H
