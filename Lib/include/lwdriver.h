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

#ifdef LIGHTWHALE_UNIX

// Lora Hardware channel and configuration for specific component
// 10 available channels [0-9], prefix slwcomm
// Serial LightWhale Communication

#   define LWDRIV_COMM0     "/dev/slwcomm0" // Serial LightWhale Communication Ch.0
#   define LWDRIV_COMM1     "/dev/slwcomm1" // Serial LightWhale Communication Ch.1
#   define LWDRIV_COMM2     "/dev/slwcomm2" // Serial LightWhale Communication Ch.2
#   define LWDRIV_COMM3     "/dev/slwcomm3" // Serial LightWhale Communication Ch.3
#   define LWDRIV_COMM4     "/dev/slwcomm4" // Serial LightWhale Communication Ch.4
#   define LWDRIV_COMM5     "/dev/slwcomm5" // Serial LightWhale Communication Ch.5
#   define LWDRIV_COMM6     "/dev/slwcomm6" // Serial LightWhale Communication Ch.6
#   define LWDRIV_COMM7     "/dev/slwcomm7" // Serial LightWhale Communication Ch.7
#   define LWDRIV_COMM8     "/dev/slwcomm8" // Serial LightWhale Communication Ch.8
#   define LWDRIV_COMM9     "/dev/slwcomm9" // Serial LightWhale Communication Ch.9

#elif defined(LIGHTWHALE_WIN32)
#error "not supported yet !" // Focus on Linux/Unix-Like system
#else
#error "not supported OS"
#endif

    /**
     * \brief Read data from the driver.
     * \param n Number of byte to read.
     * \param dest Destination buffer to fill
     * \return The number of bytes actually read
     */
    extern int lrhtcp_lwdriv_read(lwi32 n, lwbyte * restrict dest);

    /**
     * \brief Write data on the driver.
     * \param n Number of byte to write.
     * \param src Data to write on the driver.
     * \return The number of bytes successfuly written.
     */
    extern int lrhtcp_lwdriv_write(lwi32 n, const lwbyte * restrict src);

    /**
     * \brief Open the buffer in the specified open mode.
     * \param open_mode Tell how to open the buffer (FILE*).
     * \return -1 in case of failure, above or equal to 0 otherwise.
     */
    extern int lrhtcp_lwdriv_open(lwflag open_mode);

    /**
     * \brief Close the driver buffer.
     * \return -1 in case of failure, above or equal to 0 otherwise.
     */
    extern int lrhtcp_lwdriv_release();

    typedef struct lw_driver_obj lwdriv, *lwdriv_p;
    struct lw_driver_obj
    {
        int (*read)(lwi32 n, lwbyte * restrict dest);
        int (*write)(lwi32 n, const lwbyte * restrict src);
        int (*open)(lwflag open_mode);
        int (*release)();

        struct lw_driver_desc
        {
            /**
             * \brief Driver channel where's the driver performed
             */
            const char* channel;

            const char* license;        /**< license of the driver      */
            const char* author;         /**< author of the driver       */
            const char* description;    /**< description of the driver  */
            const char* version;        /**< version of the driver      */
        } __desc;
    } const lw_default_driver = {
        .read    = lrhtcp_lwdriv_read,
        .write   = lrhtcp_lwdriv_write,
        .open    = lrhtcp_lwdriv_open,
        .release = lrhtcp_lwdriv_release,
        {
            .channel = LWDRIV_COMM0,

            .license        = "MIT",
            .author         = "Rin E. Baudelet",
            .description    = "Default LoRa driver for the LightWhale Project",
            .version        = LIGHTWHALE_LRHTCP_VERSION
        }
    };

#ifdef __cplusplus
};
#endif//__cplusplus
#endif //SDK_LWDRIVER_H
