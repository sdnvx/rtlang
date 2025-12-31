#include <stdlib.h>

#include <rtlang/utils.h>

#ifdef __GLIBC__
extern char *program_invocation_short_name;
#endif

const char *rt_process_name(void)
{
#ifdef __GLIBC__
    return program_invocation_short_name;
#else
    return getprogname();
#endif
}
