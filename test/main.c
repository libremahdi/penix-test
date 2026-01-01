#include "ptest.h"

int test_1() {
    return 0;
}

int test_2() {
    return -1;
}

int main ()
{
    ptest_run(test_1, "pstr_push");
    ptest_run(test_1, "pstr_repeat");
    ptest_run(test_2, "pstr_find");
    return 0;
}