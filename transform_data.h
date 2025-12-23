#ifndef TRANSFORM_DATA_H__
#define TRANSFORM_DATA_H__

#include "errors.h"

errors_t transform_data(int* source_data_arr, int* source_data_arr_len, char transformed_data[][MAX_BIT_DEPTH]);

#endif