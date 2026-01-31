#include <stdio.h> /* printf */
#include <stdlib.h> /* free */
#include <time.h> /* struct timespec, clock_gettime, CLOCK_MONOTONIC */
#include <errno.h> /* errno, perror */
#include <inttypes.h> /* PRIu64 */
#include <stdint.h> /* uint64_t */

#include "ptest.h"
#include "struct.h"

void ptst_run(ptst_result *(*ptt_fnc)()) {
    struct timespec t1, t2;

    int e1=clock_gettime(CLOCK_MONOTONIC, &t1);
    ptst_result *result = ptt_fnc();
    int e2=clock_gettime(CLOCK_MONOTONIC, &t2);

    if ((e1==-1) || (e2==-1) ) { perror("clock_gettime"); return; }
    uint64_t ns1 = (uint64_t)t1.tv_sec * 1000000000ULL + (uint64_t)t1.tv_nsec;
    uint64_t ns2 = (uint64_t)t2.tv_sec * 1000000000ULL + (uint64_t)t2.tv_nsec;
    uint64_t dif = ns2 - ns1;

    uint64_t sec = dif / 1000000000ULL;
    uint64_t rem_ns = dif % 1000000000ULL;
    uint64_t usec = rem_ns / 1000ULL;
    uint64_t nsec = rem_ns % 1000ULL;

    for (unsigned int in_1=0 ; in_1<result->next_scenario ; ++in_1) {
        
        for (unsigned int in_2=0 ; in_2<result->scenario[in_1]->comment_size ; ++in_2) {
            printf ("/******** "PINK"%s "RESET"********/\n", result->scenario[in_1]->comment[in_2]);
            free (result->scenario[in_1]->comment[in_2]);
        }

        if (result->scenario[in_1]->failds != 0) {
            printf (RED"[ FAIL ] [ ");
            if (sec!=0) printf("%"PRIu64"s ", sec);
            if (usec!=0) printf("%"PRIu64"us ", usec);
            printf("%"PRIu64"ns ]: "RESET, nsec);

            printf (YELLOW"%s \n"RESET, result->scenario[in_1]->details);
            printf ("         Faild: %d\n", result->scenario[in_1]->failds);
        }
        else {
            printf (GREEN"[ PASS ] [ ");
            if (sec!=0) printf("%"PRIu64"s ", sec);
            if (usec!=0) printf("%"PRIu64"us ", usec);
            printf("%"PRIu64"ns ]: "RESET, nsec);

            printf ("%s\n", result->scenario[in_1]->details);
        }
        
        free(result->scenario[in_1]->details);
        free(result->scenario[in_1]->comment);
        free(result->scenario[in_1]);
    }


    free(result->scenario);
    free(result->topic);
    free(result);
}
