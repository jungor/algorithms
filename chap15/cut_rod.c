/**
 * cut_rod.h
 * 钢条切割问题
 */

#include "cut_rod.h"
#include "../utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int memoized_cut_rod_aux(int price_table[], int n, int max_table[]);

struct cr_slt_s {
    int *max_table;
    int *cut_table;
    int len;
};

typedef struct cr_slt_s cr_slt_t;

void free_cr_slt(cr_slt_t slt);

cr_slt_t extended_bottom_up_cut_rod(int price_table[], int n);
/**
 * 输入价格表和钢条长度，返回最佳切割方案的价格
 * 复杂度 O(2^n)
 */
int cut_rod(int price_table[], int n) {
    if (n == 0) {
        return 0;
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        int p = price_table[i] + cut_rod(price_table, n-i);
        if (p > max) {
            max = p;
        }
    }
    return max;
}

int memoized_cut_rod(int price_table[], int n) {
    int *max_table = malloc((n+1)*sizeof(int));
    max_table[0] = 0;
    for (int i = 0; i <= n; i++) {
        max_table[i] = INT_MIN;
    }
    int max = memoized_cut_rod_aux(price_table, n, max_table);
    free(max_table);
    return max;
}

int memoized_cut_rod_aux(int price_table[], int n, int max_table[]) {
    if (max_table[n] >= 0) {
        return max_table[n];
    }
    int max = INT_MIN;;
    if (n == 0) {
        max = 0;
    }
    for (int i = 1; i <= n; i++) {
        int p = price_table[i] + memoized_cut_rod_aux(price_table, n-i, max_table);
        if (p > max) {
            max = p;
        }
    }
    max_table[n] = max;
    return max;
}

int bottom_up_cut_rod(int price_table[], int n) {
    int *max_table = malloc((n+1)*sizeof(int));
    max_table[0] = 0;
    for (int i = 1; i <= n; i++) {
        int max = INT_MIN;
        for (int j = 1; j <= i; j++) {
            int cur = price_table[j] + max_table[i-j];
            if (cur > max) {
                max = cur;
            }
        }
        max_table[i] = max;
    }
    int result = max_table[n];
    print_array(max_table, n);
    free(max_table);
    return result;
}

void free_cr_slt(cr_slt_t slt) {
    free(slt.max_table);
    free(slt.cut_table);
}


cr_slt_t extended_bottom_up_cut_rod(int price_table[], int n) {
    cr_slt_t slt;
    slt.len = n+1;
    slt.max_table = malloc((n+1)*sizeof(int));
    slt.cut_table= malloc((n+1)*sizeof(int));
    slt.max_table[0] = 0;
    slt.cut_table[0] = 0;
    for (int i = 1; i <= n; i++) {
        int max = INT_MIN;
        for (int j = 1; j <= i; j++) {
            int cur = slt.max_table[j] + slt.max_table[i-j];
            if (cur > max) {
                max = cur;
                slt.cut_table[i] = j;
            }
        }
        slt.max_table[i] = max;
    }
    return slt;
}


void print_cut_rod_solution(int price_table[], int n) {
    cr_slt_t slt = extended_bottom_up_cut_rod(price_table, n);
    printf("%d\n", slt.max_table[n]);
    while (n > 0) {
        printf("%d ", slt.cut_table[n]);
        n -= slt.cut_table[n];
    }
    printf("\n");
    free_cr_slt(slt);
}
