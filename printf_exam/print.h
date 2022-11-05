#pragma ONCE
#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <stdio.h>
#include <stdlib.h>

typedef int (*_cloud)(const int *dream,  char *return_contents);

#define PARK_HEADER                     \
    int *mydream;                       \
    char *return_contents;              \
    _cloud  update;                     \

#define DECL_PARK(DREAM, RETURN_FUNCTION) struct {  \
    PARK_HEADER;                                    \
} DEFINE_NAME(NAME, RETURN_FUNCTION)

#define RETURN_FUNCTION(DREAM, RETURN_CONTENTS) \
DECL_PARK(NAME, RETURN_FUNCTION) = {            \
}

typedef struct CLOUD {
    int *mydream;
    char *return_contents;
    int (*_cloud)(const int *,  char *);
} *CLOUD;

int return_dream(const int *dream,  char *return_contents) {
    CLOUD cloud;
    cloud->return_contents = return_contents;
    return_contents = "로우레벨 웹 통합 플렛폼 엔지니어";
    if(sizeof(cloud->mydream) == 4)
        return (printf("%s\n",return_contents));
}

#endif

#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
PARK_HEADER

typedef int (*_main)(int argc, char *argv[]);

#define PRINTF              \
    _main PRINTF            \

#define PRINF_FUNCTION(ARGC, ARGV) struct {   \
    PRINTF;                                   \
} DEFINE_PRINTF(ARGC, ARGV) 

#define RETURN_PRINTF(ARGC, ARGV) \
PRINF_FUNCTION(ARGC, ARGV) = {    \
}

int main(int argc, char *argv[]) {
    return_dream(mydream, return_contents);
    return 0;
}

#endif