#ifndef ERR_H__
#define ERR_H__
#define MAX_ARR_LEN 15
#define MAX_BIT_DEPTH 33

typedef enum
{
    OK = 0,
    ERR_FILE,
    ERR_NOT_ENOUGH_ARGS,
    ERR_EXTRA_DATA_IN_FILE,
    ERR_FUNC_ARGS,
    ERR_NEGATIVE_NUMBER,
    ERR_EMPTY_FILE
} errors_t;

#endif