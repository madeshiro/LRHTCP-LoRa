#include "lightwhale.h"
#include <dlfcn.h>
#include <stdio.h>

static lwptr_t lw_dll_driver = NULL;
static lwdriv  lw_driver_api = lw_default_driver;

int lw_set_driver(const char* dll)
{
    if (dll)
    {
        const lwptr_t lwdll = dlopen(dll, RTLD_LAZY);
        if (!lwdll)
        {
            fprintf(stderr, "[lightwhale] Unable to find DLL \"%s\"", dll);
            return -1; // DLL not found
        }

        struct lw_driver_obj (*init_driver)() = dlsym(lwdll, "lwdriv_init");
        if (!init_driver)
        {
            fprintf(stderr,
                "[lightwhale] Unable to find symbol \"init_driver\" in %s",
                dll);
            return -2; // Invalid DLL Symbols
        }

        lw_driver_api = init_driver();
        if (!lw_driver_api)
        {
            fprintf(stderr, "[ligthwhale] An error occured while trying to init"
                            "the driver \"%s\"", dll);
            return -3; // Driver's Internal Error
        }

        lw_dll_driver = lwdll;
    }
    else
    {
        // Set default driver API
        lw_dll_driver = NULL;
        lw_driver_api = lw_default_driver;
    }

    return 0;
}

lwdriv lw_get_driver()
{
    return lw_driver_api;
}
