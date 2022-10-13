#ifndef C_TEMPLATE_UTILS_H
#define C_TEMPLATE_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdarg.h>

typedef enum {
    ALL = 0, TRACE = 1, DEBUG = 2, INFO = 3, WARN = 4, ERROR = 5, FATAL = 6, OFF = 7
} LOG_LEVEL;

extern LOG_LEVEL cur_log_level;

bool print_log(LOG_LEVEL level, char *format, ...);


#endif //C_TEMPLATE_UTILS_H
