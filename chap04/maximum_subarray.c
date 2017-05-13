/**
 * maximum_subarray.cpp
 * 最大子数组
 * 分:均分成两个子数组。最大子数组只能是以下三种位置：
 *     1. 完全在左子数组。此时它也是左子数组的最大子数组
 *     2. 完全在右子数组。此时它也是左子数组的最大子数组
 *     3. 一部分在左，一部分在右
 * 此思路不是最优算法，有线性时间算法。
 */
#include <limits.h>
#include <stdio.h>
#include "maximum_subarray.h"

subarr maximum_subarray(int nums[], int begin, int end) {
    int len = end - begin;
    subarr sa;
    if (len == 1) {
        sa.left = sa.right = begin;
        sa.sum = nums[0];
        return sa;
    }
    int mid = begin + len/2;
    // 左右子数组的最大子数组
    subarr lsa = maximum_subarray(nums, begin, mid);
    subarr rsa = maximum_subarray(nums, mid, end);
    // 跨越mid的最大子数组
    int maxsum = INT_MIN;
    int suml = 0;
    int maxi, sum = 0;
    int maxil = mid-1;
    for (int i = mid-1; i >= 0; i--) {
        suml += nums[begin+i];
        if (suml > maxsum) {
            maxsum = suml;
            maxil = begin+i;
        }
    }
    sum += maxsum;
    maxsum = INT_MIN;
    int sumr = 0;
    int maxir = mid;
    for (int i = mid; i < len; i++) {
        sumr += nums[begin+i];
        if (sumr > maxsum) {
            maxsum = sumr;
            maxir = begin+i;
        }
    }
    sum += maxsum;
    if (lsa.sum > rsa.sum) {
        sa = lsa;
    } else {
        sa = rsa;
    }
    if (sum > sa.sum) {
        sa.sum = sum;
        sa.left = maxil;
        sa.right = maxir;
    }
    // printf("%d %d %d\n", suml, sumr, sum);
    return sa;
}
