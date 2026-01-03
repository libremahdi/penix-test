#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ptest.h"
#include "struct.h"

ptst_result *ptst_init(char *topic) {
    ptst_result *result=malloc(sizeof(ptst_result));
    result->topic=malloc(strlen(topic)*sizeof(char)+1);
    strcpy(result->topic, topic);
    printf ("\n========= %s =========\n", topic);
    result->scenario=NULL;
    result->next_scenario=0;
    return result;
}
