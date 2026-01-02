#include <string.h>

#include "ptest.h"
#include "struct.h"

void internal_test_fnc_int(ptst_result *init, int num_1, int num_2) {
    if (num_1 != num_2) {
        ++init->scenario[init->next_scenario-1]->failds;
    }
}

void internal_test_fnc_arr(ptst_result *init, char* arr_1, char* arr_2) {
    if (strcmp(arr_1, arr_2)) {
        ++init->scenario[init->next_scenario-1]->failds;
    }
}

void internal_test_fnc_dbl(ptst_result *init, double dbl_1, double dbl_2) {
    if (dbl_1 != dbl_2) {
        ++init->scenario[init->next_scenario-1]->failds;
    }
}

void ptst_fail(ptst_result *init) {
    ++init->scenario[init->next_scenario-1]->failds;
}