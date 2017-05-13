/**
 * heap_sort.c
 * 堆排序
 */

#include "heap_sort.h"
#include <limits.h>
/**
 * 维护堆的性质
 * 前置条件：i的左右子树都已经是最大堆
 * 后置条件：i为根的树也是最大堆
 */
void max_heapify(int nums[], int heap_size, int i) {
    int l = 2*i+1;
    int r = 2*i+2;
    // 在i, l, r三个位置中找最大值上，如果是l或者r就和i交换位置
    int max;
    if (l < heap_size && nums[l] > nums[i]) {
        max = l;
    } else {
        max = i;
    }
    if (r < heap_size && nums[r] > nums[max]) {
        max = r;
    }
    if (max != i) {
        int tmp = nums[i];
        nums[i] = nums[max];
        nums[max] = tmp;
        max_heapify(nums, heap_size, max);
    }
}

/**
 * 建堆
 * 注意: 因为叶子节点可以看做是已经建好的堆，可以直接从非叶子节点开始自底向上建堆
 */
void build_max_heap(int nums[], int len) {
    int heap_size = len;
    for (int i = len/2-1; i >=0; i--) {
        max_heapify(nums, heap_size, i);
    }
}

/**
 * 堆排序
 */
void heap_sort(int nums[], int len) {
    build_max_heap(nums, len);
    int heap_size = len;
    for (int i = len-1; i >= 0; i--) {
        int tmp = nums[0];
        nums[0] = nums[i];
        nums[i] = tmp;
        heap_size--;
        max_heapify(nums, heap_size, 0);
    }    
}

int heap_maximum(int nums[]) {
    return nums[0];
}

int heap_extract_max(int nums[], int heap_size) {
    int max;
    max = nums[0];
    nums[0] = nums[heap_size-1];
    heap_size--;
    max_heapify(nums, heap_size, 0);
    return max;
}

void heap_increse_key(int nums[], int i, int key) {
    if (key < nums[i]) {
        // TODO: error
    }
    nums[i] = key;
    while (i > 0 && nums[(i-1)/2] < nums[i]) {
        int tmp = nums[i];
        nums[i] = nums[(i-1)/2];
        nums[(i-1/2)] = tmp;
        i = (i-1)/2;
    }
}

void max_heap_insert(int nums[], int *heap_size, int key) {
    (*heap_size)++;
    nums[*heap_size] = INT_MIN;
    heap_increse_key(nums, *heap_size-1, key);
}
