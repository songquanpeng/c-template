#ifndef C_TEMPLATE_UTILS_H
#define C_TEMPLATE_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void fatal(const char *msg) {
    printf("fatal: %s", msg);
    exit(-1);
}


#endif //C_TEMPLATE_UTILS_H
