#include <stdarg.h>
#include <stdio.h>

#include <rtlang/error.h>
#include <rtlang/utils.h>

static void rt_message(const char *level, const char *fmt, va_list args)
{
    const char *proc;

    fprintf(stderr, "%s: %s: ", rt_process_name(), level);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
}

void rt_error(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    rt_message("error", fmt, args);
    va_end(args);
}
