/**
 * couting_sort.h
 * 计数排序
 * 注意：
 *    基数排序原本是非in-place，为了实现in-place空间复杂度从O(k)z增加到O(n+k)
 */

#include "counting_sort.h"
#include "../utils.h"
#include <stdlib.h>

void counting_sort(int nums[], int len) {
    int *counts = malloc(COUNTING_SORT_NUM_MAX * sizeof(int));
    int *sorted = malloc(len * sizeof(int));
    for (int i = 0; i < COUNTING_SORT_NUM_MAX; i++) {
        counts[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        counts[nums[i]]++;
    }
    for (int i = 1; i < COUNTING_SORT_NUM_MAX; i++) {
        counts[i] += counts[i-1];
    }
    // 必须从后往前遍历，以保证排序的稳定性
    for (int i = len-1; i >= 0; i--) {
        sorted[counts[nums[i]]-1] = nums[i];
        counts[nums[i]]--;
    }
    for (int i = 0; i < len; i++) {
        nums[i] = sorted[i];
    }
    free(counts);
    free(sorted);
}
