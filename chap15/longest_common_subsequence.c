/**
 * longest_common_subsequence.c
 * 最长公共子序列问题
 */

#include "longest_common_subsequence.h"
#include "../utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void init_lcs_slt(lcs_slt_t *slt, int m, int n) {
    slt->m = m;
    slt->n = n;
    slt->c = malloc((m+1)*sizeof(int*));
    slt->b = malloc((m+1)*sizeof(lcs_slt_dirc_t*));
    for (int i = 0; i <= slt->m; i++) {
        slt->c[i] = malloc((n+1)*sizeof(int));
        slt->b[i] = malloc((n+1)*sizeof(lcs_slt_dirc_t));
    }
    for (int i = 0; i <= m; i++) {
        slt->c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        slt->c[0][j] = 0;
    }
}

void free_lcs_slt(lcs_slt_t *slt) {
    for(int i = 0; i <= slt->m; i++) {
        free(slt->c[i]);
        free(slt->b[i]);
    }
    free(slt->c);
    free(slt->b);
}

lcs_slt_t lcs_length(const char *strx, const char *stry) {
    int m = strlen(strx);
    int n = strlen(stry);
    lcs_slt_t slt = {NULL, NULL, 0, 0};
    init_lcs_slt(&slt, m, n);
    int **c = slt.c;
    lcs_slt_dirc_t **b = slt.b;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (strx[i-1] == stry[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = UP_LEFT;
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = UP;
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = LEFT;
            }
        }
    }
    return slt;
}

void get_lcs_aux(const char *strx, int i, int j, lcs_slt_dirc_t **b, char *buf, int *idx);

void get_lcs(const char *strx, const char *stry, int i, int j, char *buf) {
    lcs_slt_t slt = lcs_length(strx, stry);
    lcs_slt_dirc_t **b = slt.b;
    int idx = 0;
    get_lcs_aux(strx, i, j, b, buf, &idx);
    buf[idx] = '\0';
    for (int i = 0; i <= (idx-1)/2; i++) {
        char tmp = buf[i];
        buf[i] = buf[idx-i-1];
        buf[idx-i-1] = tmp; 
    }
    free_lcs_slt(&slt);
}

void get_lcs_aux(const char *strx, int i, int j, lcs_slt_dirc_t **b, char *buf, int *idx) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == UP_LEFT) {
        buf[*idx] = strx[i-1];
        (*idx)++;
        get_lcs_aux(strx, i-1, j-1, b, buf, idx);
        printf("%c", strx[i-1]);
    } else if (b[i][j] == UP) {
        get_lcs_aux(strx, i-1, j, b, buf, idx);
    } else {
        get_lcs_aux(strx, i, j-1, b, buf, idx);
    }
}
