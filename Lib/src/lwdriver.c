#include "lwdriver.h"
#include <dlfcn.h>

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