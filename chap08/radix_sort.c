/**
 * radix_sort.c
 * 基数排序
 */

#include "radix_sort.h"
#include "counting_sort.h"
#include "../utils.h"
#include <stdlib.h>

void radix_sort(int nums[], int len) {
    int counts[COUNTING_SORT_NUM_MAX];
    int sorted[len];
    // 从最低有效位开始为关键字进行计数排序（只要是稳定排序就行）
    int max_len = get_dgt_cnt(RAND_MAX);
    for (int j = 0; j < max_len; j++) {
        for (int i = 0; i < COUNTING_SORT_NUM_MAX; i++) {
            counts[i] = 0;
        }
        for (int i = 0; i < len; i++) {
            counts[get_ith_dgt(nums[i], j)]++;
        }
        for (int i = 1; i < COUNTING_SORT_NUM_MAX; i++) {
            counts[i] += counts[i-1];
        }
        for (int i = len-1; i >= 0; i--) {
            sorted[counts[get_ith_dgt(nums[i], j)]-1] = nums[i];
            counts[get_ith_dgt(nums[i], j)]--;
        }
        for (int i = 0; i < len; i++) {
            nums[i] = sorted[i];
        }
    }
}
