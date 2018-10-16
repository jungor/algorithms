/**
 * 插入排序
 */
#include "insertion_sort.h"
#include "../utils.h"
/**
 * 插入排序
 */
void insertion_sort(int nums[], int len) {
    // 要插入第i个数，从i-i个数开始往前扫描
    // 循环不变式: nums[0]~nums[i-1]是排好序的
    for (int i = 1; i < len; i++) {
        int j = i-1;
        int key = nums[i];
        // 只要被扫描的数大于等于要插入的数就把被扫描的数往后挪一个位置，
        // 然后接着扫描前一个数，知道没有剩余没扫描的数字或者要被扫描的数字小于等于key
        // 循环不变式: nums[0]~nums[j],nums[j+2]~nums[i]升序且，且nums[j+2]~nums[i]都是比key大的
        while (j >= 0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }
        // 扫描结束，根据循环不变式要插入的数的位置就是j+1
        nums[j+1] = key;
    }
}

