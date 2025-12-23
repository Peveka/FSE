#ifndef FILE_OUT_H__
#define FILE_OUT_H__

#include "errors.h"

errors_t file_print_data(const char* filename, char array[][MAX_BIT_DEPTH], int array_len);

#endif