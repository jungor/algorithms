/**
 * utils.c
 * 工具函数
 */
#include "utils.h"
#include <stdio.h>
void print_array(int nums[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        if (i < len-1) {
            printf("%d, ", nums[i]);
        } else {
            printf("%d", nums[i]);
        }
        if (i !=0 && i%10 == 0) printf("\n");
    }
    printf("]\n");
}

void swap(int nums[], int a, int b) {
    if (a == b) return;
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
