#include <stdio.h>
#include <string.h>
#include "errors.h"

static errors_t calculate_digit_sum(int num, int* sum)
{
    if (num < 0)
        return ERR_NEGATIVE_NUMBER;

    *sum = 0;
    if (num == 0)
    {
        *sum = 0;
        return OK;
    }

    int temp = num;
    while (temp != 0)
    {
        *sum += temp % 10;
        temp /= 10;
    }

    return OK;
}

static errors_t reverse_num(int num, int* reversed)
{
    if (num < 0)
        return ERR_NEGATIVE_NUMBER;

    *reversed = 0;

    if (num == 0)
    {
        *reversed = 0;
        return OK;
    }

    int temp = num;
    while (temp != 0)
    {
        *reversed = *reversed * 10 + temp % 10;
        temp /= 10;
    }

    return OK;
}

static errors_t translate_to_binary(char* num_to_print, int num_to_translate)
{
    if (num_to_translate < 0)
        return ERR_NEGATIVE_NUMBER;

    int index = 0;

    if (num_to_translate == 0)
    {
        num_to_print[index++] = '0';
        num_to_print[index] = '\0';
        return OK;
    }

    int bits[MAX_BIT_DEPTH-1];
    int bit_count = 0;

    int num = num_to_translate;
    while (num > 0)
    {
        bits[bit_count++] = num % 2;
        num /= 2;
    }

    for (int i = bit_count - 1; i >= 0; --i)
        num_to_print[index++] = (char)('0' + bits[i]);

    num_to_print[index] = '\0';
    return OK;
}

errors_t transform_data(int* source_data_arr, int* source_data_arr_len, char transformed_data[][MAX_BIT_DEPTH])
{
    if (!source_data_arr || !source_data_arr_len || !transformed_data)
        return ERR_FUNC_ARGS;

    errors_t rc = OK;

    for (int i = 0; i < *source_data_arr_len; ++i)
    {
        if (source_data_arr[i] < 0)
            return ERR_NEGATIVE_NUMBER;

        int sum_of_digits = 0;
        rc = calculate_digit_sum(source_data_arr[i], &sum_of_digits);

        if (rc != OK)
            return rc;

        if (sum_of_digits % 2 != 0)
        {
            int reversed_num = 0;
            rc = reverse_num(source_data_arr[i], &reversed_num);

            if (rc == OK)
                snprintf(transformed_data[i], MAX_BIT_DEPTH, "%d", reversed_num);
        }
        else
        {
            rc = translate_to_binary(transformed_data[i], source_data_arr[i]);
        }

        if (rc != OK)
            return rc;
    }

    return OK;
}