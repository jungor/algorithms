/**
 * radix_sort.c
 * 基数排序
 */

#include "radix_sort.h"
#include "counting_sort.h"
#include "../utils.h"
#include <stdlib.h>

void radix_sort(int nums[], int len) {
    int *counts = malloc(COUNTING_SORT_NUM_MAX * sizeof(int));
    int *sorted = malloc(len * sizeof(int));
    int base = 10;
    // 从最低有效位开始为关键字进行计数排序（只要是稳定排序就行）
    for (int j = 0; j < RADIX_SORT_NUM_MAX_WIDTH; j++) {
        for (int i = 0; i < COUNTING_SORT_NUM_MAX; i++) {
            counts[i] = 0;
        }
        for (int i = 0; i < len; i++) {
            counts[nums[i]%base/(base/10)]++;
        }
        for (int i = 1; i < COUNTING_SORT_NUM_MAX; i++) {
            counts[i] += counts[i-1];
        }
        // 必须从后往前遍历，以保证排序的稳定性
        for (int i = len-1; i >= 0; i--) {
            sorted[counts[nums[i]%base/(base/10)]-1] = nums[i];
            counts[nums[i]%base/(base/10)]--;
        }
        for (int i = 0; i < len; i++) {
            nums[i] = sorted[i];
        }
        base *= 10;
    }
    free(counts);
    free(sorted);
}
