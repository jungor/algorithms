/**
 * order_statistic.c
 * 顺序统计量
 */

#include "order_statistic.h"
#include "../chap02/insertion_sort.h"
#include "../chap07/quick_sort.h"
#include "../utils.h"
#include <stdlib.h>

int minimum(int nums[], int len) {
    int min = nums[0];
    for (int i = 1; i < len; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

int maximum(int nums[], int len) {
    int max = nums[0];
    for (int i = 1; i < len; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

/**
 * 返回第i小的元素。最小的是第0小
 * 平均O(n)
 */
int randomized_select(int nums[], int begin, int end, int i) {
    int len = end - begin;
    if (len == 1) {
        return nums[begin];
    }
    int q = randomized_partition(nums, begin, end);
    int left_len = q - begin;
    if (i == left_len) {
        return nums[q];
    } else if (i < left_len) {
        return randomized_select(nums, begin, q, i);
    } else {
        return randomized_select(nums, q+1, end, i-left_len-1);
    }
}
/**
 * 将数组5个一组进行分组，找出每组的中位数，返回这些中位数的中位数的下标
 */
int median_of_medians(int nums[], int begin, int end) {
    int len = end - begin;
    int parts_count = len / 5;
    int last_part_len = len % 5;
    int part[5] = {0};
    if (last_part_len > 0) {
        parts_count++;
    }
    int *medians = malloc(parts_count * sizeof(int));
    for (int i = 0; i < parts_count; i++) {
        for (int j = 0; j < 5; j++) {
            part[j] = nums[i*5+j];
        }
        int part_len = 5;
        if (i > len / 5) {
            part_len = last_part_len;
        }
        insertion_sort(part, part_len);
        medians[i] = part[part_len/2];
    }
    int mm = linear_select(medians, 0, parts_count, parts_count/2);
    free(medians);
    return mm;
}

/**
 * 以pivoit作为主元对数组进行partition。返回partition之后主元后的位置
 */
int specified_partition(int nums[], int begin, int end, int pivot) {
    int pivot_index = begin;
    for (; pivot_index < end; pivot_index++) {
        if (nums[pivot_index] == pivot) {
            break;
        }
    }
    swap(nums, end-1, pivot_index);
    return partition(nums, begin, end);
}

/**
 * 最差O(n)， 假设数组的数都是互异的
 */
int linear_select(int nums[], int begin, int end, int i) {
    int len = end - begin;
    if (len == 1) {
        return nums[begin];
    }
    // index of median_of_medians
    int imm = median_of_medians(nums, begin, end);
    int q = specified_partition(nums, begin, end, imm);
    int left_len = q - begin;
    if (i == left_len) {
        return nums[q];
    } else if (i < left_len) {
        return linear_select(nums, begin, q, i);
    } else {
        return linear_select(nums, q+1, end, i-left_len-1);
    }

}
