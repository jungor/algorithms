/**
 * matrix_chain_multiplication.c
 * 矩阵链乘法问题
 */

#include "matrix_chain_multiplication.h"
#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void free_mcm_slt(mcm_slt_t slt) {
    for (int i = 0; i < slt.len; i++) {
        free(slt.m[i]);
        free(slt.s[i]);
    }
    free(slt.m);
    free(slt.s);
}

mcm_slt_t matrix_chain_order(int p[], int n) {
    // int len = n+1;
    // mcm_slt_t slt;
    // slt.s = malloc(len*sizeof(int*));
    // slt.m = malloc(len*sizeof(int*));
    // for (int i = 0; i < len; i++) {
    //     slt.s[i] = malloc(len*sizeof(int));
    //     slt.m[i] = malloc(len*sizeof(int));
    // }
    // slt.len = n+1;
    // for (int i = 1; i < len; i++) {
    //     slt.m[i][i] = 0;
    // }
    // for (int l = 1; l < len; l++) {
    //     for (int i = 1; i < len-l+1; i++) {
    //         int j = i+l-1;
    //         slt.m[i][j] = INT_MAX;
    //         for (int k =i; k < j; k++) {
    //             int cur = slt.m[i][k] + slt.m[k+1][j] + p[i-1]*p[k]*p[j];
    //             if (cur < slt.m[i][j]) {
    //                 slt.m[i][j] = cur;
    //                 slt.s[i][j] = k;
    //             }
    //         }
    //     }
    // }
    // return slt;
    // 注意matrix_count = n-1;
    mcm_slt_t slt;
    slt.s = malloc(n*sizeof(int*));
    slt.m = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        slt.s[i] = malloc(n*sizeof(int));
        slt.m[i] = malloc(n*sizeof(int));
    }
    slt.len = n;
    for (int i = 1; i < n; i++) {
        slt.m[i][i] = 0;
    }
    for (int j = 2; j < n; j++) {
        for (int i = j-1; i > 0; i--) {
            int min = INT_MAX;
            for (int k = i; k < j; k++) {
                int tmp = slt.m[i][k] + slt.m[k+1][j] + p[i-1]*p[k]*p[j];
                if (tmp < min) {
                    min = tmp;
                }
            }
            slt.m[i][j] = min;
        }
    }
    return slt;
}

void print_optimal_parens_aux(mcm_slt_t slt, int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens_aux(slt, i, slt.s[i][j]);
        print_optimal_parens_aux(slt, slt.s[i][j]+1, j);
        printf(")");
    }
}

void print_optimal_parens(int p[], int n, int i, int j) {
    mcm_slt_t slt = matrix_chain_order(p, n);
    printf("%d\n", slt.m[i][j]);
    print_optimal_parens_aux(slt, i, j);
    printf("\n");
}
