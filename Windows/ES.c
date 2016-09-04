//Using SDL and standard IO
#include <stdio.h>
#include <stdarg.h>
#include "ES.h"

int escreva(const char *format, ...) {
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    return 0;
}