/**
 * quick_sort.h
 * 快速排序
 */

#include "quick_sort.h"
#include "../utils.h"
#include <stdlib.h>

static int partition(int nums[], int begin, int end);
static int randomized_partition(int nums[], int begin, int end);

int partition(int nums[], int begin, int end) {
    int small_top = begin;
    int key = nums[end-1];
    for (int i = begin; i < end; i++) {
        if (nums[i] < key) {
            swap(nums, small_top, i);
            small_top++;
        }
    }
    swap(nums, small_top, end-1);
    return small_top;
}

void quick_sort(int nums[], int begin, int end) {
    if (begin < end) {
        int p = partition(nums, begin, end);
        quick_sort(nums, begin, p);
        quick_sort(nums, p+1, end);
    }
}

int randomized_partition(int nums[], int begin, int end) {
    int r = rand() % (end-begin) + begin;
    swap(nums, end-1, r);
    return partition(nums, begin, end);
}

void randomized_quick_sort(int nums[], int begin, int end) {
    if (begin < end) {
        int p = randomized_partition(nums, begin, end);
        randomized_quick_sort(nums, begin, p);
        randomized_quick_sort(nums, p+1, end);
    }
}
