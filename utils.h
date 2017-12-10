#ifndef UTILS_H
#define UTILS_H

#define CHECK_CU_GLOBAL()                     \
    do {                                      \
        CU_ErrorCode c = CU_get_error();      \
        if (CUE_SUCCESS != c) {               \
            printf("%s", CU_get_error_msg()); \
            return c;                         \
        }                                     \
    }                                         \
    while (0)

#define CHECK_CU_RETURN(res)                  \
    do {                                      \
        if (CUE_SUCCESS != (res)) {           \
            printf("%s", CU_get_error_msg()); \
            return (res);                     \
        }                                     \
    }                                         \
    while (0)
/**
 * 输出数组
 */
void print_array(int nums[], int len);
void print_array2(int **nums, int rows, int cols);
void swap(int nums[], int a, int b);
int maxnum(int a, int b);
int minnum(int a, int b);
int get_ith_dgt(int num, int i);
int get_dgt_cnt(int num);
void shuffle(int nums[], int len);
#endif
