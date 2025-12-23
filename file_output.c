#include <stdio.h>
#include "errors.h"

#define MAX_BIT_DEPTH 33

errors_t file_print_data(const char* filename, char array[][MAX_BIT_DEPTH], int array_len)
{
    if (!filename || !array)
        return ERR_FUNC_ARGS;

    FILE* file = fopen(filename, "w");
    if (!file)
        return ERR_FILE;
    if (array_len > 0)
        fprintf(file, "%s", array[0]);

    for (int i = 1; i < array_len; i++)
        fprintf(file, " %s", array[i]);

    fprintf(file, "\n");
    fclose(file);

    return OK;
}