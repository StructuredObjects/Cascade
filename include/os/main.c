#pragma once
#include "main.h"

char *read_file(const char *filepath) 
{
	FILE *fp = fopen(filepath, "r");
	if(fp == NULL) return "";
	long size;
	
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	char *data = malloc(size);
	fread(data, 1, size, fp);
	
	fclose(fp);
	return data;
}

int read_file_size(const char *filepath) 
{
	FILE *fp = fopen(filepath, "r");
	if(fp == NULL) return 0;
	long size;
	
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	fclose(fp);
	return size;
}

char *exec(const  char*cmd)
{
    FILE *new_process = popen(cmd, "r");

    fseek(new_process, 0, SEEK_END);
    long sz = ftell(new_process);
    fseek(new_process, 0, SEEK_SET);

    char *data = malloc(sz*4);
    fread(data, 1, sz+6, new_process);

    pclose(new_process);
    return data;
}