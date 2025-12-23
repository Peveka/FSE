#include <stdio.h>
#include "errors.h"
#include "file_input.h"
#include "transform_data.h"
#include "file_output.h"

int main(int argc, char** argv)
{
    if (argc != 3)
        return ERR_NOT_ENOUGH_ARGS;

    errors_t rc = OK;
    int source_data_array[MAX_ARR_LEN];
    int array_len = 0;

    rc = file_scan_data(argv[1], source_data_array, &array_len);

    char transformed_data_array[MAX_ARR_LEN][MAX_BIT_DEPTH];

    if (rc == OK || rc == ERR_EXTRA_DATA_IN_FILE)
        rc = transform_data(source_data_array, &array_len, transformed_data_array);


    if (rc == OK)
        rc = file_print_data(argv[2], transformed_data_array, array_len);

    if (rc != OK)
    {
        if (rc == ERR_EXTRA_DATA_IN_FILE)
            printf("Количество чисел в файле превышает допустимое значение\n");
        else if (rc == ERR_NEGATIVE_NUMBER)
            printf("Отрицательные числа в файле\n");
        else if (rc == ERR_EMPTY_FILE)
            printf("Файл пуст\n");
        else if (rc == ERR_FILE)
            printf("Ошибка работы с файлом\n");
    }

    return rc;
}