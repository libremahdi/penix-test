#ifndef PARABYTE_PTEST
#define PARABYTE_PTEST "1.0.0"

struct PTEST_SCENARIO;
typedef struct PTEST_RESAULT ptst_result;

#include "ptest_test.h"

ptst_result *ptst_init(char *);
void ptst_add(ptst_result *, char *);
void ptst_run(ptst_result *(*)());
void ptst_fail(ptst_result *);
void ptst_comment(ptst_result *, char *);

#endif
