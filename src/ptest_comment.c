#include <stdlib.h> /* malloc, realloc */
#include <string.h> /* strlen */
#include <stdio.h> /* printf */

#include "ptest.h"
#include "struct.h"

void ptst_comment(ptst_result *init, char *comt) {
    if (!init->next_scenario) {
        printf (">>>>>>>>: "PINK"%s\n\n"RESET, comt);
        return;
    }

    #define SCN_D init->scenario[init->next_scenario-1]

    SCN_D->comment = realloc (SCN_D->comment, sizeof(char*)*(SCN_D->comment_size+1));
    SCN_D->comment[SCN_D->comment_size] = strdup(comt);

    ++SCN_D->comment_size;
}