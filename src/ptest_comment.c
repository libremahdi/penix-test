#include <stdio.h>
#include "ptest.h"

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void ptst_comment(ptst_result *result, char *comt) {
    // printf (YELLOW"          %s\n"RESET, comt);
    printf (">>>>>>>>: "YELLOW"%s\n"RESET, comt);
}