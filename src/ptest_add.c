#include "ptest.h"
#include "struct.h"
#include <stdlib.h>
#include <string.h>

void ptst_add(ptst_result *init, char *details) {
    init->scenario = realloc ((init->scenario), sizeof(struct PTEST_SCENARIO)*(1+init->next_scenario));
    init->scenario[init->next_scenario]=malloc(sizeof(struct PTEST_SCENARIO));

    init->scenario[init->next_scenario]->details = malloc(sizeof(char)*strlen(details)+1);
    strcpy (init->scenario[init->next_scenario]->details, details);

    init->scenario[init->next_scenario]->comment = NULL;
    init->scenario[init->next_scenario]->comment_size = 0;

    init->scenario[init->next_scenario]->failds = 0;
    ++init->next_scenario;


}
