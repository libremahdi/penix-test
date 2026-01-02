#include "ptest.h"
#include "struct.h"
#include <stdlib.h>
#include <string.h>

ptst_result *ptst_init(char *topic) {
    ptst_result *result=malloc(sizeof(ptst_result));
    result->topic=malloc(strlen(topic)*sizeof(char)+1);
    strcpy(result->topic, topic);

    result->scenario=NULL;
    result->next_scenario=0;
    return result;
}
