#include "ptest.h"
#include "struct.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void ptst_run(ptst_result *(*ptt_fnc)()) {
    ptst_result *result = ptt_fnc();
    char fail_flag = 0;

    for (register unsigned int in_1=0 ; in_1<result->next_scenario ; ++in_1) {
        if (result->scenario[in_1]->failds != 0) {
            printf (RED"[ FAIL ]: "RESET);
            printf (YELLOW"%s \n"RESET, result->topic);
            printf ("Faild: %d | %s\n\n", result->scenario[in_1]->failds, result->scenario[in_1]->details);
            fail_flag=1;
        }
        free(result->scenario[in_1]->details);
        free(result->scenario[in_1]);
    }
    if (fail_flag==0) {
        printf (GREEN"[ PASS ]: "RESET);
        printf ("%s\n", result->topic);
    }


    free(result->scenario);
    free(result->topic);
    free(result);
}
