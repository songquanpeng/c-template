#include "utils.h"

LOG_LEVEL cur_log_level = INFO;
char log_time[20];
const static char *LOG_LEVEL_TEXT[] = {"ALL", "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL", "OFF"};

bool print_log(LOG_LEVEL level, char *format, ...) {
    if (level < cur_log_level) return false;
    time_t timer = time(NULL);
    strftime(log_time, 20, "%Y-%m-%d %H:%M:%S", localtime(&timer));
    printf("[%s][%s]: ", log_time, LOG_LEVEL_TEXT[level]);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
    if (level == FATAL) {
        exit(EXIT_FAILURE);
    }
    return true;
}