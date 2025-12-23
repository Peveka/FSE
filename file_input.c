#include <stdio.h>
#include "errors.h"

errors_t file_scan_data(const char* filename, int* array_to_scan, int* array_len)
{
    FILE* file = fopen(filename, "r");
    if (!file || !array_to_scan || !array_len)
        return ERR_FILE;

    int scanned_num;
    errors_t rc = OK;

    int index = 0;
    while (index < MAX_ARR_LEN && fscanf(file, "%d", &scanned_num) == 1)
    {
        if (scanned_num < 0)
        {
            fclose(file);
            return ERR_NEGATIVE_NUMBER;
        }

        array_to_scan[index] = scanned_num;
        index++;
    }

    if (index == MAX_ARR_LEN && fscanf(file, "%d", &scanned_num) == 1)
        rc = ERR_EXTRA_DATA_IN_FILE;

    *array_len = index;

    if (index == 0)
        rc = ERR_EMPTY_FILE;

    fclose(file);
    return rc;
}