#ifndef FILE_IO_H__
#define FILE_IO_H__

#include "errors.h"

errors_t file_scan_data(const char* filename, int* array_to_scan, int* array_len);

#endif