/**
 * utils.c
 * 工具函数
 */
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void print_array2(int **nums, int rows, int cols) {
    printf("[\n");
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
            if (j < cols-1) {
                printf("%d, ", nums[i][j]);
            } else {
                printf("%d", nums[i][j]);
            }
            if (j != 0 && j%10 == 0) printf("\n");
        }
        printf("]\n");
    }
    printf("]\n");
}

void swap(int nums[], int a, int b) {
    if (a == b) return;
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

int maxnum(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int minnum(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}


int get_ith_dgt(int num, int i) {
    return num % (int)pow(10, i+1) / (int)pow(10, i); 
}

int get_dgt_cnt(int num) {
    int i = 1;
    while (num > pow(10, i)-1) {
        i++;
    }
    return i;
}

void shuffle(int nums[], int len) {
    // 最后一个位置自动确定了
    for (int i = len-1; i > 0; i--) {
        swap(nums, i, rand()%(i+1));
    }   
}

