#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#ifdef DEBUG
    #define PRINT_ERROR        if (code_error != ERR_NO) {my_strerr(code_error, stderr);}
    #define ERR_RET(ret_value) if (code_error == NULL || *code_error != 0) {return ret_value;}
#else
    #define PRINT_ERROR
    #define ERR_RET(...)
#endif

#define my_assert(expr, cd_err) if (!(expr)) {  \
        fprintf(stderr, "\x1b[31m%s %s:%d: My assertion failed: \"" #expr "\"\x1b[0m\n", __FILE__, __func__, __LINE__); \
        *code_error |= cd_err;  \
    }

enum code_error {
    ERR_NO            = 0,
    ERR_PTR           = 1 << 0,
    ERR_NAN           = 1 << 1,
    ERR_MEM           = 1 << 2,
    ERR_FOPEN         = 1 << 3,
    ERR_FCLOSE        = 1 << 4,
    ERR_FREAD         = 1 << 5,
    ERR_SYSTEM        = 1 << 6,
    ERR_DIV_ZERO      = 1 << 7,
    ERR_SQRT_NEGAT    = 1 << 8,
    ERR_LOG_NEGAT     = 1 << 9,
    SYNTAX_ERROR      = 1 << 10,
    ERR_TREE          = 1 << 11,

    TREE_ERR_PTR      = 1 << 12,
    TREE_NOT_INIT     = 1 << 13,
    TREE_ERR_ROOT_PTR = 1 << 14,
    TREE_ERR_N_VAR    = 1 << 15,

    NODE_ERR          = 1 << 16,
    NODE_DATA_ERR_PTR = 1 << 17,

    ERR_CNT           = 18
};

void my_strerr (const unsigned code_error, FILE *stream);

#endif // ERROR_H
