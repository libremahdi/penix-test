#include "ptest.h"

#include <stdio.h>
#include <unistd.h>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void ptest_run(int (*ptt_fnc)(), char *topic) {
    int result = ptt_fnc();

    if (result==-1) {
        printf (RED"[ERROR]: "RESET);
        printf (YELLOW"%s\n"RESET, topic);
    } else {
        printf (GREEN"[PASSD]: "RESET);
        printf ("%s\n", topic);
    }
    usleep (500000);
}