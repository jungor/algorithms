/**
 * maximum_subarray.cpp
 * 最大子数组
 */
#include <limits.h>
#include <stdio.h>
#include "maximum_subarray.h"
#include "../utils.h"

static MSA_slt_t maximum_subarray_daq(int nums[], int begin, int end);
static MSA_slt_t maximum_subarray_linear(int nums[], int begin, int end);

/**
 * 解法1：分治法
 * 分:均分成两个子数组。最大子数组只能是以下三种位置：
 *     1. 完全在左子数组。此时它也是左子数组的最大子数组
 *     2. 完全在右子数组。此时它也是左子数组的最大子数组
 *     3. 一部分在左，一部分在右
 * 此思路不是最优算法，有线性时间算法。
 */
MSA_slt_t maximum_subarray_daq(int nums[], int begin, int end) {
    int len = end - begin;
    MSA_slt_t sa;
    if (len == 1) {
        sa.left = sa.right = begin;
        sa.sum = nums[begin];
        return sa;
    }
    int mid = begin + len/2;
    // 左右子数组的最大子数组
    MSA_slt_t lsa = maximum_subarray_daq(nums, begin, mid);
    MSA_slt_t rsa = maximum_subarray_daq(nums, mid, end);
    // 跨越mid的最大子数组
    int maxsum = INT_MIN;
    int suml = 0;
    int sum = 0;
    int maxil = mid-1;
    for (int i = mid-1; i >= begin; i--) {
        suml += nums[i];
        if (suml > maxsum) {
            maxsum = suml;
            maxil = i;
        }
    }
    sum += maxsum;
    maxsum = INT_MIN;
    int sumr = 0;
    int maxir = mid;
    for (int i = mid; i < end; i++) {
        sumr += nums[i];
        if (sumr > maxsum) {
            maxsum = sumr;
            maxir = i;
        }
    }
    sum += maxsum;
    // 选择三种分类中的最优解
    if (lsa.sum > rsa.sum) {
        sa.left = lsa.left;
        sa.right = lsa.right;
        sa.sum = lsa.sum;
    } else {
        sa.left = rsa.left;
        sa.right = rsa.right;
        sa.sum = rsa.sum;
    }
    if (sum > sa.sum) {
        sa.sum = sum;
        sa.left = maxil;
        sa.right = maxir;
    }
    // printf("%d %d %d\n", suml, sumr, sum);
    return sa;
}


MSA_slt_t maximum_subarray_linear(int nums[], int begin, int end) {
    MSA_slt_t slt = {begin, begin, nums[begin]};
    int cur = nums[begin];
    int left = begin;
    for (int i = begin+1; i < end; i++) {
        if (cur <= 0) {
            cur = nums[i];
            left = i;
        } else {
            cur += nums[i];
        }
        if (cur > slt.sum) {
            slt.left = left;
            slt.right = i;
            slt.sum = cur;
        }
    }
    return slt;
}

MSA_slt_t maximum_subarray(int nums[], int begin, int end, MSA_policy_t p) {
    if (p == MSA_PLC_DAQ) {
        return maximum_subarray_daq(nums, begin, end);
    } else {
        return maximum_subarray_linear(nums, begin, end);
    }
}
