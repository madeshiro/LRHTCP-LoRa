#include "lwdef.h"

// TODO host to network conversion

lw_be_ushort lwhtonh(lwu16 hostshort)
{
    return (lw_be_ushort){._short = 0u};
}

lw_be_uint lwltonhl(lwu32 hostint)
{
    return (lw_be_uint){._int = 0u};
}

lw_be_ulong lwlltonhll(lwu64 hostlong)
{
    return (lw_be_ulong){._long = 0ul};
}