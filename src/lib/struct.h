#pragma once

struct PTEST_SCENARIO {
    char *details;
    int failds;

    char **comment;
    unsigned int comment_size;
};

struct PTEST_RESAULT {
    char *topic;
    unsigned int next_scenario;
    struct PTEST_SCENARIO **scenario;
};
