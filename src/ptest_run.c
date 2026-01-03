#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "ptest.h"
#include "struct.h"


#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void ptst_run(ptst_result *(*ptt_fnc)()) {
    ptst_result *result = ptt_fnc();
    for (register unsigned int in_1=0 ; in_1<result->next_scenario ; ++in_1) {
        if (result->scenario[in_1]->failds != 0) {
            printf (RED"[ FAIL ]: "RESET);
            printf (YELLOW"%s \n"RESET, result->scenario[in_1]->details);
            printf ("          Faild: %d\n", result->scenario[in_1]->failds);
        }
        else {
            printf (GREEN"[ PASS ]: "RESET);
            printf ("%s\n", result->scenario[in_1]->details);
        }
        free(result->scenario[in_1]->details);
        free(result->scenario[in_1]);
    }


    free(result->scenario);
    free(result->topic);
    free(result);
}
