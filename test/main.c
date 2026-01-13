#include "ptest.h"
#include <stdio.h>

ptst_result *test_1() {
    ptst_result *result = ptst_init("Passed Test");
    ptst_add (result, "int numbers");
    ptst_test (result, 1, 1);
    ptst_test (result, 2, 2);

    ptst_add (result, "float/double numbers");
    ptst_test (result, 1.1, 1.1);
    ptst_test (result, 3.1415, 3.1415);


    ptst_add (result, "Char* (arr)");
    ptst_test (result, "Hello", "Hello");
    ptst_test (result, "Hi there!", "Hi there!");
    return result;
}

ptst_result *test_2() {
    ptst_result *result = ptst_init("Fail Test");

    ptst_comment (result, "This is hint/comment text");

    ptst_add (result, "int numbers");
    ptst_test (result, 1, 2);
    ptst_test (result, 2, 5);

    ptst_add (result, "float/double numbers");
    ptst_test (result, 1.1, 1.2);
    ptst_test (result, 3.1415, 3.14);


    ptst_add (result, "Char* (arr)");
    ptst_comment (result, "This is hint/comment text for last ptst_add");

    ptst_test (result, "Hello", "Hi");
    ptst_test (result, "Hello there!", "Hi there!");

    ptst_add (result, "Use Fail Function");

    ptst_fail(result);

    return result;
}

int main ()
{
    ptst_run(test_1);
    ptst_run(test_2);
    return 0;
}

/*
==167331== 
==167331== HEAP SUMMARY:
==167331==     in use at exit: 0 bytes in 0 blocks
==167331==   total heap usage: 26 allocs, 26 frees, 1,570 bytes allocated
==167331== 
==167331== All heap blocks were freed -- no leaks are possible
==167331== 
==167331== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/