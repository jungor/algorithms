/**
 * merge_sort.cpp
 * 归并排序
 */
#include <limits.h>
#include <stdlib.h>
void merge_sort(int nums[], int len) {
    if (len == 1) return;
    int mid = len/2;
    int ll = mid;
    int rl = len - mid;
    int *l = malloc((ll+1)*sizeof(int));
    int *r = malloc((rl+1)*sizeof(int));
    merge_sort(nums, ll);
    merge_sort(nums+mid, rl);
    for (int i=0; i < ll; i++) {
        l[i] = nums[i];
    }
    for (int i=0; i < rl; i++) {
        r[i] = nums[mid+i];
    }
    // 哨兵元素，merge的时候不用检查子数组是否到达边界
    l[ll] = INT_MAX;
    r[rl] = INT_MAX;
    int i = 0;
    int il = 0;
    int ir = 0;
    while (i < len) {
        if (l[il] < r[ir]) {
            nums[i++] = l[il++];
        } else {
            nums[i++] = r[ir++];
        }
    }
    free(l);
    free(r);
}
