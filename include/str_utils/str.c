#pragma once
#include "str.h"

char *trim_newline(const char *str)
{
    char *new = malloc(strlen(str)+3);
    bzero(new, strlen(str)+3);
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '\0') return new;
        if(str[i] != '\n' || str[i] != '\r' || str[i] != '\t')
            strcat(new, &str[i]);
    }
    return new;
}