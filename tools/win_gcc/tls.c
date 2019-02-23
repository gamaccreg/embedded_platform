/*
 * tools.c
 *
 *  Created on: Nov 20, 2018
 *      Author: uia94411
 */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <tls.h>

/* print in place; max 30characters */
void tls_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    fflush(stdout);
}
