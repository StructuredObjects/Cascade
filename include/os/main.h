#ifndef MAIN_H
#define MAIN_H

#include "main.c"

/* 
    [PARAMETERS]
        - [filepath] Path to file for reading

    [RETURN] 
        - [CHAR] Return file content 
*/
char *read_file(const char *filepath);

/* 
    [PARAMETERS]
        - [filepath] Path to file for content count

    [RETURN]
        - [INT] file content count
*/
int read_file_size(const char *filepath);

/* 
    [PARAMETERS]
        - [cmd] Command you want executed
        
    [RETURN]
        - [CHAR] Return the command reponse
*/
char *exec(const char *cmd);

#endif