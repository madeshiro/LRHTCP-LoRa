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

// > ReSharper Hint Disable (CLion Nova)
// ReSharper disable CppUnusedIncludeDirective

#ifndef LW_LWDEF_H
#define LW_LWDEF_H
#include <stddef.h>
#include "liblightwhale.h"

// ---- LORA CONFIGURATION CONSTANTS ---- //

// >    Define Spreading factors

#define LW_LORA_SF12    0 /*< SF12 */
#define LW_LORA_SF11    1 /*< SF11 */
#define LW_LORA_SF10    2 /*< SF10 */
#define LW_LORA_SF9     3 /*< SF9  */
#define LW_LORA_SF8     4 /*< SF8  */
#define LW_LORA_SF7     5 /*< SF7  */

// >    Define broadcast ratio

#define LW_BROADCAST_1P     0 /*< Classical ratio 1% legal limitation        */
#define LW_BROADCAST_10P    1 /*< Force to switch to the special channel legal
                                limitation up to 10 %                        */
#define LW_BROADCAST_LBT    2 /*< Listen Before Talk : up to 100% until
                                  another device start a communication       */
#define LW_BROADCAST_LBTM   3 /*< Listen Before Talk adaptive -- *Reserved*  */

// >    Define Bandwidth and associate channels

#define LW_BANDWIDTH_125    0x10    /*< 125 KHz */
#   define LW_CHANNEL125_0  0x00    // .000 - .124 MHz
#   define LW_CHANNEL125_1  0x01    // .125 - .249 MHz
#   define LW_CHANNEL125_2  0x02    // .250 - .374 MHz
#   define LW_CHANNEL125_3  0x03    // .375 - .499 MHz
#   define LW_CHANNEL125_4  0x04    // .500 - .624 MHz
#   define LW_CHANNEL125_5  0x05    // .625 - .749 MHz
#   define LW_CHANNEL125_6  0x06    // .750 - .874 MHz
#   define LW_CHANNEL125_7  0x07    // .875 - .999 MHz

#define LW_BANDWIDTH_250    0x20    /*< 250 KHz */
#   define LW_CHANNEL250_0  0x00    // .000 - .249 MHz
#   define LW_CHANNEL250_1  0x01    // .250 - .499 MHz
#   define LW_CHANNEL250_2  0x02    // .500 - .749 MHz
#   define LW_CHANNEL250_3  0x03    // .750 - .999 MHz

#define LW_BANDWIDTH_333    0x30    /*< 333 KHz */
#   define LW_CHANNEL333_0  0x00    // .000 - .332 MHz
#   define LW_CHANNEL333_1  0x01    // .333 - .665 MHz
#   define LW_CHANNEL333_2  0x02    // .666 - .998 MHz

#define LW_BANDWIDTH_500    0x40    /*< 500 KHz */
#   define LW_CHANNEL500_0  0x00    // .000 - .499 Mhz
#   define LW_CHANNEL500_1  0x01    // .500 - .999 Mhz

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
     * \brief LightWhale Header Lora Protocol
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

    typedef struct lightwhale_data_lp lw_lp_data, *plw_lp_data;
    /**
     * \brief LightWhale Data Descriptor
     */
    struct lightwhale_data_lp; // Defined in lwpacket.c

    typedef struct lightwhale_frame_lp lw_lp_frame, *plw_lp_frame;
    /**
     * \brief LightWhale Frame, Lora Protocol
     */
    struct lightwhale_frame_lp
    {
        struct lightwhale_header_lp const*  header;
        struct lightwhale_data_lp const*    data;
    };

#ifdef __cplusplus
};
#endif // __cplusplus
#endif // LW_LWDEF_H
