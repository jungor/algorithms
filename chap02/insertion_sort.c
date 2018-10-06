/**
 * 插入排序
 */
#include "insertion_sort.h"
#include "../utils.h"
void insertion_sort(int nums[], int len) {
    for (int i = 1; i < len; i++) {
        // 要插入第i个数，从i-i个数开始往前扫描
        int j = i-1;
        int key = nums[i];
        // 只要被扫描的数大于等于要插入的数就把被扫描的数往后挪一个位置，
        // 然后接着扫描前一个数
        while (j >= 0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }
        // 扫描结束，要插入的数的最终位置就是最后被扫描的数的后面
        nums[j+1] = key;
    }
}

