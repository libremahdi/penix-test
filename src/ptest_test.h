void internal_test_fnc_int(ptst_result *, int, int);
void internal_test_fnc_arr(ptst_result *, char*, char*);
void internal_test_fnc_dbl(ptst_result *, double, double);

#define ptst_test(init, in_1, in_2) _Generic((in_1), \
    int:    internal_test_fnc_int, \
    char*:  internal_test_fnc_arr, \
    double: internal_test_fnc_dbl  \
)(init, in_1, in_2)
