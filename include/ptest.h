#ifndef PARABYTE_PTEST
#define PARABYTE_PTEST "1.0.0"

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define PINK    "\033[35m"
#define RESET   "\033[0m"

struct PTEST_SCENARIO;
typedef struct PTEST_RESAULT ptst_result;

#include "ptest_test.h"

ptst_result *ptst_init(char *);
void ptst_add(ptst_result *, char *);
void ptst_run(ptst_result *(*)());
void ptst_fail(ptst_result *);
void ptst_comment(ptst_result *, char *);

#endif
