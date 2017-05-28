/**
 * optimal_binary_search_tree.c
 * 最优二叉搜索树
 */

#include "optimal_binary_search_tree.h"
#include "../utils.h"
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdio.h>

void init_obst_slt(obst_slt_t *slt, int n) {
    slt->n = n;
    slt->e = malloc((n+2)*sizeof(double*));
    slt->r = malloc((n+2)*sizeof(int*));
    for (int i = 1; i < n+2; i++) {
        slt->e[i] = malloc((n+1)*sizeof(double));
        slt->r[i] = malloc((n+1)*sizeof(int));
    }
}

void free_obst_slt(obst_slt_t *slt) {
    int n = slt->n;
    for (int i= 1; i < n+2; i++) {
        free(slt->e[i]);
        free(slt->r[i]);
    }
    free(slt->e);
    free(slt->r);
}

obst_slt_t optimal_bst(double p[], double q[], int n) {
    obst_slt_t slt;
    init_obst_slt(&slt, n);
    double **e = slt.e;
    int **root = slt.r;
    double w[n+2][n+1];
    for (int i = 1; i < n+2; i++) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i+l-1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                double cur = e[i][r-1] + e[r+1][j] + w[i][j];
                if (cur < e[i][j]) {
                    e[i][j] = cur;
                    root[i][j] = r;
                }
            }
        }
    }
    printf("%lf\n", e[1][n]);
    return slt;
}

void print_obst(double p[], double q[], int i, int j) {
    
}
