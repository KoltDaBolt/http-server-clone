#include "log.h"

void debug_log(const char* format, ...) {
    va_list args;
    va_start(args, format);

    fprintf(stderr, "[LOG] ");
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
}